#ifndef _ROS_ros_topology_msgs_Service_h
#define _ROS_ros_topology_msgs_Service_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_topology_msgs
{

  class Service : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _uri_type;
      _uri_type uri;

    Service():
      name(""),
      uri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_uri = strlen(this->uri);
      varToArr(outbuffer + offset, length_uri);
      offset += 4;
      memcpy(outbuffer + offset, this->uri, length_uri);
      offset += length_uri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_uri;
      arrToVar(length_uri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_uri-1]=0;
      this->uri = (char *)(inbuffer + offset-1);
      offset += length_uri;
     return offset;
    }

    const char * getType(){ return "ros_topology_msgs/Service"; };
    const char * getMD5(){ return "e16bd2ccde8c00db21bfe01cc1739ff2"; };

  };

}
#endif