#ifndef _ROS_pal_interaction_msgs_TtsMark_h
#define _ROS_pal_interaction_msgs_TtsMark_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class TtsMark : public ros::Msg
  {
    public:
      typedef const char* _id_type;
      _id_type id;
      uint32_t keys_length;
      typedef char* _keys_type;
      _keys_type st_keys;
      _keys_type * keys;
      uint32_t value_length;
      typedef char* _value_type;
      _value_type st_value;
      _value_type * value;

    TtsMark():
      id(""),
      keys_length(0), keys(NULL),
      value_length(0), value(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      *(outbuffer + offset + 0) = (this->keys_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->keys_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->keys_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->keys_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->keys_length);
      for( uint32_t i = 0; i < keys_length; i++){
      uint32_t length_keysi = strlen(this->keys[i]);
      varToArr(outbuffer + offset, length_keysi);
      offset += 4;
      memcpy(outbuffer + offset, this->keys[i], length_keysi);
      offset += length_keysi;
      }
      *(outbuffer + offset + 0) = (this->value_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->value_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->value_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value_length);
      for( uint32_t i = 0; i < value_length; i++){
      uint32_t length_valuei = strlen(this->value[i]);
      varToArr(outbuffer + offset, length_valuei);
      offset += 4;
      memcpy(outbuffer + offset, this->value[i], length_valuei);
      offset += length_valuei;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      uint32_t keys_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      keys_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      keys_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      keys_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->keys_length);
      if(keys_lengthT > keys_length)
        this->keys = (char**)realloc(this->keys, keys_lengthT * sizeof(char*));
      keys_length = keys_lengthT;
      for( uint32_t i = 0; i < keys_length; i++){
      uint32_t length_st_keys;
      arrToVar(length_st_keys, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_keys; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_keys-1]=0;
      this->st_keys = (char *)(inbuffer + offset-1);
      offset += length_st_keys;
        memcpy( &(this->keys[i]), &(this->st_keys), sizeof(char*));
      }
      uint32_t value_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->value_length);
      if(value_lengthT > value_length)
        this->value = (char**)realloc(this->value, value_lengthT * sizeof(char*));
      value_length = value_lengthT;
      for( uint32_t i = 0; i < value_length; i++){
      uint32_t length_st_value;
      arrToVar(length_st_value, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_value-1]=0;
      this->st_value = (char *)(inbuffer + offset-1);
      offset += length_st_value;
        memcpy( &(this->value[i]), &(this->st_value), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/TtsMark"; };
    const char * getMD5(){ return "10ae9a83cac56ac1660df7e26eabeac9"; };

  };

}
#endif