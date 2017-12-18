#ifndef _SERIAL_NODE_HANDLE_H_
#define _SERIAL_NODE_HANDLE_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#include <iostream>
#include <numeric>
#include <vector>
#include <boost/thread.hpp>

#include "msg.h"
#include "time.h"

namespace std_msgs
{

  class Time : public serial::Msg
  {
    public:
      typedef serial::Time _data_type;
      _data_type data;

    Time(): data()
    {

    }

    virtual int serialize(uint8_t* outbuffer) const
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

    virtual int deserialize(uint8_t* inbuffer)
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
    int   getByte() { return 4; }
    const char* getType() { return "std_msgs/Time"; }
    const char* getMD5()  { return "cd7166c74c552c311fbcc2fe5a7bc289"; }
  };
}

namespace serial {

    class NodeHandleBase
    {
    public:
        virtual int  publish(int id, Msg* msg) = 0;
        virtual bool connected() = 0;
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
  template<class Hardware>
  class NodeHandle : public NodeHandleBase
  {
    protected:
    Hardware hardware;

    /* time used for syncing */
    uint32_t rt_time;

    /* used for computing current time */
    uint32_t sec_offset, nsec_offset;

    uint32_t rc_flag;
    uint32_t rw_index;
    std::vector<uint8_t> message_in;
    std::vector<uint8_t> message_out;

    std::vector<Publisher*>   publishers;
    std::vector<Subscriber_*> subscribers;

   /*
    * Setup Functions
    */
public:
    NodeHandle() : configured_(false)
    {
        initNode();
        publishers.clear();
        subscribers.clear();
        message_in.clear();
        message_out.clear();
        boost::function0<void> f0 = boost::bind(&NodeHandle::spin, this);
        thread_ = new boost::thread(f0);
    }

    virtual ~NodeHandle()
    {
        std::cout<<"[Clean Memory]"<<std::endl;
        thread_->interrupt();
        thread_->timed_join(boost::posix_time::seconds(1));
        hardware.close();
        delete thread_;

        for(int i=0;i<subscribers.size();i++)
        {
            delete subscribers[i];
        }

        for(int i=0;i<publishers.size();i++)
        {
            delete publishers[i];
        }
        std::cout<<"[Clean Done]"<<std::endl;
    }

    Hardware* getHardware()
    {
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
      bool configured_;
      /* used for syncing the time */
      uint32_t last_sync_time;
      uint32_t last_sync_receive_time;
      uint32_t last_msg_timeout_time;

public:
    boost::thread* thread_;
    boost::thread::id thread_id_;

    bool sum_check(void)
    {
        uint32_t size = message_in.size();
        uint8_t checksum = 0;
        try
        {
            checksum = (uint8_t)std::accumulate(message_in.begin(), message_in.end()-1, 0)%256;
            if((checksum % 256)== message_in[size-1])
            {
                return true;
            }
        }
        catch(std::exception& e)
        {
            return false;
        }
        return false;
    }

    virtual int protocal_explain()
    {
        int data = hardware.read();
        if(data == 0xa5)
        {
          rc_flag |= 0x80;
          message_in.push_back(data);
        }
        else if(data == 0x5a)
        {
          if(rc_flag & 0x80)
          {
              message_in.clear();
              rc_flag &= ~0x40;
          }
          else
          {
              message_in.push_back(data);
          }
          rc_flag &= ~0x80;
        }
        else
        {
          message_in.push_back(data);
          rc_flag &= ~0x80;
          uint16_t size = message_in[0]<<8 | message_in[1];
          if(size == message_in.size())
          {
              rc_flag |= 0x40;
              uint16_t id = message_in[2]<<8 | message_in[3];
              if(sum_check())
              {
                  for(int i=0;i<subscribers.size();i++)
                  {
                      if(subscribers[i]->id == id)
                      {
                          long long time = 0;
                          gettimeofday(&subscribers[i]->end,NULL);
                          subscribers[i]->callback(message_in.data()+7);
                          time = 1000000 * (subscribers[i]->end.tv_sec-subscribers[i]->start.tv_sec) +
                                            subscribers[i]->end.tv_usec-subscribers[i]->start.tv_usec;
                          subscribers[i]->feq = 1000000.0 / time;
                          gettimeofday(&subscribers[i]->start,NULL);
                      }
                  }
              }
              message_in.clear();
          }
        }
    }
    /*
    *  This function goes in your loop() function, it handles
    *  serial input and callbacks for subscribers.
    */
    int spin()
    {
        while(1)
        {
            protocal_explain();
        }
    }

    virtual int spinOnce()
    {

        /* restart if timed out */
        uint32_t c_time = hardware.time();
        if( (c_time - last_sync_receive_time) > (SYNC_SECONDS*2200) ){
        configured_ = false;
        }

        while(1);

        /* occasionally sync time */
        if( configured_ && ((c_time-last_sync_time) > (SYNC_SECONDS*500) )){
        requestSyncTime();
        last_sync_time = c_time;
        }
        return 0;
    }

    /* Are we connected to the PC */
    virtual bool connected()
    {
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
    */

    /*Register a new publisher */
    bool advertise(Publisher & p)
    {
        return false;
    }

    /* Register a new subscriber */
    template <class MsgT>
    void subscribe(int id,
                 char* topic,
                 void(*callback)(const char* topic, const MsgT&))
    {
      for(int i=0; i<subscribers.size(); i++)
      {
          if(subscribers[i]->id == id &&
             subscribers[i]->topic == topic)
          {
              std::cerr<<"[Subscribe] topic has been subscribe"<<std::endl;
              return;
          }
      }

      serial::Subscriber<MsgT> *sub=
              new serial::Subscriber<MsgT>(topic, callback);
      sub->id = id;
      sub->topic = topic;
      subscribers.push_back(static_cast<Subscriber_*>(sub));
    }

    /* Register a new subscriber in class*/
    template <class MsgT, class ObjT>
    void subscribe(int id, char* topic,
                   void (ObjT::*callback)(const char* topic, const MsgT&),
                   ObjT* obj)
    {
        for(int i=0; i<subscribers.size(); i++)
        {
            if(subscribers[i]->id == id &&
               subscribers[i]->topic == topic)
            {
                std::cerr<<"[Subscribe] topic has been subscribe"<<std::endl;
                return;
            }
        }

        serial::Subscriber<MsgT,ObjT> *sub=
        new serial::Subscriber<MsgT,ObjT>(topic, callback, obj);
        sub->id = id;
        sub->topic = topic;
        subscribers.push_back(static_cast<Subscriber_*>(sub));
    }

    virtual int publish(int id, Msg* msg)
    {
        message_out.clear();
        const uint16_t size = msg->getByte();
        uint8_t temp[size];
        /* setup the header */
        message_out.push_back(0xa5);
        message_out.push_back(0x5A);
        /* setup the size */
        message_out.push_back((uint8_t)((size+8) >> 8));
        message_out.push_back((uint8_t) (size+8));
        /* setup the ID  */
        message_out.push_back((uint8_t)(id >> 8));
        message_out.push_back((uint8_t)(id));
        /* setup the via  */
        message_out.push_back(0);
        /* setup the reserve  */
        message_out.push_back(0);
        message_out.push_back(0);
        /* serialize message */
        msg->serialize(temp);
        for(int i=0; i<size; i++)
        {
            message_out.push_back(temp[i]);
        }
        uint8_t checksum = std::accumulate(message_out.begin() + 2, message_out.end(), 0) % 256;
        message_out.push_back((uint8_t)(checksum));
        hardware.write(message_out.data(), message_out.size());
    }

/********************************************************************
 * Parameters
 */
};
}

#endif
