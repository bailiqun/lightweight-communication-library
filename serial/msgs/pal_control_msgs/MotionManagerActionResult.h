#ifndef _ROS_pal_control_msgs_MotionManagerActionResult_h
#define _ROS_pal_control_msgs_MotionManagerActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "pal_control_msgs/MotionManagerResult.h"

namespace pal_control_msgs
{

  class MotionManagerActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef pal_control_msgs::MotionManagerResult _result_type;
      _result_type result;

    MotionManagerActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_control_msgs/MotionManagerActionResult"; };
    const char * getMD5(){ return "3fa2b15df3c07c71945669df816f357b"; };

  };

}
#endif