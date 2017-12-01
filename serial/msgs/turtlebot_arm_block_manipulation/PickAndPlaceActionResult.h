#ifndef _ROS_turtlebot_arm_block_manipulation_PickAndPlaceActionResult_h
#define _ROS_turtlebot_arm_block_manipulation_PickAndPlaceActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "turtlebot_arm_block_manipulation/PickAndPlaceResult.h"

namespace turtlebot_arm_block_manipulation
{

  class PickAndPlaceActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef turtlebot_arm_block_manipulation::PickAndPlaceResult _result_type;
      _result_type result;

    PickAndPlaceActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "turtlebot_arm_block_manipulation/PickAndPlaceActionResult"; };
    const char * getMD5(){ return "1eb06eeff08fa7ea874431638cb52332"; };

  };

}
#endif