#ifndef _ROS_pal_navigation_msgs_VisualTrainingResult_h
#define _ROS_pal_navigation_msgs_VisualTrainingResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

  class VisualTrainingResult : public ros::Msg
  {
    public:

    VisualTrainingResult()
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

    const char * getType(){ return "pal_navigation_msgs/VisualTrainingResult"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif