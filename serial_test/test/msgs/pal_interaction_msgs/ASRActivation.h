#ifndef _ROS_pal_interaction_msgs_ASRActivation_h
#define _ROS_pal_interaction_msgs_ASRActivation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class ASRActivation : public ros::Msg
  {
    public:
      typedef int8_t _action_type;
      _action_type action;
      enum { ACTIVATE =  1 };
      enum { DEACTIVATE =  2 };
      enum { PAUSE =  3 };
      enum { RESUME =  4 };
      enum { CALIBRATE =  5 };

    ASRActivation():
      action(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_action;
      u_action.real = this->action;
      *(outbuffer + offset + 0) = (u_action.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_action;
      u_action.base = 0;
      u_action.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->action = u_action.real;
      offset += sizeof(this->action);
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/ASRActivation"; };
    const char * getMD5(){ return "cbd42ef6448061151159fe3a848b2553"; };

  };

}
#endif