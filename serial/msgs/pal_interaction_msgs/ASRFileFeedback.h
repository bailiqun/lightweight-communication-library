#ifndef _ROS_pal_interaction_msgs_ASRFileFeedback_h
#define _ROS_pal_interaction_msgs_ASRFileFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_interaction_msgs/asrresult.h"

namespace pal_interaction_msgs
{

  class ASRFileFeedback : public ros::Msg
  {
    public:
      typedef pal_interaction_msgs::asrresult _recognised_utterance_type;
      _recognised_utterance_type recognised_utterance;

    ASRFileFeedback():
      recognised_utterance()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->recognised_utterance.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->recognised_utterance.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/ASRFileFeedback"; };
    const char * getMD5(){ return "e8f3da6b7eb47ddaa66e1eca614ca0be"; };

  };

}
#endif