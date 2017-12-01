#ifndef _ROS_pal_walking_msgs_WalkingStatus_h
#define _ROS_pal_walking_msgs_WalkingStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"

namespace pal_walking_msgs
{

  class WalkingStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Pose _hip_reference_pose_type;
      _hip_reference_pose_type hip_reference_pose;
      geometry_msgs::Pose foot_reference_pose[2];
      typedef geometry_msgs::Point _zmp_reference_type;
      _zmp_reference_type zmp_reference;

    WalkingStatus():
      header(),
      hip_reference_pose(),
      foot_reference_pose(),
      zmp_reference()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->hip_reference_pose.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      offset += this->foot_reference_pose[i].serialize(outbuffer + offset);
      }
      offset += this->zmp_reference.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->hip_reference_pose.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      offset += this->foot_reference_pose[i].deserialize(inbuffer + offset);
      }
      offset += this->zmp_reference.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_walking_msgs/WalkingStatus"; };
    const char * getMD5(){ return "86de80b808fb27b3f11d218fa8d1c16e"; };

  };

}
#endif