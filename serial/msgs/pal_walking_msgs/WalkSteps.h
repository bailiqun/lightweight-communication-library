#ifndef _ROS_SERVICE_WalkSteps_h
#define _ROS_SERVICE_WalkSteps_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_walking_msgs
{

static const char WALKSTEPS[] = "pal_walking_msgs/WalkSteps";

  class WalkStepsRequest : public ros::Msg
  {
    public:
      typedef int32_t _nsteps_type;
      _nsteps_type nsteps;
      typedef float _step_length_type;
      _step_length_type step_length;
      typedef float _step_time_type;
      _step_time_type step_time;

    WalkStepsRequest():
      nsteps(0),
      step_length(0),
      step_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_nsteps;
      u_nsteps.real = this->nsteps;
      *(outbuffer + offset + 0) = (u_nsteps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nsteps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nsteps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nsteps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nsteps);
      offset += serializeAvrFloat64(outbuffer + offset, this->step_length);
      offset += serializeAvrFloat64(outbuffer + offset, this->step_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_nsteps;
      u_nsteps.base = 0;
      u_nsteps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nsteps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nsteps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nsteps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nsteps = u_nsteps.real;
      offset += sizeof(this->nsteps);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->step_length));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->step_time));
     return offset;
    }

    const char * getType(){ return WALKSTEPS; };
    const char * getMD5(){ return "58a83587aa65e3865f04c9ed9e7cdaaf"; };

  };

  class WalkStepsResponse : public ros::Msg
  {
    public:

    WalkStepsResponse()
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

    const char * getType(){ return WALKSTEPS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class WalkSteps {
    public:
    typedef WalkStepsRequest Request;
    typedef WalkStepsResponse Response;
  };

}
#endif
