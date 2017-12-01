#ifndef _ROS_pal_navigation_msgs_GoToPOIFeedback_h
#define _ROS_pal_navigation_msgs_GoToPOIFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace pal_navigation_msgs
{

  class GoToPOIFeedback : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _base_position_type;
      _base_position_type base_position;

    GoToPOIFeedback():
      base_position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->base_position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->base_position.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/GoToPOIFeedback"; };
    const char * getMD5(){ return "3fb824c456a757373a226f6d08071bf0"; };

  };

}
#endif