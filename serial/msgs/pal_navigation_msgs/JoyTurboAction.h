#ifndef _ROS_pal_navigation_msgs_JoyTurboAction_h
#define _ROS_pal_navigation_msgs_JoyTurboAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_navigation_msgs/JoyTurboActionGoal.h"
#include "pal_navigation_msgs/JoyTurboActionResult.h"
#include "pal_navigation_msgs/JoyTurboActionFeedback.h"

namespace pal_navigation_msgs
{

  class JoyTurboAction : public ros::Msg
  {
    public:
      typedef pal_navigation_msgs::JoyTurboActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef pal_navigation_msgs::JoyTurboActionResult _action_result_type;
      _action_result_type action_result;
      typedef pal_navigation_msgs::JoyTurboActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    JoyTurboAction():
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

    const char * getType(){ return "pal_navigation_msgs/JoyTurboAction"; };
    const char * getMD5(){ return "d5a016b49f278075666fbc901debbd08"; };

  };

}
#endif