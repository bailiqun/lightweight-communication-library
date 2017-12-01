#ifndef _ROS_SERVICE_TimedBlinkEffect_h
#define _ROS_SERVICE_TimedBlinkEffect_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_device_msgs/LedGroup.h"
#include "ros/duration.h"
#include "std_msgs/ColorRGBA.h"

namespace pal_device_msgs
{

static const char TIMEDBLINKEFFECT[] = "pal_device_msgs/TimedBlinkEffect";

  class TimedBlinkEffectRequest : public ros::Msg
  {
    public:
      typedef pal_device_msgs::LedGroup _leds_type;
      _leds_type leds;
      typedef std_msgs::ColorRGBA _firstColor_type;
      _firstColor_type firstColor;
      typedef std_msgs::ColorRGBA _secondColor_type;
      _secondColor_type secondColor;
      typedef ros::Duration _firstColorDuration_type;
      _firstColorDuration_type firstColorDuration;
      typedef ros::Duration _secondColorDuration_type;
      _secondColorDuration_type secondColorDuration;
      typedef ros::Duration _effectDuration_type;
      _effectDuration_type effectDuration;
      typedef uint8_t _priority_type;
      _priority_type priority;

    TimedBlinkEffectRequest():
      leds(),
      firstColor(),
      secondColor(),
      firstColorDuration(),
      secondColorDuration(),
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
      *(outbuffer + offset + 0) = (this->firstColorDuration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->firstColorDuration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->firstColorDuration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->firstColorDuration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->firstColorDuration.sec);
      *(outbuffer + offset + 0) = (this->firstColorDuration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->firstColorDuration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->firstColorDuration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->firstColorDuration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->firstColorDuration.nsec);
      *(outbuffer + offset + 0) = (this->secondColorDuration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->secondColorDuration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->secondColorDuration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->secondColorDuration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->secondColorDuration.sec);
      *(outbuffer + offset + 0) = (this->secondColorDuration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->secondColorDuration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->secondColorDuration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->secondColorDuration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->secondColorDuration.nsec);
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
      this->firstColorDuration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->firstColorDuration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->firstColorDuration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->firstColorDuration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->firstColorDuration.sec);
      this->firstColorDuration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->firstColorDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->firstColorDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->firstColorDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->firstColorDuration.nsec);
      this->secondColorDuration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->secondColorDuration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->secondColorDuration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->secondColorDuration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->secondColorDuration.sec);
      this->secondColorDuration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->secondColorDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->secondColorDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->secondColorDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->secondColorDuration.nsec);
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

    const char * getType(){ return TIMEDBLINKEFFECT; };
    const char * getMD5(){ return "c7345ff92e3c60b0471328ccec5e5dc8"; };

  };

  class TimedBlinkEffectResponse : public ros::Msg
  {
    public:
      typedef uint32_t _effectId_type;
      _effectId_type effectId;

    TimedBlinkEffectResponse():
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

    const char * getType(){ return TIMEDBLINKEFFECT; };
    const char * getMD5(){ return "f6602e24c29b84632fa113b15b20645d"; };

  };

  class TimedBlinkEffect {
    public:
    typedef TimedBlinkEffectRequest Request;
    typedef TimedBlinkEffectResponse Response;
  };

}
#endif
