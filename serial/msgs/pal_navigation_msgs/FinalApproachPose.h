#ifndef _ROS_SERVICE_FinalApproachPose_h
#define _ROS_SERVICE_FinalApproachPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "std_msgs/Bool.h"

namespace pal_navigation_msgs
{

static const char FINALAPPROACHPOSE[] = "pal_navigation_msgs/FinalApproachPose";

  class FinalApproachPoseRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;

    FinalApproachPoseRequest():
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return FINALAPPROACHPOSE; };
    const char * getMD5(){ return "f192399f711a48924df9a394d37edd67"; };

  };

  class FinalApproachPoseResponse : public ros::Msg
  {
    public:
      typedef std_msgs::Bool _done_type;
      _done_type done;

    FinalApproachPoseResponse():
      done()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->done.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->done.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return FINALAPPROACHPOSE; };
    const char * getMD5(){ return "1c236c9790b7f5f3c3164ceb3563eae0"; };

  };

  class FinalApproachPose {
    public:
    typedef FinalApproachPoseRequest Request;
    typedef FinalApproachPoseResponse Response;
  };

}
#endif
