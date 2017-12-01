#ifndef _ROS_pal_vision_msgs_HeadPanTilt_h
#define _ROS_pal_vision_msgs_HeadPanTilt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pal_vision_msgs
{

  class HeadPanTilt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _pan_type;
      _pan_type pan;
      typedef float _tilt_type;
      _tilt_type tilt;

    HeadPanTilt():
      header(),
      pan(0),
      tilt(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_pan;
      u_pan.real = this->pan;
      *(outbuffer + offset + 0) = (u_pan.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pan.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pan.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pan.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pan);
      union {
        float real;
        uint32_t base;
      } u_tilt;
      u_tilt.real = this->tilt;
      *(outbuffer + offset + 0) = (u_tilt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tilt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tilt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tilt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tilt);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_pan;
      u_pan.base = 0;
      u_pan.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pan.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pan.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pan.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pan = u_pan.real;
      offset += sizeof(this->pan);
      union {
        float real;
        uint32_t base;
      } u_tilt;
      u_tilt.base = 0;
      u_tilt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tilt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tilt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tilt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tilt = u_tilt.real;
      offset += sizeof(this->tilt);
     return offset;
    }

    const char * getType(){ return "pal_vision_msgs/HeadPanTilt"; };
    const char * getMD5(){ return "3a7f57c9f96db29da139b70516999666"; };

  };

}
#endif