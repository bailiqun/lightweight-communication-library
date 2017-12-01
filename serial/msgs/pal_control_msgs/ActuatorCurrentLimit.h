#ifndef _ROS_pal_control_msgs_ActuatorCurrentLimit_h
#define _ROS_pal_control_msgs_ActuatorCurrentLimit_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_control_msgs
{

  class ActuatorCurrentLimit : public ros::Msg
  {
    public:
      uint32_t actuator_names_length;
      typedef char* _actuator_names_type;
      _actuator_names_type st_actuator_names;
      _actuator_names_type * actuator_names;
      uint32_t current_limits_length;
      typedef float _current_limits_type;
      _current_limits_type st_current_limits;
      _current_limits_type * current_limits;

    ActuatorCurrentLimit():
      actuator_names_length(0), actuator_names(NULL),
      current_limits_length(0), current_limits(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->actuator_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->actuator_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->actuator_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->actuator_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->actuator_names_length);
      for( uint32_t i = 0; i < actuator_names_length; i++){
      uint32_t length_actuator_namesi = strlen(this->actuator_names[i]);
      varToArr(outbuffer + offset, length_actuator_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->actuator_names[i], length_actuator_namesi);
      offset += length_actuator_namesi;
      }
      *(outbuffer + offset + 0) = (this->current_limits_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_limits_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->current_limits_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->current_limits_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_limits_length);
      for( uint32_t i = 0; i < current_limits_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->current_limits[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t actuator_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      actuator_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      actuator_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      actuator_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->actuator_names_length);
      if(actuator_names_lengthT > actuator_names_length)
        this->actuator_names = (char**)realloc(this->actuator_names, actuator_names_lengthT * sizeof(char*));
      actuator_names_length = actuator_names_lengthT;
      for( uint32_t i = 0; i < actuator_names_length; i++){
      uint32_t length_st_actuator_names;
      arrToVar(length_st_actuator_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_actuator_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_actuator_names-1]=0;
      this->st_actuator_names = (char *)(inbuffer + offset-1);
      offset += length_st_actuator_names;
        memcpy( &(this->actuator_names[i]), &(this->st_actuator_names), sizeof(char*));
      }
      uint32_t current_limits_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      current_limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      current_limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      current_limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->current_limits_length);
      if(current_limits_lengthT > current_limits_length)
        this->current_limits = (float*)realloc(this->current_limits, current_limits_lengthT * sizeof(float));
      current_limits_length = current_limits_lengthT;
      for( uint32_t i = 0; i < current_limits_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_current_limits));
        memcpy( &(this->current_limits[i]), &(this->st_current_limits), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "pal_control_msgs/ActuatorCurrentLimit"; };
    const char * getMD5(){ return "974a1b5c83bb8df5691c27dbd5b363bc"; };

  };

}
#endif