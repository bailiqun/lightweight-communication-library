#ifndef _ROS_SERVICE_DisableEmergency_h
#define _ROS_SERVICE_DisableEmergency_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

static const char DISABLEEMERGENCY[] = "pal_navigation_msgs/DisableEmergency";

  class DisableEmergencyRequest : public ros::Msg
  {
    public:
      typedef float _second_type;
      _second_type second;
      typedef bool _useLEDs_type;
      _useLEDs_type useLEDs;

    DisableEmergencyRequest():
      second(0),
      useLEDs(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->second);
      union {
        bool real;
        uint8_t base;
      } u_useLEDs;
      u_useLEDs.real = this->useLEDs;
      *(outbuffer + offset + 0) = (u_useLEDs.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->useLEDs);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->second));
      union {
        bool real;
        uint8_t base;
      } u_useLEDs;
      u_useLEDs.base = 0;
      u_useLEDs.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->useLEDs = u_useLEDs.real;
      offset += sizeof(this->useLEDs);
     return offset;
    }

    const char * getType(){ return DISABLEEMERGENCY; };
    const char * getMD5(){ return "fbef0837e8a0d26d59ce6c877c970c68"; };

  };

  class DisableEmergencyResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    DisableEmergencyResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return DISABLEEMERGENCY; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class DisableEmergency {
    public:
    typedef DisableEmergencyRequest Request;
    typedef DisableEmergencyResponse Response;
  };

}
#endif
