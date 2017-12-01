#ifndef _ROS_pal_vision_msgs_Rectangle_h
#define _ROS_pal_vision_msgs_Rectangle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_vision_msgs
{

  class Rectangle : public ros::Msg
  {
    public:
      typedef int64_t _x_type;
      _x_type x;
      typedef int64_t _y_type;
      _y_type y;
      typedef int64_t _width_type;
      _width_type width;
      typedef int64_t _height_type;
      _height_type height;

    Rectangle():
      x(0),
      y(0),
      width(0),
      height(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x);
      union {
        int64_t real;
        uint64_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y);
      union {
        int64_t real;
        uint64_t base;
      } u_width;
      u_width.real = this->width;
      *(outbuffer + offset + 0) = (u_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_width.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_width.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_width.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_width.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_width.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->width);
      union {
        int64_t real;
        uint64_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_height.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_height.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_height.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_height.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->height);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        int64_t real;
        uint64_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        int64_t real;
        uint64_t base;
      } u_width;
      u_width.base = 0;
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->width = u_width.real;
      offset += sizeof(this->width);
      union {
        int64_t real;
        uint64_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->height = u_height.real;
      offset += sizeof(this->height);
     return offset;
    }

    const char * getType(){ return "pal_vision_msgs/Rectangle"; };
    const char * getMD5(){ return "da3a0b875a11573348524040e5637f14"; };

  };

}
#endif