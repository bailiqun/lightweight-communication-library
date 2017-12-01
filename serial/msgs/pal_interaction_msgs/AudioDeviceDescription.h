#ifndef _ROS_pal_interaction_msgs_AudioDeviceDescription_h
#define _ROS_pal_interaction_msgs_AudioDeviceDescription_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class AudioDeviceDescription : public ros::Msg
  {
    public:
      typedef const char* _device_name_type;
      _device_name_type device_name;
      typedef uint32_t _sample_rate_type;
      _sample_rate_type sample_rate;
      typedef int8_t _sample_size_type;
      _sample_size_type sample_size;
      typedef int8_t _format_type;
      _format_type format;
      typedef uint16_t _buffer_size_type;
      _buffer_size_type buffer_size;
      typedef int8_t _number_of_channels_type;
      _number_of_channels_type number_of_channels;
      enum { SIGNED =  0 };
      enum { UNSIGNED =  1 };

    AudioDeviceDescription():
      device_name(""),
      sample_rate(0),
      sample_size(0),
      format(0),
      buffer_size(0),
      number_of_channels(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_device_name = strlen(this->device_name);
      varToArr(outbuffer + offset, length_device_name);
      offset += 4;
      memcpy(outbuffer + offset, this->device_name, length_device_name);
      offset += length_device_name;
      *(outbuffer + offset + 0) = (this->sample_rate >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sample_rate >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sample_rate >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sample_rate >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sample_rate);
      union {
        int8_t real;
        uint8_t base;
      } u_sample_size;
      u_sample_size.real = this->sample_size;
      *(outbuffer + offset + 0) = (u_sample_size.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sample_size);
      union {
        int8_t real;
        uint8_t base;
      } u_format;
      u_format.real = this->format;
      *(outbuffer + offset + 0) = (u_format.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->format);
      *(outbuffer + offset + 0) = (this->buffer_size >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->buffer_size >> (8 * 1)) & 0xFF;
      offset += sizeof(this->buffer_size);
      union {
        int8_t real;
        uint8_t base;
      } u_number_of_channels;
      u_number_of_channels.real = this->number_of_channels;
      *(outbuffer + offset + 0) = (u_number_of_channels.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->number_of_channels);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_device_name;
      arrToVar(length_device_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_device_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_device_name-1]=0;
      this->device_name = (char *)(inbuffer + offset-1);
      offset += length_device_name;
      this->sample_rate =  ((uint32_t) (*(inbuffer + offset)));
      this->sample_rate |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sample_rate |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sample_rate |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sample_rate);
      union {
        int8_t real;
        uint8_t base;
      } u_sample_size;
      u_sample_size.base = 0;
      u_sample_size.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sample_size = u_sample_size.real;
      offset += sizeof(this->sample_size);
      union {
        int8_t real;
        uint8_t base;
      } u_format;
      u_format.base = 0;
      u_format.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->format = u_format.real;
      offset += sizeof(this->format);
      this->buffer_size =  ((uint16_t) (*(inbuffer + offset)));
      this->buffer_size |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->buffer_size);
      union {
        int8_t real;
        uint8_t base;
      } u_number_of_channels;
      u_number_of_channels.base = 0;
      u_number_of_channels.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->number_of_channels = u_number_of_channels.real;
      offset += sizeof(this->number_of_channels);
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/AudioDeviceDescription"; };
    const char * getMD5(){ return "e55171ed98aeb49e34453bc5efb47184"; };

  };

}
#endif