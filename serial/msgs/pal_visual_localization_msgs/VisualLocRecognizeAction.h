#ifndef _ROS_pal_visual_localization_msgs_VisualLocRecognizeAction_h
#define _ROS_pal_visual_localization_msgs_VisualLocRecognizeAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_visual_localization_msgs/VisualLocRecognizeActionGoal.h"
#include "pal_visual_localization_msgs/VisualLocRecognizeActionResult.h"
#include "pal_visual_localization_msgs/VisualLocRecognizeActionFeedback.h"

namespace pal_visual_localization_msgs
{

  class VisualLocRecognizeAction : public ros::Msg
  {
    public:
      typedef pal_visual_localization_msgs::VisualLocRecognizeActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef pal_visual_localization_msgs::VisualLocRecognizeActionResult _action_result_type;
      _action_result_type action_result;
      typedef pal_visual_localization_msgs::VisualLocRecognizeActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    VisualLocRecognizeAction():
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

    const char * getType(){ return "pal_visual_localization_msgs/VisualLocRecognizeAction"; };
    const char * getMD5(){ return "32838540444654e8e6d15b3145b36be2"; };

  };

}
#endif