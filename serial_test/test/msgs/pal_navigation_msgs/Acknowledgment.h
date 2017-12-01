#ifndef _ROS_SERVICE_Acknowledgment_h
#define _ROS_SERVICE_Acknowledgment_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

static const char ACKNOWLEDGMENT[] = "pal_navigation_msgs/Acknowledgment";

  class AcknowledgmentRequest : public ros::Msg
  {
    public:
      typedef const char* _input_type;
      _input_type input;

    AcknowledgmentRequest():
      input("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_input = strlen(this->input);
      varToArr(outbuffer + offset, length_input);
      offset += 4;
      memcpy(outbuffer + offset, this->input, length_input);
      offset += length_input;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_input;
      arrToVar(length_input, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_input; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_input-1]=0;
      this->input = (char *)(inbuffer + offset-1);
      offset += length_input;
     return offset;
    }

    const char * getType(){ return ACKNOWLEDGMENT; };
    const char * getMD5(){ return "39e92f1778057359c64c7b8a7d7b19de"; };

  };

  class AcknowledgmentResponse : public ros::Msg
  {
    public:
      typedef bool _output_type;
      _output_type output;
      typedef const char* _error_type;
      _error_type error;

    AcknowledgmentResponse():
      output(0),
      error("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_output;
      u_output.real = this->output;
      *(outbuffer + offset + 0) = (u_output.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->output);
      uint32_t length_error = strlen(this->error);
      varToArr(outbuffer + offset, length_error);
      offset += 4;
      memcpy(outbuffer + offset, this->error, length_error);
      offset += length_error;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_output;
      u_output.base = 0;
      u_output.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->output = u_output.real;
      offset += sizeof(this->output);
      uint32_t length_error;
      arrToVar(length_error, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error-1]=0;
      this->error = (char *)(inbuffer + offset-1);
      offset += length_error;
     return offset;
    }

    const char * getType(){ return ACKNOWLEDGMENT; };
    const char * getMD5(){ return "bf71ecd1af59cd66f913901847b1a87c"; };

  };

  class Acknowledgment {
    public:
    typedef AcknowledgmentRequest Request;
    typedef AcknowledgmentResponse Response;
  };

}
#endif
