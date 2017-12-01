#ifndef _ROS_pal_behaviour_msgs_PresentationAction_h
#define _ROS_pal_behaviour_msgs_PresentationAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_behaviour_msgs/PresentationActionGoal.h"
#include "pal_behaviour_msgs/PresentationActionResult.h"
#include "pal_behaviour_msgs/PresentationActionFeedback.h"

namespace pal_behaviour_msgs
{

  class PresentationAction : public ros::Msg
  {
    public:
      typedef pal_behaviour_msgs::PresentationActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef pal_behaviour_msgs::PresentationActionResult _action_result_type;
      _action_result_type action_result;
      typedef pal_behaviour_msgs::PresentationActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    PresentationAction():
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

    const char * getType(){ return "pal_behaviour_msgs/PresentationAction"; };
    const char * getMD5(){ return "63f60f48a3f16a733bd5e4982af38eb2"; };

  };

}
#endif