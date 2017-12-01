#ifndef _ROS_pal_interaction_msgs_asrupdate_h
#define _ROS_pal_interaction_msgs_asrupdate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class asrupdate : public ros::Msg
  {
    public:
      typedef const char* _language_type;
      _language_type language;
      typedef const char* _enable_grammar_type;
      _enable_grammar_type enable_grammar;
      typedef const char* _disable_grammar_type;
      _disable_grammar_type disable_grammar;
      typedef const char* _acousticenv_type;
      _acousticenv_type acousticenv;
      typedef bool _active_type;
      _active_type active;

    asrupdate():
      language(""),
      enable_grammar(""),
      disable_grammar(""),
      acousticenv(""),
      active(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_language = strlen(this->language);
      varToArr(outbuffer + offset, length_language);
      offset += 4;
      memcpy(outbuffer + offset, this->language, length_language);
      offset += length_language;
      uint32_t length_enable_grammar = strlen(this->enable_grammar);
      varToArr(outbuffer + offset, length_enable_grammar);
      offset += 4;
      memcpy(outbuffer + offset, this->enable_grammar, length_enable_grammar);
      offset += length_enable_grammar;
      uint32_t length_disable_grammar = strlen(this->disable_grammar);
      varToArr(outbuffer + offset, length_disable_grammar);
      offset += 4;
      memcpy(outbuffer + offset, this->disable_grammar, length_disable_grammar);
      offset += length_disable_grammar;
      uint32_t length_acousticenv = strlen(this->acousticenv);
      varToArr(outbuffer + offset, length_acousticenv);
      offset += 4;
      memcpy(outbuffer + offset, this->acousticenv, length_acousticenv);
      offset += length_acousticenv;
      union {
        bool real;
        uint8_t base;
      } u_active;
      u_active.real = this->active;
      *(outbuffer + offset + 0) = (u_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_language;
      arrToVar(length_language, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_language; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_language-1]=0;
      this->language = (char *)(inbuffer + offset-1);
      offset += length_language;
      uint32_t length_enable_grammar;
      arrToVar(length_enable_grammar, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_enable_grammar; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_enable_grammar-1]=0;
      this->enable_grammar = (char *)(inbuffer + offset-1);
      offset += length_enable_grammar;
      uint32_t length_disable_grammar;
      arrToVar(length_disable_grammar, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_disable_grammar; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_disable_grammar-1]=0;
      this->disable_grammar = (char *)(inbuffer + offset-1);
      offset += length_disable_grammar;
      uint32_t length_acousticenv;
      arrToVar(length_acousticenv, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_acousticenv; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_acousticenv-1]=0;
      this->acousticenv = (char *)(inbuffer + offset-1);
      offset += length_acousticenv;
      union {
        bool real;
        uint8_t base;
      } u_active;
      u_active.base = 0;
      u_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->active = u_active.real;
      offset += sizeof(this->active);
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/asrupdate"; };
    const char * getMD5(){ return "1f28e753977d8fe335d6b968a649f1ed"; };

  };

}
#endif