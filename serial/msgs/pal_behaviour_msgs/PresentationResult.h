#ifndef _ROS_pal_behaviour_msgs_PresentationResult_h
#define _ROS_pal_behaviour_msgs_PresentationResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_behaviour_msgs
{

  class PresentationResult : public ros::Msg
  {
    public:

    PresentationResult()
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

    const char * getType(){ return "pal_behaviour_msgs/PresentationResult"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif