#ifndef _ROS_pal_navigation_msgs_PolarReading_h
#define _ROS_pal_navigation_msgs_PolarReading_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

  class PolarReading : public ros::Msg
  {
    public:
      typedef float _angle_type;
      _angle_type angle;
      typedef float _distance_type;
      _distance_type distance;

    PolarReading():
      angle(0),
      distance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.real = this->angle;
      *(outbuffer + offset + 0) = (u_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.base = 0;
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle = u_angle.real;
      offset += sizeof(this->angle);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/PolarReading"; };
    const char * getMD5(){ return "817840b8f4d2300f89b98e0187dc919a"; };

  };

}
#endif