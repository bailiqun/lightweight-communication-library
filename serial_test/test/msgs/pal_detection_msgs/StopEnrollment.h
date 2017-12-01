#ifndef _ROS_SERVICE_StopEnrollment_h
#define _ROS_SERVICE_StopEnrollment_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_detection_msgs
{

static const char STOPENROLLMENT[] = "pal_detection_msgs/StopEnrollment";

  class StopEnrollmentRequest : public ros::Msg
  {
    public:

    StopEnrollmentRequest()
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

    const char * getType(){ return STOPENROLLMENT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class StopEnrollmentResponse : public ros::Msg
  {
    public:
      typedef bool _enrollment_ok_type;
      _enrollment_ok_type enrollment_ok;
      typedef int32_t _numFacesEnrolled_type;
      _numFacesEnrolled_type numFacesEnrolled;
      typedef const char* _error_msg_type;
      _error_msg_type error_msg;

    StopEnrollmentResponse():
      enrollment_ok(0),
      numFacesEnrolled(0),
      error_msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enrollment_ok;
      u_enrollment_ok.real = this->enrollment_ok;
      *(outbuffer + offset + 0) = (u_enrollment_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enrollment_ok);
      union {
        int32_t real;
        uint32_t base;
      } u_numFacesEnrolled;
      u_numFacesEnrolled.real = this->numFacesEnrolled;
      *(outbuffer + offset + 0) = (u_numFacesEnrolled.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_numFacesEnrolled.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_numFacesEnrolled.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_numFacesEnrolled.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->numFacesEnrolled);
      uint32_t length_error_msg = strlen(this->error_msg);
      varToArr(outbuffer + offset, length_error_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->error_msg, length_error_msg);
      offset += length_error_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enrollment_ok;
      u_enrollment_ok.base = 0;
      u_enrollment_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enrollment_ok = u_enrollment_ok.real;
      offset += sizeof(this->enrollment_ok);
      union {
        int32_t real;
        uint32_t base;
      } u_numFacesEnrolled;
      u_numFacesEnrolled.base = 0;
      u_numFacesEnrolled.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_numFacesEnrolled.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_numFacesEnrolled.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_numFacesEnrolled.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->numFacesEnrolled = u_numFacesEnrolled.real;
      offset += sizeof(this->numFacesEnrolled);
      uint32_t length_error_msg;
      arrToVar(length_error_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error_msg-1]=0;
      this->error_msg = (char *)(inbuffer + offset-1);
      offset += length_error_msg;
     return offset;
    }

    const char * getType(){ return STOPENROLLMENT; };
    const char * getMD5(){ return "fb84ca50753c7bbc7737a1c5095dac61"; };

  };

  class StopEnrollment {
    public:
    typedef StopEnrollmentRequest Request;
    typedef StopEnrollmentResponse Response;
  };

}
#endif
