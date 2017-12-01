#ifndef _ROS_pal_interaction_msgs_TTSstate_h
#define _ROS_pal_interaction_msgs_TTSstate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class TTSstate : public ros::Msg
  {
    public:
      typedef bool _isSpeaking_type;
      _isSpeaking_type isSpeaking;
      typedef const char* _text_type;
      _text_type text;

    TTSstate():
      isSpeaking(0),
      text("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_isSpeaking;
      u_isSpeaking.real = this->isSpeaking;
      *(outbuffer + offset + 0) = (u_isSpeaking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isSpeaking);
      uint32_t length_text = strlen(this->text);
      varToArr(outbuffer + offset, length_text);
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_isSpeaking;
      u_isSpeaking.base = 0;
      u_isSpeaking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isSpeaking = u_isSpeaking.real;
      offset += sizeof(this->isSpeaking);
      uint32_t length_text;
      arrToVar(length_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/TTSstate"; };
    const char * getMD5(){ return "b3b6b5f485986278e907e9bb4f658e3d"; };

  };

}
#endif