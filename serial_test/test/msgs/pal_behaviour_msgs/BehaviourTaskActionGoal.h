#ifndef _ROS_pal_behaviour_msgs_BehaviourTaskActionGoal_h
#define _ROS_pal_behaviour_msgs_BehaviourTaskActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "pal_behaviour_msgs/BehaviourTaskGoal.h"

namespace pal_behaviour_msgs
{

  class BehaviourTaskActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef pal_behaviour_msgs::BehaviourTaskGoal _goal_type;
      _goal_type goal;

    BehaviourTaskActionGoal():
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

    const char * getType(){ return "pal_behaviour_msgs/BehaviourTaskActionGoal"; };
    const char * getMD5(){ return "9133f67f0b62bc067b5b8c68d3981686"; };

  };

}
#endif