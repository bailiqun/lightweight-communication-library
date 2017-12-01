#ifndef _ROS_turtlebot_arm_block_manipulation_InteractiveBlockManipulationActionFeedback_h
#define _ROS_turtlebot_arm_block_manipulation_InteractiveBlockManipulationActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "turtlebot_arm_block_manipulation/InteractiveBlockManipulationFeedback.h"

namespace turtlebot_arm_block_manipulation
{

  class InteractiveBlockManipulationActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef turtlebot_arm_block_manipulation::InteractiveBlockManipulationFeedback _feedback_type;
      _feedback_type feedback;

    InteractiveBlockManipulationActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "turtlebot_arm_block_manipulation/InteractiveBlockManipulationActionFeedback"; };
    const char * getMD5(){ return "aae20e09065c3809e8a8e87c4c8953fd"; };

  };

}
#endif