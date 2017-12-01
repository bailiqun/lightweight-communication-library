#ifndef _ROS_SERVICE_Recognizer_h
#define _ROS_SERVICE_Recognizer_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_detection_msgs
{

static const char RECOGNIZER[] = "pal_detection_msgs/Recognizer";

  class RecognizerRequest : public ros::Msg
  {
    public:
      typedef bool _enabled_type;
      _enabled_type enabled;
      typedef float _minConfidence_type;
      _minConfidence_type minConfidence;

    RecognizerRequest():
      enabled(0),
      minConfidence(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enabled;
      u_enabled.real = this->enabled;
      *(outbuffer + offset + 0) = (u_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enabled);
      union {
        float real;
        uint32_t base;
      } u_minConfidence;
      u_minConfidence.real = this->minConfidence;
      *(outbuffer + offset + 0) = (u_minConfidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_minConfidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_minConfidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_minConfidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->minConfidence);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enabled;
      u_enabled.base = 0;
      u_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enabled = u_enabled.real;
      offset += sizeof(this->enabled);
      union {
        float real;
        uint32_t base;
      } u_minConfidence;
      u_minConfidence.base = 0;
      u_minConfidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_minConfidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_minConfidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_minConfidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->minConfidence = u_minConfidence.real;
      offset += sizeof(this->minConfidence);
     return offset;
    }

    const char * getType(){ return RECOGNIZER; };
    const char * getMD5(){ return "1988e71091b2db6d28fdeea96cff5fb1"; };

  };

  class RecognizerResponse : public ros::Msg
  {
    public:

    RecognizerResponse()
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

    const char * getType(){ return RECOGNIZER; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class Recognizer {
    public:
    typedef RecognizerRequest Request;
    typedef RecognizerResponse Response;
  };

}
#endif
