#ifndef _ROS_pal_navigation_msgs_VisualTrainingAction_h
#define _ROS_pal_navigation_msgs_VisualTrainingAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_navigation_msgs/VisualTrainingActionGoal.h"
#include "pal_navigation_msgs/VisualTrainingActionResult.h"
#include "pal_navigation_msgs/VisualTrainingActionFeedback.h"

namespace pal_navigation_msgs
{

  class VisualTrainingAction : public ros::Msg
  {
    public:
      typedef pal_navigation_msgs::VisualTrainingActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef pal_navigation_msgs::VisualTrainingActionResult _action_result_type;
      _action_result_type action_result;
      typedef pal_navigation_msgs::VisualTrainingActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    VisualTrainingAction():
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

    const char * getType(){ return "pal_navigation_msgs/VisualTrainingAction"; };
    const char * getMD5(){ return "e4f61a9ec010e4c4596ca7372e044f24"; };

  };

}
#endif