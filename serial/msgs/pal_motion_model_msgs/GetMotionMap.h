#ifndef _ROS_SERVICE_GetMotionMap_h
#define _ROS_SERVICE_GetMotionMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_motion_model_msgs/MotionModelMap.h"

namespace pal_motion_model_msgs
{

static const char GETMOTIONMAP[] = "pal_motion_model_msgs/GetMotionMap";

  class GetMotionMapRequest : public ros::Msg
  {
    public:

    GetMotionMapRequest()
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

    const char * getType(){ return GETMOTIONMAP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetMotionMapResponse : public ros::Msg
  {
    public:
      typedef pal_motion_model_msgs::MotionModelMap _map_type;
      _map_type map;

    GetMotionMapResponse():
      map()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->map.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->map.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETMOTIONMAP; };
    const char * getMD5(){ return "ff508f86b1d484eed7ca1c596036d1bf"; };

  };

  class GetMotionMap {
    public:
    typedef GetMotionMapRequest Request;
    typedef GetMotionMapResponse Response;
  };

}
#endif
