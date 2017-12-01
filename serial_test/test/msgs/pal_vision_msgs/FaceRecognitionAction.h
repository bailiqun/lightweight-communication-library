#ifndef _ROS_pal_vision_msgs_FaceRecognitionAction_h
#define _ROS_pal_vision_msgs_FaceRecognitionAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_vision_msgs/FaceRecognitionActionGoal.h"
#include "pal_vision_msgs/FaceRecognitionActionResult.h"
#include "pal_vision_msgs/FaceRecognitionActionFeedback.h"

namespace pal_vision_msgs
{

  class FaceRecognitionAction : public ros::Msg
  {
    public:
      typedef pal_vision_msgs::FaceRecognitionActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef pal_vision_msgs::FaceRecognitionActionResult _action_result_type;
      _action_result_type action_result;
      typedef pal_vision_msgs::FaceRecognitionActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    FaceRecognitionAction():
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

    const char * getType(){ return "pal_vision_msgs/FaceRecognitionAction"; };
    const char * getMD5(){ return "102b0392d6292ae2bbbc788be5a2bd52"; };

  };

}
#endif