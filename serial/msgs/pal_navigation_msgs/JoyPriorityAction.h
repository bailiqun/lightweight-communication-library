#ifndef _ROS_pal_navigation_msgs_JoyPriorityAction_h
#define _ROS_pal_navigation_msgs_JoyPriorityAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_navigation_msgs/JoyPriorityActionGoal.h"
#include "pal_navigation_msgs/JoyPriorityActionResult.h"
#include "pal_navigation_msgs/JoyPriorityActionFeedback.h"

namespace pal_navigation_msgs
{

  class JoyPriorityAction : public ros::Msg
  {
    public:
      typedef pal_navigation_msgs::JoyPriorityActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef pal_navigation_msgs::JoyPriorityActionResult _action_result_type;
      _action_result_type action_result;
      typedef pal_navigation_msgs::JoyPriorityActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    JoyPriorityAction():
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

    const char * getType(){ return "pal_navigation_msgs/JoyPriorityAction"; };
    const char * getMD5(){ return "d5a016b49f278075666fbc901debbd08"; };

  };

}
#endif