#ifndef _ROS_pal_vision_msgs_FollowMeResponse_h
#define _ROS_pal_vision_msgs_FollowMeResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pal_vision_msgs
{

  class FollowMeResponse : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _targetDetected_type;
      _targetDetected_type targetDetected;

    FollowMeResponse():
      header(),
      targetDetected(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_targetDetected;
      u_targetDetected.real = this->targetDetected;
      *(outbuffer + offset + 0) = (u_targetDetected.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->targetDetected);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_targetDetected;
      u_targetDetected.base = 0;
      u_targetDetected.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->targetDetected = u_targetDetected.real;
      offset += sizeof(this->targetDetected);
     return offset;
    }

    const char * getType(){ return "pal_vision_msgs/FollowMeResponse"; };
    const char * getMD5(){ return "36315720880eb3a5b4a4ddf6ffd48eec"; };

  };

}
#endif