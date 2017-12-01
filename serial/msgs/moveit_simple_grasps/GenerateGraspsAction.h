#ifndef _ROS_moveit_simple_grasps_GenerateGraspsAction_h
#define _ROS_moveit_simple_grasps_GenerateGraspsAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_simple_grasps/GenerateGraspsActionGoal.h"
#include "moveit_simple_grasps/GenerateGraspsActionResult.h"
#include "moveit_simple_grasps/GenerateGraspsActionFeedback.h"

namespace moveit_simple_grasps
{

  class GenerateGraspsAction : public ros::Msg
  {
    public:
      typedef moveit_simple_grasps::GenerateGraspsActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef moveit_simple_grasps::GenerateGraspsActionResult _action_result_type;
      _action_result_type action_result;
      typedef moveit_simple_grasps::GenerateGraspsActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    GenerateGraspsAction():
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

    const char * getType(){ return "moveit_simple_grasps/GenerateGraspsAction"; };
    const char * getMD5(){ return "c6a4a26da55f3310edbc8a5586b98c78"; };

  };

}
#endif