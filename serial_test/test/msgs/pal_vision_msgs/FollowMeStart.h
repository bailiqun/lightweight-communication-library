#ifndef _ROS_SERVICE_FollowMeStart_h
#define _ROS_SERVICE_FollowMeStart_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_vision_msgs
{

static const char FOLLOWMESTART[] = "pal_vision_msgs/FollowMeStart";

  class FollowMeStartRequest : public ros::Msg
  {
    public:
      typedef float _maxSecondsTargetLost_type;
      _maxSecondsTargetLost_type maxSecondsTargetLost;

    FollowMeStartRequest():
      maxSecondsTargetLost(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_maxSecondsTargetLost;
      u_maxSecondsTargetLost.real = this->maxSecondsTargetLost;
      *(outbuffer + offset + 0) = (u_maxSecondsTargetLost.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_maxSecondsTargetLost.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_maxSecondsTargetLost.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_maxSecondsTargetLost.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->maxSecondsTargetLost);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_maxSecondsTargetLost;
      u_maxSecondsTargetLost.base = 0;
      u_maxSecondsTargetLost.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_maxSecondsTargetLost.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_maxSecondsTargetLost.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_maxSecondsTargetLost.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->maxSecondsTargetLost = u_maxSecondsTargetLost.real;
      offset += sizeof(this->maxSecondsTargetLost);
     return offset;
    }

    const char * getType(){ return FOLLOWMESTART; };
    const char * getMD5(){ return "87d3dd79b1c6acbd29fa88c4d5b58715"; };

  };

  class FollowMeStartResponse : public ros::Msg
  {
    public:

    FollowMeStartResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return FOLLOWMESTART; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class FollowMeStart {
    public:
    typedef FollowMeStartRequest Request;
    typedef FollowMeStartResponse Response;
  };

}
#endif
