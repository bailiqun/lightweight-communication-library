#ifndef _ROS_pal_web_msgs_WebGoTo_h
#define _ROS_pal_web_msgs_WebGoTo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_web_msgs
{

  class WebGoTo : public ros::Msg
  {
    public:
      typedef uint8_t _type_type;
      _type_type type;
      typedef const char* _value_type;
      _value_type value;
      enum { IMAGE =  0 };
      enum { VIDEO =  1 };
      enum { URI =  2 };

    WebGoTo():
      type(0),
      value("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t length_value = strlen(this->value);
      varToArr(outbuffer + offset, length_value);
      offset += 4;
      memcpy(outbuffer + offset, this->value, length_value);
      offset += length_value;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      uint32_t length_value;
      arrToVar(length_value, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value-1]=0;
      this->value = (char *)(inbuffer + offset-1);
      offset += length_value;
     return offset;
    }

    const char * getType(){ return "pal_web_msgs/WebGoTo"; };
    const char * getMD5(){ return "715dcaa6e10d734c32f0941dc6231986"; };

  };

}
#endif