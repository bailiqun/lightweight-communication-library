#ifndef _ROS_pal_interaction_msgs_TtsGoal_h
#define _ROS_pal_interaction_msgs_TtsGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_interaction_msgs/I18nText.h"
#include "pal_interaction_msgs/TtsText.h"

namespace pal_interaction_msgs
{

  class TtsGoal : public ros::Msg
  {
    public:
      typedef pal_interaction_msgs::I18nText _text_type;
      _text_type text;
      typedef pal_interaction_msgs::TtsText _rawtext_type;
      _rawtext_type rawtext;
      typedef const char* _speakerName_type;
      _speakerName_type speakerName;
      typedef float _wait_before_speaking_type;
      _wait_before_speaking_type wait_before_speaking;

    TtsGoal():
      text(),
      rawtext(),
      speakerName(""),
      wait_before_speaking(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->text.serialize(outbuffer + offset);
      offset += this->rawtext.serialize(outbuffer + offset);
      uint32_t length_speakerName = strlen(this->speakerName);
      varToArr(outbuffer + offset, length_speakerName);
      offset += 4;
      memcpy(outbuffer + offset, this->speakerName, length_speakerName);
      offset += length_speakerName;
      offset += serializeAvrFloat64(outbuffer + offset, this->wait_before_speaking);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->text.deserialize(inbuffer + offset);
      offset += this->rawtext.deserialize(inbuffer + offset);
      uint32_t length_speakerName;
      arrToVar(length_speakerName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_speakerName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_speakerName-1]=0;
      this->speakerName = (char *)(inbuffer + offset-1);
      offset += length_speakerName;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->wait_before_speaking));
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/TtsGoal"; };
    const char * getMD5(){ return "9c88bf4a4d119474b8ae97c98892bc78"; };

  };

}
#endif