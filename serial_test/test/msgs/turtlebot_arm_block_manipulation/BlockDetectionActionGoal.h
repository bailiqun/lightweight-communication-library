#ifndef _ROS_turtlebot_arm_block_manipulation_BlockDetectionActionGoal_h
#define _ROS_turtlebot_arm_block_manipulation_BlockDetectionActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "turtlebot_arm_block_manipulation/BlockDetectionGoal.h"

namespace turtlebot_arm_block_manipulation
{

  class BlockDetectionActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef turtlebot_arm_block_manipulation::BlockDetectionGoal _goal_type;
      _goal_type goal;

    BlockDetectionActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "turtlebot_arm_block_manipulation/BlockDetectionActionGoal"; };
    const char * getMD5(){ return "1ebf2c1d94729e15f30169d8857420df"; };

  };

}
#endif