#ifndef _ROS_pal_interaction_msgs_VoiceActivity_h
#define _ROS_pal_interaction_msgs_VoiceActivity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class VoiceActivity : public ros::Msg
  {
    public:
      typedef bool _isSpeech_type;
      _isSpeech_type isSpeech;

    VoiceActivity():
      isSpeech(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_isSpeech;
      u_isSpeech.real = this->isSpeech;
      *(outbuffer + offset + 0) = (u_isSpeech.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isSpeech);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_isSpeech;
      u_isSpeech.base = 0;
      u_isSpeech.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isSpeech = u_isSpeech.real;
      offset += sizeof(this->isSpeech);
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/VoiceActivity"; };
    const char * getMD5(){ return "6ec045a05170c3f88f25da9af745836f"; };

  };

}
#endif