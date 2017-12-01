#ifndef _ROS_SERVICE_FollowMeStop_h
#define _ROS_SERVICE_FollowMeStop_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_vision_msgs
{

static const char FOLLOWMESTOP[] = "pal_vision_msgs/FollowMeStop";

  class FollowMeStopRequest : public ros::Msg
  {
    public:

    FollowMeStopRequest()
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

    const char * getType(){ return FOLLOWMESTOP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class FollowMeStopResponse : public ros::Msg
  {
    public:

    FollowMeStopResponse()
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

    const char * getType(){ return FOLLOWMESTOP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class FollowMeStop {
    public:
    typedef FollowMeStopRequest Request;
    typedef FollowMeStopResponse Response;
  };

}
#endif
