#ifndef _ROS_SERVICE_TimedColourEffect_h
#define _ROS_SERVICE_TimedColourEffect_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_device_msgs/LedGroup.h"
#include "ros/duration.h"
#include "std_msgs/ColorRGBA.h"

namespace pal_device_msgs
{

static const char TIMEDCOLOUREFFECT[] = "pal_device_msgs/TimedColourEffect";

  class TimedColourEffectRequest : public ros::Msg
  {
    public:
      typedef pal_device_msgs::LedGroup _leds_type;
      _leds_type leds;
      typedef std_msgs::ColorRGBA _color_type;
      _color_type color;
      typedef ros::Duration _effectDuration_type;
      _effectDuration_type effectDuration;
      typedef uint8_t _priority_type;
      _priority_type priority;

    TimedColourEffectRequest():
      leds(),
      color(),
      effectDuration(),
      priority(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->leds.serialize(outbuffer + offset);
      offset += this->color.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->effectDuration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->effectDuration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->effectDuration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->effectDuration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effectDuration.sec);
      *(outbuffer + offset + 0) = (this->effectDuration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->effectDuration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->effectDuration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->effectDuration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effectDuration.nsec);
      *(outbuffer + offset + 0) = (this->priority >> (8 * 0)) & 0xFF;
      offset += sizeof(this->priority);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->leds.deserialize(inbuffer + offset);
      offset += this->color.deserialize(inbuffer + offset);
      this->effectDuration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->effectDuration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->effectDuration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->effectDuration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->effectDuration.sec);
      this->effectDuration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->effectDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->effectDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->effectDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->effectDuration.nsec);
      this->priority =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->priority);
     return offset;
    }

    const char * getType(){ return TIMEDCOLOUREFFECT; };
    const char * getMD5(){ return "a7f2577993c3ce4fd146dbd95f4a91d5"; };

  };

  class TimedColourEffectResponse : public ros::Msg
  {
    public:
      typedef uint32_t _effectId_type;
      _effectId_type effectId;

    TimedColourEffectResponse():
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

    const char * getType(){ return TIMEDCOLOUREFFECT; };
    const char * getMD5(){ return "f6602e24c29b84632fa113b15b20645d"; };

  };

  class TimedColourEffect {
    public:
    typedef TimedColourEffectRequest Request;
    typedef TimedColourEffectResponse Response;
  };

}
#endif
