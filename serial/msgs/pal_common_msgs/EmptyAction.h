#ifndef _ROS_pal_common_msgs_EmptyAction_h
#define _ROS_pal_common_msgs_EmptyAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_common_msgs/EmptyActionGoal.h"
#include "pal_common_msgs/EmptyActionResult.h"
#include "pal_common_msgs/EmptyActionFeedback.h"

namespace pal_common_msgs
{

  class EmptyAction : public ros::Msg
  {
    public:
      typedef pal_common_msgs::EmptyActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef pal_common_msgs::EmptyActionResult _action_result_type;
      _action_result_type action_result;
      typedef pal_common_msgs::EmptyActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    EmptyAction():
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

    const char * getType(){ return "pal_common_msgs/EmptyAction"; };
    const char * getMD5(){ return "d5a016b49f278075666fbc901debbd08"; };

  };

}
#endif