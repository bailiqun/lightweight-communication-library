#ifndef _ROS_pal_interaction_msgs_AudioPlayerState_h
#define _ROS_pal_interaction_msgs_AudioPlayerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pal_interaction_msgs
{

  class AudioPlayerState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _isPlaying_type;
      _isPlaying_type isPlaying;
      typedef const char* _msg_type;
      _msg_type msg;

    AudioPlayerState():
      header(),
      isPlaying(0),
      msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_isPlaying;
      u_isPlaying.real = this->isPlaying;
      *(outbuffer + offset + 0) = (u_isPlaying.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isPlaying);
      uint32_t length_msg = strlen(this->msg);
      varToArr(outbuffer + offset, length_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->msg, length_msg);
      offset += length_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_isPlaying;
      u_isPlaying.base = 0;
      u_isPlaying.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isPlaying = u_isPlaying.real;
      offset += sizeof(this->isPlaying);
      uint32_t length_msg;
      arrToVar(length_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/AudioPlayerState"; };
    const char * getMD5(){ return "56d08544761f7625c1fa9ada542abb32"; };

  };

}
#endif