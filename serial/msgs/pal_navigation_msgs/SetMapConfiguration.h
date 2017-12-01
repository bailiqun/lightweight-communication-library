#ifndef _ROS_SERVICE_SetMapConfiguration_h
#define _ROS_SERVICE_SetMapConfiguration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_navigation_msgs/MapConfiguration.h"

namespace pal_navigation_msgs
{

static const char SETMAPCONFIGURATION[] = "pal_navigation_msgs/SetMapConfiguration";

  class SetMapConfigurationRequest : public ros::Msg
  {
    public:
      typedef pal_navigation_msgs::MapConfiguration _map_config_type;
      _map_config_type map_config;

    SetMapConfigurationRequest():
      map_config()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->map_config.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->map_config.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETMAPCONFIGURATION; };
    const char * getMD5(){ return "03fc2970c7709c1aa00a0077b9478e6f"; };

  };

  class SetMapConfigurationResponse : public ros::Msg
  {
    public:

    SetMapConfigurationResponse()
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

    const char * getType(){ return SETMAPCONFIGURATION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetMapConfiguration {
    public:
    typedef SetMapConfigurationRequest Request;
    typedef SetMapConfigurationResponse Response;
  };

}
#endif
