#ifndef _ROS_pal_interaction_msgs_SoundGoal_h
#define _ROS_pal_interaction_msgs_SoundGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace pal_interaction_msgs
{

  class SoundGoal : public ros::Msg
  {
    public:
      typedef const char* _text_type;
      _text_type text;
      typedef const char* _lang_id_type;
      _lang_id_type lang_id;
      typedef ros::Duration _wait_before_speaking_type;
      _wait_before_speaking_type wait_before_speaking;

    SoundGoal():
      text(""),
      lang_id(""),
      wait_before_speaking()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_text = strlen(this->text);
      varToArr(outbuffer + offset, length_text);
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
      uint32_t length_lang_id = strlen(this->lang_id);
      varToArr(outbuffer + offset, length_lang_id);
      offset += 4;
      memcpy(outbuffer + offset, this->lang_id, length_lang_id);
      offset += length_lang_id;
      *(outbuffer + offset + 0) = (this->wait_before_speaking.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wait_before_speaking.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->wait_before_speaking.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->wait_before_speaking.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wait_before_speaking.sec);
      *(outbuffer + offset + 0) = (this->wait_before_speaking.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wait_before_speaking.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->wait_before_speaking.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->wait_before_speaking.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wait_before_speaking.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_text;
      arrToVar(length_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
      uint32_t length_lang_id;
      arrToVar(length_lang_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lang_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lang_id-1]=0;
      this->lang_id = (char *)(inbuffer + offset-1);
      offset += length_lang_id;
      this->wait_before_speaking.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->wait_before_speaking.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->wait_before_speaking.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->wait_before_speaking.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->wait_before_speaking.sec);
      this->wait_before_speaking.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->wait_before_speaking.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->wait_before_speaking.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->wait_before_speaking.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->wait_before_speaking.nsec);
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/SoundGoal"; };
    const char * getMD5(){ return "a885e729fbf7cd3a957b93630532e7bf"; };

  };

}
#endif