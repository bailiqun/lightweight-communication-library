#ifndef _ROS_pal_interaction_msgs_WebGuiEvent_h
#define _ROS_pal_interaction_msgs_WebGuiEvent_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class WebGuiEvent : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _arg_type;
      _arg_type arg;

    WebGuiEvent():
      name(""),
      arg("")
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
      uint32_t length_arg = strlen(this->arg);
      varToArr(outbuffer + offset, length_arg);
      offset += 4;
      memcpy(outbuffer + offset, this->arg, length_arg);
      offset += length_arg;
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
      uint32_t length_arg;
      arrToVar(length_arg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_arg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_arg-1]=0;
      this->arg = (char *)(inbuffer + offset-1);
      offset += length_arg;
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/WebGuiEvent"; };
    const char * getMD5(){ return "bd4a90be174b9e14b06cf397c1359fb1"; };

  };

}
#endif