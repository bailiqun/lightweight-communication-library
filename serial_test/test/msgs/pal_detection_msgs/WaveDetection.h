#ifndef _ROS_pal_detection_msgs_WaveDetection_h
#define _ROS_pal_detection_msgs_WaveDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pal_detection_msgs
{

  class WaveDetection : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _wave_type;
      _wave_type wave;
      typedef int8_t _u_type;
      _u_type u;
      typedef int8_t _v_type;
      _v_type v;

    WaveDetection():
      header(),
      wave(0),
      u(0),
      v(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_wave;
      u_wave.real = this->wave;
      *(outbuffer + offset + 0) = (u_wave.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wave);
      union {
        int8_t real;
        uint8_t base;
      } u_u;
      u_u.real = this->u;
      *(outbuffer + offset + 0) = (u_u.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->u);
      union {
        int8_t real;
        uint8_t base;
      } u_v;
      u_v.real = this->v;
      *(outbuffer + offset + 0) = (u_v.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->v);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_wave;
      u_wave.base = 0;
      u_wave.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wave = u_wave.real;
      offset += sizeof(this->wave);
      union {
        int8_t real;
        uint8_t base;
      } u_u;
      u_u.base = 0;
      u_u.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->u = u_u.real;
      offset += sizeof(this->u);
      union {
        int8_t real;
        uint8_t base;
      } u_v;
      u_v.base = 0;
      u_v.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->v = u_v.real;
      offset += sizeof(this->v);
     return offset;
    }

    const char * getType(){ return "pal_detection_msgs/WaveDetection"; };
    const char * getMD5(){ return "aa420a347ae2972ab2629dc50442fbb8"; };

  };

}
#endif