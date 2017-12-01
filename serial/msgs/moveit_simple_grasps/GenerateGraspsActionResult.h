#ifndef _ROS_moveit_simple_grasps_GenerateGraspsActionResult_h
#define _ROS_moveit_simple_grasps_GenerateGraspsActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "moveit_simple_grasps/GenerateGraspsResult.h"

namespace moveit_simple_grasps
{

  class GenerateGraspsActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef moveit_simple_grasps::GenerateGraspsResult _result_type;
      _result_type result;

    GenerateGraspsActionResult():
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

    const char * getType(){ return "moveit_simple_grasps/GenerateGraspsActionResult"; };
    const char * getMD5(){ return "3e5cdae81cffa49b72e6fc3e16366194"; };

  };

}
#endif