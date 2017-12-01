#ifndef _ROS_turtlebot_arm_block_manipulation_BlockDetectionAction_h
#define _ROS_turtlebot_arm_block_manipulation_BlockDetectionAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "turtlebot_arm_block_manipulation/BlockDetectionActionGoal.h"
#include "turtlebot_arm_block_manipulation/BlockDetectionActionResult.h"
#include "turtlebot_arm_block_manipulation/BlockDetectionActionFeedback.h"

namespace turtlebot_arm_block_manipulation
{

  class BlockDetectionAction : public ros::Msg
  {
    public:
      typedef turtlebot_arm_block_manipulation::BlockDetectionActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef turtlebot_arm_block_manipulation::BlockDetectionActionResult _action_result_type;
      _action_result_type action_result;
      typedef turtlebot_arm_block_manipulation::BlockDetectionActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    BlockDetectionAction():
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

    const char * getType(){ return "turtlebot_arm_block_manipulation/BlockDetectionAction"; };
    const char * getMD5(){ return "32b318b57a8d5ec852090b7f3b7885e0"; };

  };

}
#endif