#ifndef _ROS_pal_visual_localization_msgs_VisualLocAddPlaceAction_h
#define _ROS_pal_visual_localization_msgs_VisualLocAddPlaceAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_visual_localization_msgs/VisualLocAddPlaceActionGoal.h"
#include "pal_visual_localization_msgs/VisualLocAddPlaceActionResult.h"
#include "pal_visual_localization_msgs/VisualLocAddPlaceActionFeedback.h"

namespace pal_visual_localization_msgs
{

  class VisualLocAddPlaceAction : public ros::Msg
  {
    public:
      typedef pal_visual_localization_msgs::VisualLocAddPlaceActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef pal_visual_localization_msgs::VisualLocAddPlaceActionResult _action_result_type;
      _action_result_type action_result;
      typedef pal_visual_localization_msgs::VisualLocAddPlaceActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    VisualLocAddPlaceAction():
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

    const char * getType(){ return "pal_visual_localization_msgs/VisualLocAddPlaceAction"; };
    const char * getMD5(){ return "9ab27ece3afb2d2cde471bd3fa387d8d"; };

  };

}
#endif