#ifndef _ROS_pal_vision_msgs_DetectedObject_h
#define _ROS_pal_vision_msgs_DetectedObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace pal_vision_msgs
{

  class DetectedObject : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Point _position3D_type;
      _position3D_type position3D;

    DetectedObject():
      header(),
      position3D()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->position3D.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->position3D.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_vision_msgs/DetectedObject"; };
    const char * getMD5(){ return "817c989208cff6eff51aae475bf50d0f"; };

  };

}
#endif