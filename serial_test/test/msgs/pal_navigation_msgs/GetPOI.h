#ifndef _ROS_SERVICE_GetPOI_h
#define _ROS_SERVICE_GetPOI_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_navigation_msgs/POI.h"

namespace pal_navigation_msgs
{

static const char GETPOI[] = "pal_navigation_msgs/GetPOI";

  class GetPOIRequest : public ros::Msg
  {
    public:

    GetPOIRequest()
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

    const char * getType(){ return GETPOI; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetPOIResponse : public ros::Msg
  {
    public:
      typedef pal_navigation_msgs::POI _poi_type;
      _poi_type poi;

    GetPOIResponse():
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

    const char * getType(){ return GETPOI; };
    const char * getMD5(){ return "f0a8811f1068c7b1269d9e58c608681f"; };

  };

  class GetPOI {
    public:
    typedef GetPOIRequest Request;
    typedef GetPOIResponse Response;
  };

}
#endif
