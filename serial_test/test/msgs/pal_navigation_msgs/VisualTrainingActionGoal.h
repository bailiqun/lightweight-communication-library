#ifndef _ROS_pal_navigation_msgs_VisualTrainingActionGoal_h
#define _ROS_pal_navigation_msgs_VisualTrainingActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "pal_navigation_msgs/VisualTrainingGoal.h"

namespace pal_navigation_msgs
{

  class VisualTrainingActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef pal_navigation_msgs::VisualTrainingGoal _goal_type;
      _goal_type goal;

    VisualTrainingActionGoal():
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

    const char * getType(){ return "pal_navigation_msgs/VisualTrainingActionGoal"; };
    const char * getMD5(){ return "8b1077b36f655d1a278f06e98570335b"; };

  };

}
#endif