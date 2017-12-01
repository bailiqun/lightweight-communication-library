#ifndef _ROS_SERVICE_FaceTrackingStart_h
#define _ROS_SERVICE_FaceTrackingStart_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_vision_msgs
{

static const char FACETRACKINGSTART[] = "pal_vision_msgs/FaceTrackingStart";

  class FaceTrackingStartRequest : public ros::Msg
  {
    public:

    FaceTrackingStartRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return FACETRACKINGSTART; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class FaceTrackingStartResponse : public ros::Msg
  {
    public:

    FaceTrackingStartResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return FACETRACKINGSTART; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class FaceTrackingStart {
    public:
    typedef FaceTrackingStartRequest Request;
    typedef FaceTrackingStartResponse Response;
  };

}
#endif
