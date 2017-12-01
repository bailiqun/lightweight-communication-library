#ifndef _ROS_pal_common_msgs_DisableGoal_h
#define _ROS_pal_common_msgs_DisableGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_common_msgs
{

  class DisableGoal : public ros::Msg
  {
    public:
      typedef float _duration_type;
      _duration_type duration;

    DisableGoal():
      duration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_duration;
      u_duration.real = this->duration;
      *(outbuffer + offset + 0) = (u_duration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_duration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_duration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_duration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_duration;
      u_duration.base = 0;
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->duration = u_duration.real;
      offset += sizeof(this->duration);
     return offset;
    }

    const char * getType(){ return "pal_common_msgs/DisableGoal"; };
    const char * getMD5(){ return "f17ffa2323e97e44a94d55c2699df849"; };

  };

}
#endif