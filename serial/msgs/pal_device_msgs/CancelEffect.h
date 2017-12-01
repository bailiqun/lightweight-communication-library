#ifndef _ROS_SERVICE_CancelEffect_h
#define _ROS_SERVICE_CancelEffect_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_device_msgs
{

static const char CANCELEFFECT[] = "pal_device_msgs/CancelEffect";

  class CancelEffectRequest : public ros::Msg
  {
    public:
      typedef uint32_t _effectId_type;
      _effectId_type effectId;

    CancelEffectRequest():
      effectId(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->effectId >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->effectId >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->effectId >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->effectId >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effectId);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->effectId =  ((uint32_t) (*(inbuffer + offset)));
      this->effectId |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->effectId |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->effectId |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->effectId);
     return offset;
    }

    const char * getType(){ return CANCELEFFECT; };
    const char * getMD5(){ return "f6602e24c29b84632fa113b15b20645d"; };

  };

  class CancelEffectResponse : public ros::Msg
  {
    public:

    CancelEffectResponse()
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

    const char * getType(){ return CANCELEFFECT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class CancelEffect {
    public:
    typedef CancelEffectRequest Request;
    typedef CancelEffectResponse Response;
  };

}
#endif
