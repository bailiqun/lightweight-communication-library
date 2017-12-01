#ifndef _ROS_pal_navigation_msgs_EulerAngles_h
#define _ROS_pal_navigation_msgs_EulerAngles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

  class EulerAngles : public ros::Msg
  {
    public:
      typedef const char* _sequence_type;
      _sequence_type sequence;
      typedef bool _angles_in_degrees_type;
      _angles_in_degrees_type angles_in_degrees;
      typedef float _ai_type;
      _ai_type ai;
      typedef float _aj_type;
      _aj_type aj;
      typedef float _ak_type;
      _ak_type ak;

    EulerAngles():
      sequence(""),
      angles_in_degrees(0),
      ai(0),
      aj(0),
      ak(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_sequence = strlen(this->sequence);
      varToArr(outbuffer + offset, length_sequence);
      offset += 4;
      memcpy(outbuffer + offset, this->sequence, length_sequence);
      offset += length_sequence;
      union {
        bool real;
        uint8_t base;
      } u_angles_in_degrees;
      u_angles_in_degrees.real = this->angles_in_degrees;
      *(outbuffer + offset + 0) = (u_angles_in_degrees.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->angles_in_degrees);
      offset += serializeAvrFloat64(outbuffer + offset, this->ai);
      offset += serializeAvrFloat64(outbuffer + offset, this->aj);
      offset += serializeAvrFloat64(outbuffer + offset, this->ak);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_sequence;
      arrToVar(length_sequence, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sequence; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sequence-1]=0;
      this->sequence = (char *)(inbuffer + offset-1);
      offset += length_sequence;
      union {
        bool real;
        uint8_t base;
      } u_angles_in_degrees;
      u_angles_in_degrees.base = 0;
      u_angles_in_degrees.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->angles_in_degrees = u_angles_in_degrees.real;
      offset += sizeof(this->angles_in_degrees);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ai));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->aj));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ak));
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/EulerAngles"; };
    const char * getMD5(){ return "b41bea25ef0825fa6d2799746a51460f"; };

  };

}
#endif