#ifndef _ROS_pal_tablet_msgs_FunctionalityStatus_h
#define _ROS_pal_tablet_msgs_FunctionalityStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"

namespace pal_tablet_msgs
{

  class FunctionalityStatus : public ros::Msg
  {
    public:
      typedef std_msgs::String _errMessage_type;
      _errMessage_type errMessage;
      typedef std_msgs::Bool _errStatus_type;
      _errStatus_type errStatus;

    FunctionalityStatus():
      errMessage(),
      errStatus()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->errMessage.serialize(outbuffer + offset);
      offset += this->errStatus.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->errMessage.deserialize(inbuffer + offset);
      offset += this->errStatus.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_tablet_msgs/FunctionalityStatus"; };
    const char * getMD5(){ return "8a8da27b7dcd09b29d33e708966ece31"; };

  };

}
#endif