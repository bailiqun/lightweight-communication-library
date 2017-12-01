#ifndef _ROS_pal_control_msgs_MotionManagerAction_h
#define _ROS_pal_control_msgs_MotionManagerAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_control_msgs/MotionManagerActionGoal.h"
#include "pal_control_msgs/MotionManagerActionResult.h"
#include "pal_control_msgs/MotionManagerActionFeedback.h"

namespace pal_control_msgs
{

  class MotionManagerAction : public ros::Msg
  {
    public:
      typedef pal_control_msgs::MotionManagerActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef pal_control_msgs::MotionManagerActionResult _action_result_type;
      _action_result_type action_result;
      typedef pal_control_msgs::MotionManagerActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    MotionManagerAction():
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

    const char * getType(){ return "pal_control_msgs/MotionManagerAction"; };
    const char * getMD5(){ return "42689d3bf9c1135e4da2202787f92626"; };

  };

}
#endif