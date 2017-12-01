#ifndef _ROS_SERVICE_SaveMap_h
#define _ROS_SERVICE_SaveMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

static const char SAVEMAP[] = "pal_navigation_msgs/SaveMap";

  class SaveMapRequest : public ros::Msg
  {
    public:
      typedef const char* _directory_type;
      _directory_type directory;

    SaveMapRequest():
      directory("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_directory = strlen(this->directory);
      varToArr(outbuffer + offset, length_directory);
      offset += 4;
      memcpy(outbuffer + offset, this->directory, length_directory);
      offset += length_directory;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_directory;
      arrToVar(length_directory, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_directory; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_directory-1]=0;
      this->directory = (char *)(inbuffer + offset-1);
      offset += length_directory;
     return offset;
    }

    const char * getType(){ return SAVEMAP; };
    const char * getMD5(){ return "310e138069b8368226f05a8c4e7bb107"; };

  };

  class SaveMapResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _full_path_type;
      _full_path_type full_path;
      typedef const char* _message_type;
      _message_type message;

    SaveMapResponse():
      success(0),
      name(""),
      full_path(""),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_full_path = strlen(this->full_path);
      varToArr(outbuffer + offset, length_full_path);
      offset += 4;
      memcpy(outbuffer + offset, this->full_path, length_full_path);
      offset += length_full_path;
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_full_path;
      arrToVar(length_full_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_full_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_full_path-1]=0;
      this->full_path = (char *)(inbuffer + offset-1);
      offset += length_full_path;
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    const char * getType(){ return SAVEMAP; };
    const char * getMD5(){ return "0cbfca185576cdac677b2dbfe46084ca"; };

  };

  class SaveMap {
    public:
    typedef SaveMapRequest Request;
    typedef SaveMapResponse Response;
  };

}
#endif
