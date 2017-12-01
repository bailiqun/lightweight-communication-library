#ifndef _ROS_pal_interaction_msgs_I18nText_h
#define _ROS_pal_interaction_msgs_I18nText_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_interaction_msgs/I18nArgument.h"

namespace pal_interaction_msgs
{

  class I18nText : public ros::Msg
  {
    public:
      typedef const char* _section_type;
      _section_type section;
      typedef const char* _key_type;
      _key_type key;
      typedef const char* _lang_id_type;
      _lang_id_type lang_id;
      uint32_t arguments_length;
      typedef pal_interaction_msgs::I18nArgument _arguments_type;
      _arguments_type st_arguments;
      _arguments_type * arguments;

    I18nText():
      section(""),
      key(""),
      lang_id(""),
      arguments_length(0), arguments(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_section = strlen(this->section);
      varToArr(outbuffer + offset, length_section);
      offset += 4;
      memcpy(outbuffer + offset, this->section, length_section);
      offset += length_section;
      uint32_t length_key = strlen(this->key);
      varToArr(outbuffer + offset, length_key);
      offset += 4;
      memcpy(outbuffer + offset, this->key, length_key);
      offset += length_key;
      uint32_t length_lang_id = strlen(this->lang_id);
      varToArr(outbuffer + offset, length_lang_id);
      offset += 4;
      memcpy(outbuffer + offset, this->lang_id, length_lang_id);
      offset += length_lang_id;
      *(outbuffer + offset + 0) = (this->arguments_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->arguments_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->arguments_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->arguments_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->arguments_length);
      for( uint32_t i = 0; i < arguments_length; i++){
      offset += this->arguments[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_section;
      arrToVar(length_section, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_section; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_section-1]=0;
      this->section = (char *)(inbuffer + offset-1);
      offset += length_section;
      uint32_t length_key;
      arrToVar(length_key, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_key; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_key-1]=0;
      this->key = (char *)(inbuffer + offset-1);
      offset += length_key;
      uint32_t length_lang_id;
      arrToVar(length_lang_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lang_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lang_id-1]=0;
      this->lang_id = (char *)(inbuffer + offset-1);
      offset += length_lang_id;
      uint32_t arguments_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      arguments_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      arguments_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      arguments_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->arguments_length);
      if(arguments_lengthT > arguments_length)
        this->arguments = (pal_interaction_msgs::I18nArgument*)realloc(this->arguments, arguments_lengthT * sizeof(pal_interaction_msgs::I18nArgument));
      arguments_length = arguments_lengthT;
      for( uint32_t i = 0; i < arguments_length; i++){
      offset += this->st_arguments.deserialize(inbuffer + offset);
        memcpy( &(this->arguments[i]), &(this->st_arguments), sizeof(pal_interaction_msgs::I18nArgument));
      }
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/I18nText"; };
    const char * getMD5(){ return "855c0cd82eb6837b039ea45087975cc2"; };

  };

}
#endif