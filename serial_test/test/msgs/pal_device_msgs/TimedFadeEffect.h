#ifndef _ROS_SERVICE_TimedFadeEffect_h
#define _ROS_SERVICE_TimedFadeEffect_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_device_msgs/LedGroup.h"
#include "ros/duration.h"
#include "std_msgs/ColorRGBA.h"

namespace pal_device_msgs
{

static const char TIMEDFADEEFFECT[] = "pal_device_msgs/TimedFadeEffect";

  class TimedFadeEffectRequest : public ros::Msg
  {
    public:
      typedef pal_device_msgs::LedGroup _leds_type;
      _leds_type leds;
      typedef std_msgs::ColorRGBA _firstColor_type;
      _firstColor_type firstColor;
      typedef std_msgs::ColorRGBA _secondColor_type;
      _secondColor_type secondColor;
      typedef ros::Duration _colorChangeDuration_type;
      _colorChangeDuration_type colorChangeDuration;
      typedef bool _reverseFade_type;
      _reverseFade_type reverseFade;
      typedef ros::Duration _effectDuration_type;
      _effectDuration_type effectDuration;
      typedef uint8_t _priority_type;
      _priority_type priority;

    TimedFadeEffectRequest():
      leds(),
      firstColor(),
      secondColor(),
      colorChangeDuration(),
      reverseFade(0),
      effectDuration(),
      priority(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->leds.serialize(outbuffer + offset);
      offset += this->firstColor.serialize(outbuffer + offset);
      offset += this->secondColor.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->colorChangeDuration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->colorChangeDuration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->colorChangeDuration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->colorChangeDuration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->colorChangeDuration.sec);
      *(outbuffer + offset + 0) = (this->colorChangeDuration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->colorChangeDuration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->colorChangeDuration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->colorChangeDuration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->colorChangeDuration.nsec);
      union {
        bool real;
        uint8_t base;
      } u_reverseFade;
      u_reverseFade.real = this->reverseFade;
      *(outbuffer + offset + 0) = (u_reverseFade.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reverseFade);
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
      offset += this->firstColor.deserialize(inbuffer + offset);
      offset += this->secondColor.deserialize(inbuffer + offset);
      this->colorChangeDuration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->colorChangeDuration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->colorChangeDuration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->colorChangeDuration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->colorChangeDuration.sec);
      this->colorChangeDuration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->colorChangeDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->colorChangeDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->colorChangeDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->colorChangeDuration.nsec);
      union {
        bool real;
        uint8_t base;
      } u_reverseFade;
      u_reverseFade.base = 0;
      u_reverseFade.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reverseFade = u_reverseFade.real;
      offset += sizeof(this->reverseFade);
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

    const char * getType(){ return TIMEDFADEEFFECT; };
    const char * getMD5(){ return "4b26fa459195deaf5bbcf5309bfe3b62"; };

  };

  class TimedFadeEffectResponse : public ros::Msg
  {
    public:
      typedef uint32_t _effectId_type;
      _effectId_type effectId;

    TimedFadeEffectResponse():
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

    const char * getType(){ return TIMEDFADEEFFECT; };
    const char * getMD5(){ return "f6602e24c29b84632fa113b15b20645d"; };

  };

  class TimedFadeEffect {
    public:
    typedef TimedFadeEffectRequest Request;
    typedef TimedFadeEffectResponse Response;
  };

}
#endif
