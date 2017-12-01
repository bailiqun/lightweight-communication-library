#ifndef _ROS_SERVICE_CurrentLimit_h
#define _ROS_SERVICE_CurrentLimit_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_control_msgs
{

static const char CURRENTLIMIT[] = "pal_control_msgs/CurrentLimit";

  class CurrentLimitRequest : public ros::Msg
  {
    public:
      typedef const char* _actuator_name_type;
      _actuator_name_type actuator_name;
      typedef float _current_limit_type;
      _current_limit_type current_limit;

    CurrentLimitRequest():
      actuator_name(""),
      current_limit(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_actuator_name = strlen(this->actuator_name);
      varToArr(outbuffer + offset, length_actuator_name);
      offset += 4;
      memcpy(outbuffer + offset, this->actuator_name, length_actuator_name);
      offset += length_actuator_name;
      offset += serializeAvrFloat64(outbuffer + offset, this->current_limit);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_actuator_name;
      arrToVar(length_actuator_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_actuator_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_actuator_name-1]=0;
      this->actuator_name = (char *)(inbuffer + offset-1);
      offset += length_actuator_name;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->current_limit));
     return offset;
    }

    const char * getType(){ return CURRENTLIMIT; };
    const char * getMD5(){ return "6d1326759cec3fceb10a88d2834f6fba"; };

  };

  class CurrentLimitResponse : public ros::Msg
  {
    public:
      typedef const char* _status_type;
      _status_type status;

    CurrentLimitResponse():
      status("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_status = strlen(this->status);
      varToArr(outbuffer + offset, length_status);
      offset += 4;
      memcpy(outbuffer + offset, this->status, length_status);
      offset += length_status;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_status;
      arrToVar(length_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status-1]=0;
      this->status = (char *)(inbuffer + offset-1);
      offset += length_status;
     return offset;
    }

    const char * getType(){ return CURRENTLIMIT; };
    const char * getMD5(){ return "4fe5af303955c287688e7347e9b00278"; };

  };

  class CurrentLimit {
    public:
    typedef CurrentLimitRequest Request;
    typedef CurrentLimitResponse Response;
  };

}
#endif
