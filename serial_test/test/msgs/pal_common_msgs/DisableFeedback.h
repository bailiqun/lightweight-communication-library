#ifndef _ROS_pal_common_msgs_DisableFeedback_h
#define _ROS_pal_common_msgs_DisableFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_common_msgs
{

  class DisableFeedback : public ros::Msg
  {
    public:

    DisableFeedback()
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

    const char * getType(){ return "pal_common_msgs/DisableFeedback"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif