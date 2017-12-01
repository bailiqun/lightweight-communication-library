#ifndef _ROS_ros_topology_msgs_Connection_h
#define _ROS_ros_topology_msgs_Connection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_topology_msgs
{

  class Connection : public ros::Msg
  {
    public:
      typedef const char* _destination_type;
      _destination_type destination;
      typedef const char* _topic_type;
      _topic_type topic;
      typedef uint8_t _direction_type;
      _direction_type direction;
      typedef const char* _transport_type;
      _transport_type transport;
      enum { IN = 1 };
      enum { OUT = 2 };
      enum { BOTH = 3 };

    Connection():
      destination(""),
      topic(""),
      direction(0),
      transport("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_destination = strlen(this->destination);
      varToArr(outbuffer + offset, length_destination);
      offset += 4;
      memcpy(outbuffer + offset, this->destination, length_destination);
      offset += length_destination;
      uint32_t length_topic = strlen(this->topic);
      varToArr(outbuffer + offset, length_topic);
      offset += 4;
      memcpy(outbuffer + offset, this->topic, length_topic);
      offset += length_topic;
      *(outbuffer + offset + 0) = (this->direction >> (8 * 0)) & 0xFF;
      offset += sizeof(this->direction);
      uint32_t length_transport = strlen(this->transport);
      varToArr(outbuffer + offset, length_transport);
      offset += 4;
      memcpy(outbuffer + offset, this->transport, length_transport);
      offset += length_transport;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_destination;
      arrToVar(length_destination, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_destination; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_destination-1]=0;
      this->destination = (char *)(inbuffer + offset-1);
      offset += length_destination;
      uint32_t length_topic;
      arrToVar(length_topic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic-1]=0;
      this->topic = (char *)(inbuffer + offset-1);
      offset += length_topic;
      this->direction =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->direction);
      uint32_t length_transport;
      arrToVar(length_transport, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_transport; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_transport-1]=0;
      this->transport = (char *)(inbuffer + offset-1);
      offset += length_transport;
     return offset;
    }

    const char * getType(){ return "ros_topology_msgs/Connection"; };
    const char * getMD5(){ return "bb176af5fc3e9873fcb695c8f523ec43"; };

  };

}
#endif