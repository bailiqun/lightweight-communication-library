#ifndef _ROS_SERVICE_SafetyZone_h
#define _ROS_SERVICE_SafetyZone_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

static const char SAFETYZONE[] = "pal_navigation_msgs/SafetyZone";

  class SafetyZoneRequest : public ros::Msg
  {
    public:
      typedef float _distance_type;
      _distance_type distance;
      typedef float _leftAngleRad_type;
      _leftAngleRad_type leftAngleRad;
      typedef float _rightAngleRad_type;
      _rightAngleRad_type rightAngleRad;
      typedef uint32_t _sensorMask_type;
      _sensorMask_type sensorMask;
      enum { NO_SENSORS =  0 };
      enum { ALL_SENSORS =  127 };
      enum { FRONT_SONARS =  1 };
      enum { LEFT_SONARS =  2 };
      enum { RIGHT_SONARS =  4 };
      enum { BACK_SONARS =  8 };
      enum { TORSO_SONARS =  16 };
      enum { ONLY_SONARS =  31 };
      enum { BASE_LASER =  32 };
      enum { TORSO_LASER =  64 };
      enum { ONLY_LASERS =  96 };

    SafetyZoneRequest():
      distance(0),
      leftAngleRad(0),
      rightAngleRad(0),
      sensorMask(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->distance);
      offset += serializeAvrFloat64(outbuffer + offset, this->leftAngleRad);
      offset += serializeAvrFloat64(outbuffer + offset, this->rightAngleRad);
      *(outbuffer + offset + 0) = (this->sensorMask >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sensorMask >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sensorMask >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sensorMask >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sensorMask);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->leftAngleRad));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rightAngleRad));
      this->sensorMask =  ((uint32_t) (*(inbuffer + offset)));
      this->sensorMask |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sensorMask |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sensorMask |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sensorMask);
     return offset;
    }

    const char * getType(){ return SAFETYZONE; };
    const char * getMD5(){ return "269cbb74525b0bd07e71e2ec943affd4"; };

  };

  class SafetyZoneResponse : public ros::Msg
  {
    public:
      typedef bool _leftSafe_type;
      _leftSafe_type leftSafe;
      typedef float _leftMinDist_type;
      _leftMinDist_type leftMinDist;
      typedef float _leftMinDistAngleRad_type;
      _leftMinDistAngleRad_type leftMinDistAngleRad;
      typedef bool _rightSafe_type;
      _rightSafe_type rightSafe;
      typedef float _rightMinDist_type;
      _rightMinDist_type rightMinDist;
      typedef float _rightMinDistAngleRad_type;
      _rightMinDistAngleRad_type rightMinDistAngleRad;

    SafetyZoneResponse():
      leftSafe(0),
      leftMinDist(0),
      leftMinDistAngleRad(0),
      rightSafe(0),
      rightMinDist(0),
      rightMinDistAngleRad(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_leftSafe;
      u_leftSafe.real = this->leftSafe;
      *(outbuffer + offset + 0) = (u_leftSafe.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->leftSafe);
      offset += serializeAvrFloat64(outbuffer + offset, this->leftMinDist);
      offset += serializeAvrFloat64(outbuffer + offset, this->leftMinDistAngleRad);
      union {
        bool real;
        uint8_t base;
      } u_rightSafe;
      u_rightSafe.real = this->rightSafe;
      *(outbuffer + offset + 0) = (u_rightSafe.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rightSafe);
      offset += serializeAvrFloat64(outbuffer + offset, this->rightMinDist);
      offset += serializeAvrFloat64(outbuffer + offset, this->rightMinDistAngleRad);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_leftSafe;
      u_leftSafe.base = 0;
      u_leftSafe.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->leftSafe = u_leftSafe.real;
      offset += sizeof(this->leftSafe);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->leftMinDist));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->leftMinDistAngleRad));
      union {
        bool real;
        uint8_t base;
      } u_rightSafe;
      u_rightSafe.base = 0;
      u_rightSafe.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rightSafe = u_rightSafe.real;
      offset += sizeof(this->rightSafe);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rightMinDist));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rightMinDistAngleRad));
     return offset;
    }

    const char * getType(){ return SAFETYZONE; };
    const char * getMD5(){ return "e2ae1feeb09d43547ad602b6e1dca6d7"; };

  };

  class SafetyZone {
    public:
    typedef SafetyZoneRequest Request;
    typedef SafetyZoneResponse Response;
  };

}
#endif
