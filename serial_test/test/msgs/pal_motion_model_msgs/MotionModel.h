#ifndef _ROS_pal_motion_model_msgs_MotionModel_h
#define _ROS_pal_motion_model_msgs_MotionModel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_motion_model_msgs
{

  class MotionModel : public ros::Msg
  {
    public:
      typedef float _heading_mean_type;
      _heading_mean_type heading_mean;
      typedef float _heading_std_dev_type;
      _heading_std_dev_type heading_std_dev;
      typedef float _linear_speed_mean_type;
      _linear_speed_mean_type linear_speed_mean;
      typedef float _linear_speed_std_dev_type;
      _linear_speed_std_dev_type linear_speed_std_dev;
      typedef float _angular_speed_mean_type;
      _angular_speed_mean_type angular_speed_mean;
      typedef float _angular_speed_std_dev_type;
      _angular_speed_std_dev_type angular_speed_std_dev;

    MotionModel():
      heading_mean(0),
      heading_std_dev(0),
      linear_speed_mean(0),
      linear_speed_std_dev(0),
      angular_speed_mean(0),
      angular_speed_std_dev(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_heading_mean;
      u_heading_mean.real = this->heading_mean;
      *(outbuffer + offset + 0) = (u_heading_mean.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heading_mean.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heading_mean.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heading_mean.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->heading_mean);
      union {
        float real;
        uint32_t base;
      } u_heading_std_dev;
      u_heading_std_dev.real = this->heading_std_dev;
      *(outbuffer + offset + 0) = (u_heading_std_dev.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heading_std_dev.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heading_std_dev.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heading_std_dev.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->heading_std_dev);
      union {
        float real;
        uint32_t base;
      } u_linear_speed_mean;
      u_linear_speed_mean.real = this->linear_speed_mean;
      *(outbuffer + offset + 0) = (u_linear_speed_mean.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_linear_speed_mean.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_linear_speed_mean.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_linear_speed_mean.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->linear_speed_mean);
      union {
        float real;
        uint32_t base;
      } u_linear_speed_std_dev;
      u_linear_speed_std_dev.real = this->linear_speed_std_dev;
      *(outbuffer + offset + 0) = (u_linear_speed_std_dev.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_linear_speed_std_dev.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_linear_speed_std_dev.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_linear_speed_std_dev.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->linear_speed_std_dev);
      union {
        float real;
        uint32_t base;
      } u_angular_speed_mean;
      u_angular_speed_mean.real = this->angular_speed_mean;
      *(outbuffer + offset + 0) = (u_angular_speed_mean.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angular_speed_mean.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angular_speed_mean.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angular_speed_mean.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angular_speed_mean);
      union {
        float real;
        uint32_t base;
      } u_angular_speed_std_dev;
      u_angular_speed_std_dev.real = this->angular_speed_std_dev;
      *(outbuffer + offset + 0) = (u_angular_speed_std_dev.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angular_speed_std_dev.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angular_speed_std_dev.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angular_speed_std_dev.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angular_speed_std_dev);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_heading_mean;
      u_heading_mean.base = 0;
      u_heading_mean.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heading_mean.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heading_mean.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heading_mean.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->heading_mean = u_heading_mean.real;
      offset += sizeof(this->heading_mean);
      union {
        float real;
        uint32_t base;
      } u_heading_std_dev;
      u_heading_std_dev.base = 0;
      u_heading_std_dev.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heading_std_dev.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heading_std_dev.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heading_std_dev.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->heading_std_dev = u_heading_std_dev.real;
      offset += sizeof(this->heading_std_dev);
      union {
        float real;
        uint32_t base;
      } u_linear_speed_mean;
      u_linear_speed_mean.base = 0;
      u_linear_speed_mean.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_linear_speed_mean.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_linear_speed_mean.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_linear_speed_mean.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->linear_speed_mean = u_linear_speed_mean.real;
      offset += sizeof(this->linear_speed_mean);
      union {
        float real;
        uint32_t base;
      } u_linear_speed_std_dev;
      u_linear_speed_std_dev.base = 0;
      u_linear_speed_std_dev.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_linear_speed_std_dev.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_linear_speed_std_dev.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_linear_speed_std_dev.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->linear_speed_std_dev = u_linear_speed_std_dev.real;
      offset += sizeof(this->linear_speed_std_dev);
      union {
        float real;
        uint32_t base;
      } u_angular_speed_mean;
      u_angular_speed_mean.base = 0;
      u_angular_speed_mean.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angular_speed_mean.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angular_speed_mean.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angular_speed_mean.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angular_speed_mean = u_angular_speed_mean.real;
      offset += sizeof(this->angular_speed_mean);
      union {
        float real;
        uint32_t base;
      } u_angular_speed_std_dev;
      u_angular_speed_std_dev.base = 0;
      u_angular_speed_std_dev.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angular_speed_std_dev.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angular_speed_std_dev.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angular_speed_std_dev.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angular_speed_std_dev = u_angular_speed_std_dev.real;
      offset += sizeof(this->angular_speed_std_dev);
     return offset;
    }

    const char * getType(){ return "pal_motion_model_msgs/MotionModel"; };
    const char * getMD5(){ return "fe7c341575e9287349aa5851bafdbb40"; };

  };

}
#endif