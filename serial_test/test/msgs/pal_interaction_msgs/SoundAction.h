#ifndef _ROS_pal_interaction_msgs_SoundAction_h
#define _ROS_pal_interaction_msgs_SoundAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_interaction_msgs/SoundActionGoal.h"
#include "pal_interaction_msgs/SoundActionResult.h"
#include "pal_interaction_msgs/SoundActionFeedback.h"

namespace pal_interaction_msgs
{

  class SoundAction : public ros::Msg
  {
    public:
      typedef pal_interaction_msgs::SoundActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef pal_interaction_msgs::SoundActionResult _action_result_type;
      _action_result_type action_result;
      typedef pal_interaction_msgs::SoundActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    SoundAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/SoundAction"; };
    const char * getMD5(){ return "8f204dc713899e4882f25f874e54b05b"; };

  };

}
#endif