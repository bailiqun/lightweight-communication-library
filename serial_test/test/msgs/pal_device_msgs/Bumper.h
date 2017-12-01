#ifndef _ROS_pal_device_msgs_Bumper_h
#define _ROS_pal_device_msgs_Bumper_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pal_device_msgs
{

  class Bumper : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _is_pressed_type;
      _is_pressed_type is_pressed;

    Bumper():
      header(),
      is_pressed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_pressed;
      u_is_pressed.real = this->is_pressed;
      *(outbuffer + offset + 0) = (u_is_pressed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_pressed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_pressed;
      u_is_pressed.base = 0;
      u_is_pressed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_pressed = u_is_pressed.real;
      offset += sizeof(this->is_pressed);
     return offset;
    }

    const char * getType(){ return "pal_device_msgs/Bumper"; };
    const char * getMD5(){ return "7feed261fab09e5d0ce6318f9f9ed4b9"; };

  };

}
#endif