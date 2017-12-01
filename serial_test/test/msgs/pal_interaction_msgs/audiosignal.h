#ifndef _ROS_pal_interaction_msgs_audiosignal_h
#define _ROS_pal_interaction_msgs_audiosignal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class audiosignal : public ros::Msg
  {
    public:
      uint32_t channel0_length;
      typedef float _channel0_type;
      _channel0_type st_channel0;
      _channel0_type * channel0;
      uint32_t channel1_length;
      typedef float _channel1_type;
      _channel1_type st_channel1;
      _channel1_type * channel1;

    audiosignal():
      channel0_length(0), channel0(NULL),
      channel1_length(0), channel1(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->channel0_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->channel0_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->channel0_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->channel0_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->channel0_length);
      for( uint32_t i = 0; i < channel0_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->channel0[i]);
      }
      *(outbuffer + offset + 0) = (this->channel1_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->channel1_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->channel1_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->channel1_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->channel1_length);
      for( uint32_t i = 0; i < channel1_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->channel1[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t channel0_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      channel0_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      channel0_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      channel0_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->channel0_length);
      if(channel0_lengthT > channel0_length)
        this->channel0 = (float*)realloc(this->channel0, channel0_lengthT * sizeof(float));
      channel0_length = channel0_lengthT;
      for( uint32_t i = 0; i < channel0_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_channel0));
        memcpy( &(this->channel0[i]), &(this->st_channel0), sizeof(float));
      }
      uint32_t channel1_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      channel1_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      channel1_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      channel1_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->channel1_length);
      if(channel1_lengthT > channel1_length)
        this->channel1 = (float*)realloc(this->channel1, channel1_lengthT * sizeof(float));
      channel1_length = channel1_lengthT;
      for( uint32_t i = 0; i < channel1_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_channel1));
        memcpy( &(this->channel1[i]), &(this->st_channel1), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/audiosignal"; };
    const char * getMD5(){ return "9406f94b261ed2ebad808e7af5b61907"; };

  };

}
#endif