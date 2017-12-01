#ifndef _ROS_pal_navigation_msgs_GoToGoal_h
#define _ROS_pal_navigation_msgs_GoToGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace pal_navigation_msgs
{

  class GoToGoal : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _target_pose_type;
      _target_pose_type target_pose;

    GoToGoal():
      target_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->target_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->target_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/GoToGoal"; };
    const char * getMD5(){ return "257d089627d7eb7136c24d3593d05a16"; };

  };

}
#endif