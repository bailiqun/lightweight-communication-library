#ifndef _ROS_pal_interaction_msgs_ASRFileActionFeedback_h
#define _ROS_pal_interaction_msgs_ASRFileActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "pal_interaction_msgs/ASRFileFeedback.h"

namespace pal_interaction_msgs
{

  class ASRFileActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef pal_interaction_msgs::ASRFileFeedback _feedback_type;
      _feedback_type feedback;

    ASRFileActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/ASRFileActionFeedback"; };
    const char * getMD5(){ return "88e8c02ba96b633e07aaccac2c11609c"; };

  };

}
#endif