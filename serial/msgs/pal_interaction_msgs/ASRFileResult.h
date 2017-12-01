#ifndef _ROS_pal_interaction_msgs_ASRFileResult_h
#define _ROS_pal_interaction_msgs_ASRFileResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_interaction_msgs/asrresult.h"

namespace pal_interaction_msgs
{

  class ASRFileResult : public ros::Msg
  {
    public:
      typedef const char* _file_type;
      _file_type file;
      typedef const char* _msg_type;
      _msg_type msg;
      uint32_t recognised_utterances_length;
      typedef pal_interaction_msgs::asrresult _recognised_utterances_type;
      _recognised_utterances_type st_recognised_utterances;
      _recognised_utterances_type * recognised_utterances;

    ASRFileResult():
      file(""),
      msg(""),
      recognised_utterances_length(0), recognised_utterances(NULL)
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
      uint32_t length_msg = strlen(this->msg);
      varToArr(outbuffer + offset, length_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->msg, length_msg);
      offset += length_msg;
      *(outbuffer + offset + 0) = (this->recognised_utterances_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->recognised_utterances_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->recognised_utterances_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->recognised_utterances_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->recognised_utterances_length);
      for( uint32_t i = 0; i < recognised_utterances_length; i++){
      offset += this->recognised_utterances[i].serialize(outbuffer + offset);
      }
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
      uint32_t length_msg;
      arrToVar(length_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
      uint32_t recognised_utterances_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      recognised_utterances_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      recognised_utterances_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      recognised_utterances_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->recognised_utterances_length);
      if(recognised_utterances_lengthT > recognised_utterances_length)
        this->recognised_utterances = (pal_interaction_msgs::asrresult*)realloc(this->recognised_utterances, recognised_utterances_lengthT * sizeof(pal_interaction_msgs::asrresult));
      recognised_utterances_length = recognised_utterances_lengthT;
      for( uint32_t i = 0; i < recognised_utterances_length; i++){
      offset += this->st_recognised_utterances.deserialize(inbuffer + offset);
        memcpy( &(this->recognised_utterances[i]), &(this->st_recognised_utterances), sizeof(pal_interaction_msgs::asrresult));
      }
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/ASRFileResult"; };
    const char * getMD5(){ return "f039521e38adb20a017037121dedb1d4"; };

  };

}
#endif