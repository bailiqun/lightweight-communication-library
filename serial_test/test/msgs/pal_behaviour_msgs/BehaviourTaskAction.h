#ifndef _ROS_pal_behaviour_msgs_BehaviourTaskAction_h
#define _ROS_pal_behaviour_msgs_BehaviourTaskAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_behaviour_msgs/BehaviourTaskActionGoal.h"
#include "pal_behaviour_msgs/BehaviourTaskActionResult.h"
#include "pal_behaviour_msgs/BehaviourTaskActionFeedback.h"

namespace pal_behaviour_msgs
{

  class BehaviourTaskAction : public ros::Msg
  {
    public:
      typedef pal_behaviour_msgs::BehaviourTaskActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef pal_behaviour_msgs::BehaviourTaskActionResult _action_result_type;
      _action_result_type action_result;
      typedef pal_behaviour_msgs::BehaviourTaskActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    BehaviourTaskAction():
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

    const char * getType(){ return "pal_behaviour_msgs/BehaviourTaskAction"; };
    const char * getMD5(){ return "5d919a3d8a48d1c701d6fe0123779cb7"; };

  };

}
#endif