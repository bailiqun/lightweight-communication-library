#ifndef _ROS_SERVICE_FaceTrackingStop_h
#define _ROS_SERVICE_FaceTrackingStop_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_vision_msgs
{

static const char FACETRACKINGSTOP[] = "pal_vision_msgs/FaceTrackingStop";

  class FaceTrackingStopRequest : public ros::Msg
  {
    public:

    FaceTrackingStopRequest()
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

    const char * getType(){ return FACETRACKINGSTOP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class FaceTrackingStopResponse : public ros::Msg
  {
    public:

    FaceTrackingStopResponse()
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

    const char * getType(){ return FACETRACKINGSTOP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class FaceTrackingStop {
    public:
    typedef FaceTrackingStopRequest Request;
    typedef FaceTrackingStopResponse Response;
  };

}
#endif
