#ifndef _SERIAL_NODE_HANDLE_H_
#define _SERIAL_NODE_HANDLE_H_

#include <stdint.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

#include "msg.h"
#include "time.h"

namespace std_msgs
{

  class Time : public serial::Msg
  {
    public:
      typedef serial::Time _data_type;
      _data_type data;

    Time():
      data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->data.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data.sec);
      *(outbuffer + offset + 0) = (this->data.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->data.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->data.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->data.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->data.sec);
      this->data.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->data.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->data.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->data.nsec);
     return offset;
    }
    const char * getType(){ return "std_msgs/Time"; }
    const char * getMD5(){ return "cd7166c74c552c311fbcc2fe5a7bc289"; }
  };
}

namespace serial {

    class NodeHandleBase
    {
    public:
        virtual int  publish(int id, const Msg* msg)=0;
        virtual int  spinOnce()=0;
        virtual bool connected()=0;
    };
}


#include "subscriber.h"
#include "publisher.h"


namespace serial {

  const uint8_t SYNC_SECONDS  = 5;
  const uint8_t MODE_FIRST_FF = 0;

  const uint8_t MODE_PROTOCOL_VER  = 1;
  const uint8_t PROTOCOL_VER       = MODE_PROTOCOL_VER;

  const uint8_t SERIAL_MSG_TIMEOUT  = 20;   // 20 milliseconds to recieve all of message data

  /* Node Handle */
  template<class Hardware,
           int INPUT_SIZE=512,
           int OUTPUT_SIZE=512>
  class NodeHandle : public NodeHandleBase
  {
    protected:
    Hardware hardware;

    /* time used for syncing */
    uint32_t rt_time;

    /* used for computing current time */
    uint32_t sec_offset, nsec_offset;

    uint8_t message_in[INPUT_SIZE];
    uint8_t message_out[OUTPUT_SIZE];

    std::vector<Publisher*>   publishers;
    std::vector<Subscriber_*> subscribers;

   /*
    * Setup Functions
    */
public:
    NodeHandle() : configured_(false)
    {
        publishers.clear();
        subscribers.clear();
        for(unsigned int i=0; i< INPUT_SIZE; i++)
            message_in[i] = 0;
        for(unsigned int i=0; i< OUTPUT_SIZE; i++)
            message_out[i] = 0;
    }

    ~NodeHandle()
    {
        for(int i=0;i<subscribers.size();i++)
        {
            delete subscribers[i];
        }
        for(int i=0;i<publishers.size();i++)
        {
            delete publishers[i];
        }
    }

    Hardware* getHardware(){
    return &hardware;
    }

    /* Start serial, initialize buffers */
    void initNode()
    {
        hardware.init();
    }

    /* Start a named port, which may be network server IP, initialize buffers */
    void initNode(char *portName)
    {
        hardware.init(portName);
    }

protected:
      //State machine variables for spinOnce
      bool configured_;
      /* used for syncing the time */
      uint32_t last_sync_time;
      uint32_t last_sync_receive_time;
      uint32_t last_msg_timeout_time;

public:
  /*
   *  This function goes in your loop() function, it handles
   *  serial input and callbacks for subscribers.
   */
    virtual int spinOnce()
    {

        /* restart if timed out */
        uint32_t c_time = hardware.time();
        if( (c_time - last_sync_receive_time) > (SYNC_SECONDS*2200) ){
        configured_ = false;
        }

        std::cout<<"size="<<subscribers.size()<<std::endl;
        while(true)
        {
            int data = hardware.read();
            for(int i=0;i<subscribers.size();i++)
            {
                unsigned char a[10]={"123123"};
                subscribers[i]->callback(a);
            }
            std::cout<<"new"<<std::endl;
            sleep(1);
        }

        /* occasionally sync time */
        if( configured_ && ((c_time-last_sync_time) > (SYNC_SECONDS*500) )){
        requestSyncTime();
        last_sync_time = c_time;
        }
        return 0;
    }

    /* Are we connected to the PC? */
    virtual bool connected() {
        return configured_;
    }

    /********************************************************************
    * Time functions
    */
    void requestSyncTime()
    {
        std_msgs::Time t;
        publish(ID_TIME, &t);
        rt_time = hardware.time();
    }

    void syncTime(uint8_t * data)
    {
        std_msgs::Time t;
        uint32_t offset = hardware.time() - rt_time;

        t.deserialize(data);
        t.data.sec += offset/1000;
        t.data.nsec += (offset%1000)*1000000UL;

        setNow(t.data);
        last_sync_receive_time = hardware.time();
    }

    Time now()
    {
        uint32_t ms = hardware.time();
        Time current_time;
        current_time.sec = ms/1000 + sec_offset;
        current_time.nsec = (ms%1000)*1000000UL + nsec_offset;
        normalizeSecNSec(current_time.sec, current_time.nsec);
        return current_time;
    }

    void setNow( Time & new_now )
    {
        uint32_t ms = hardware.time();
        sec_offset = new_now.sec - ms/1000 - 1;
        nsec_offset = new_now.nsec - (ms%1000)*1000000UL + 1000000000UL;
        normalizeSecNSec(sec_offset, nsec_offset);
    }

    /********************************************************************
     * Topic Management
     *
     */
      /* Register a new publisher */
      bool advertise(Publisher & p)
      {
        return false;
      }

      /* Register a new subscriber */
      template <class MsgT>
      void subscribe(int id,
                     char* topic,
                     void(*callback)(const MsgT&))
      {
          for(int i=0; i<subscribers.size(); i++)
          {
            if(subscribers[i]->id == id)
            {
                return;
            }
          }

          serial::Subscriber<MsgT> *sub=
                  new serial::Subscriber<MsgT>(topic, callback);
          sub->id = id;
          subscribers.push_back(static_cast<Subscriber_*>(sub));
      }

      /* Register a new subscriber in class*/
      template <class MsgT, class ObjT>
      void subscribe(int id,
                     char* topic,
                     void (ObjT::*callback)(const MsgT&),
                     ObjT* obj)
      {
          for(int i=0; i<subscribers.size(); i++)
          {
            if(subscribers[i]->id == id)
            {
                return;
            }
          }
          serial::Subscriber<MsgT,ObjT> *sub=
                  new serial::Subscriber<MsgT,ObjT>(topic, callback, obj);
          sub->id = id;
          subscribers.push_back(static_cast<Subscriber_*>(sub));
      }

      virtual int publish(int id, const Msg * msg)
      {
        if(id >= 100 && !configured_)
          return 0;

        /* serialize message */
        int l = msg->serialize(message_out+7);

        /* setup the header */
        message_out[0] = 0xA5;
        message_out[1] = 0x5A;
        message_out[2] = (uint8_t) ((uint16_t)l&255);
        message_out[3] = (uint8_t) ((uint16_t)l>>8);
        message_out[4] = 255 - ((message_out[2] + message_out[3])%256);
        message_out[5] = (uint8_t) ((int16_t)id&255);
        message_out[6] = (uint8_t) ((int16_t)id>>8);

        /* calculate checksum */
        int chk = 0;
        for(int i =5; i<l+7; i++)
          chk += message_out[i];
        l += 7;
        message_out[l++] = 255 - (chk%256);

        if( l <= OUTPUT_SIZE ){
          hardware.write(message_out, l);
          return l;
        }else{
          //log("Message from device dropped: message larger than buffer.");
          return -1;
        }
      }


/********************************************************************
 * Parameters
 */
};
}

#endif