#ifndef _ROS_pal_interaction_msgs_ASRFileGoal_h
#define _ROS_pal_interaction_msgs_ASRFileGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class ASRFileGoal : public ros::Msg
  {
    public:
      typedef const char* _file_type;
      _file_type file;
      typedef const char* _lang_id_type;
      _lang_id_type lang_id;
      typedef const char* _grammar_type;
      _grammar_type grammar;

    ASRFileGoal():
      file(""),
      lang_id(""),
      grammar("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_file = strlen(this->file);
      varToArr(outbuffer + offset, length_file);
      offset += 4;
      memcpy(outbuffer + offset, this->file, length_file);
      offset += length_file;
      uint32_t length_lang_id = strlen(this->lang_id);
      varToArr(outbuffer + offset, length_lang_id);
      offset += 4;
      memcpy(outbuffer + offset, this->lang_id, length_lang_id);
      offset += length_lang_id;
      uint32_t length_grammar = strlen(this->grammar);
      varToArr(outbuffer + offset, length_grammar);
      offset += 4;
      memcpy(outbuffer + offset, this->grammar, length_grammar);
      offset += length_grammar;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_file;
      arrToVar(length_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file-1]=0;
      this->file = (char *)(inbuffer + offset-1);
      offset += length_file;
      uint32_t length_lang_id;
      arrToVar(length_lang_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lang_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lang_id-1]=0;
      this->lang_id = (char *)(inbuffer + offset-1);
      offset += length_lang_id;
      uint32_t length_grammar;
      arrToVar(length_grammar, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_grammar; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_grammar-1]=0;
      this->grammar = (char *)(inbuffer + offset-1);
      offset += length_grammar;
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/ASRFileGoal"; };
    const char * getMD5(){ return "31bee1dbb9e7542a0b7c4085dead9edf"; };

  };

}
#endif