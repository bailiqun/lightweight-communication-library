#ifndef _ROS_pal_interaction_msgs_EnablingSoundLocalisation_h
#define _ROS_pal_interaction_msgs_EnablingSoundLocalisation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class EnablingSoundLocalisation : public ros::Msg
  {
    public:
      typedef bool _enable_type;
      _enable_type enable;

    EnablingSoundLocalisation():
      enable(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.real = this->enable;
      *(outbuffer + offset + 0) = (u_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.base = 0;
      u_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable = u_enable.real;
      offset += sizeof(this->enable);
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/EnablingSoundLocalisation"; };
    const char * getMD5(){ return "8c1211af706069c994c06e00eb59ac9e"; };

  };

}
#endif