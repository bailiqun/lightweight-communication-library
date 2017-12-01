#ifndef _ROS_SERVICE_SetSubMapFloor_h
#define _ROS_SERVICE_SetSubMapFloor_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

static const char SETSUBMAPFLOOR[] = "pal_navigation_msgs/SetSubMapFloor";

  class SetSubMapFloorRequest : public ros::Msg
  {
    public:
      typedef int8_t _index_type;
      _index_type index;
      typedef int8_t _floor_type;
      _floor_type floor;

    SetSubMapFloorRequest():
      index(0),
      floor(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_index;
      u_index.real = this->index;
      *(outbuffer + offset + 0) = (u_index.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->index);
      union {
        int8_t real;
        uint8_t base;
      } u_floor;
      u_floor.real = this->floor;
      *(outbuffer + offset + 0) = (u_floor.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->floor);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_index;
      u_index.base = 0;
      u_index.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->index = u_index.real;
      offset += sizeof(this->index);
      union {
        int8_t real;
        uint8_t base;
      } u_floor;
      u_floor.base = 0;
      u_floor.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->floor = u_floor.real;
      offset += sizeof(this->floor);
     return offset;
    }

    const char * getType(){ return SETSUBMAPFLOOR; };
    const char * getMD5(){ return "7bc38a6f54d12ca287533bb3a693ed06"; };

  };

  class SetSubMapFloorResponse : public ros::Msg
  {
    public:

    SetSubMapFloorResponse()
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

    const char * getType(){ return SETSUBMAPFLOOR; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetSubMapFloor {
    public:
    typedef SetSubMapFloorRequest Request;
    typedef SetSubMapFloorResponse Response;
  };

}
#endif
