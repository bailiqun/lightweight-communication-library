#ifndef _ROS_pal_navigation_msgs_GoToPOIGoal_h
#define _ROS_pal_navigation_msgs_GoToPOIGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace pal_navigation_msgs
{

  class GoToPOIGoal : public ros::Msg
  {
    public:
      typedef std_msgs::String _poi_type;
      _poi_type poi;

    GoToPOIGoal():
      poi()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->poi.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->poi.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/GoToPOIGoal"; };
    const char * getMD5(){ return "538be845cb53d7d128987a020f2801b8"; };

  };

}
#endif