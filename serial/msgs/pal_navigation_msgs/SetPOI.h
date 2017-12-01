#ifndef _ROS_SERVICE_SetPOI_h
#define _ROS_SERVICE_SetPOI_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_navigation_msgs/POI.h"

namespace pal_navigation_msgs
{

static const char SETPOI[] = "pal_navigation_msgs/SetPOI";

  class SetPOIRequest : public ros::Msg
  {
    public:
      typedef pal_navigation_msgs::POI _poi_type;
      _poi_type poi;

    SetPOIRequest():
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

    const char * getType(){ return SETPOI; };
    const char * getMD5(){ return "f0a8811f1068c7b1269d9e58c608681f"; };

  };

  class SetPOIResponse : public ros::Msg
  {
    public:

    SetPOIResponse()
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

    const char * getType(){ return SETPOI; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetPOI {
    public:
    typedef SetPOIRequest Request;
    typedef SetPOIResponse Response;
  };

}
#endif
