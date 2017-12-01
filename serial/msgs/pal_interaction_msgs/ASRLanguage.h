#ifndef _ROS_pal_interaction_msgs_ASRLanguage_h
#define _ROS_pal_interaction_msgs_ASRLanguage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class ASRLanguage : public ros::Msg
  {
    public:
      typedef const char* _language_type;
      _language_type language;

    ASRLanguage():
      language("")
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
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/ASRLanguage"; };
    const char * getMD5(){ return "f9264c5bffd188939e827e658af68a0d"; };

  };

}
#endif