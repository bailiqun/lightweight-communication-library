#ifndef _ROS_pal_common_msgs_EmptyGoal_h
#define _ROS_pal_common_msgs_EmptyGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_common_msgs
{

  class EmptyGoal : public ros::Msg
  {
    public:

    EmptyGoal()
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

    const char * getType(){ return "pal_common_msgs/EmptyGoal"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif