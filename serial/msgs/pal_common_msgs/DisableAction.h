#ifndef _ROS_pal_common_msgs_DisableAction_h
#define _ROS_pal_common_msgs_DisableAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_common_msgs/DisableActionGoal.h"
#include "pal_common_msgs/DisableActionResult.h"
#include "pal_common_msgs/DisableActionFeedback.h"

namespace pal_common_msgs
{

  class DisableAction : public ros::Msg
  {
    public:
      typedef pal_common_msgs::DisableActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef pal_common_msgs::DisableActionResult _action_result_type;
      _action_result_type action_result;
      typedef pal_common_msgs::DisableActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    DisableAction():
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

    const char * getType(){ return "pal_common_msgs/DisableAction"; };
    const char * getMD5(){ return "f7cce8d83254ae8329a08eb10bcc1d92"; };

  };

}
#endif