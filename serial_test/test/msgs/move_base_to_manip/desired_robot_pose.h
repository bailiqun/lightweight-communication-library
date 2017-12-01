#ifndef _ROS_SERVICE_desired_robot_pose_h
#define _ROS_SERVICE_desired_robot_pose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace move_base_to_manip
{

static const char DESIRED_ROBOT_POSE[] = "move_base_to_manip/desired_robot_pose";

  class desired_robot_poseRequest : public ros::Msg
  {
    public:
      typedef bool _shutdown_service_type;
      _shutdown_service_type shutdown_service;

    desired_robot_poseRequest():
      shutdown_service(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_shutdown_service;
      u_shutdown_service.real = this->shutdown_service;
      *(outbuffer + offset + 0) = (u_shutdown_service.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->shutdown_service);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_shutdown_service;
      u_shutdown_service.base = 0;
      u_shutdown_service.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->shutdown_service = u_shutdown_service.real;
      offset += sizeof(this->shutdown_service);
     return offset;
    }

    const char * getType(){ return DESIRED_ROBOT_POSE; };
    const char * getMD5(){ return "aebfd5f67ab9024314ad44738303dbcb"; };

  };

  class desired_robot_poseResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _desired_robot_pose_type;
      _desired_robot_pose_type desired_robot_pose;

    desired_robot_poseResponse():
      desired_robot_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->desired_robot_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->desired_robot_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return DESIRED_ROBOT_POSE; };
    const char * getMD5(){ return "18063b0279e5d055f64fb2a3c4b36089"; };

  };

  class desired_robot_pose {
    public:
    typedef desired_robot_poseRequest Request;
    typedef desired_robot_poseResponse Response;
  };

}
#endif
