#ifndef _ROS_SERVICE_GetNodes_h
#define _ROS_SERVICE_GetNodes_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

static const char GETNODES[] = "pal_navigation_msgs/GetNodes";

  class GetNodesRequest : public ros::Msg
  {
    public:

    GetNodesRequest()
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

    const char * getType(){ return GETNODES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetNodesResponse : public ros::Msg
  {
    public:
      typedef int8_t _node_type;
      _node_type node;
      typedef int8_t _totPOI_type;
      _totPOI_type totPOI;

    GetNodesResponse():
      node(0),
      totPOI(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_node;
      u_node.real = this->node;
      *(outbuffer + offset + 0) = (u_node.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->node);
      union {
        int8_t real;
        uint8_t base;
      } u_totPOI;
      u_totPOI.real = this->totPOI;
      *(outbuffer + offset + 0) = (u_totPOI.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->totPOI);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_node;
      u_node.base = 0;
      u_node.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->node = u_node.real;
      offset += sizeof(this->node);
      union {
        int8_t real;
        uint8_t base;
      } u_totPOI;
      u_totPOI.base = 0;
      u_totPOI.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->totPOI = u_totPOI.real;
      offset += sizeof(this->totPOI);
     return offset;
    }

    const char * getType(){ return GETNODES; };
    const char * getMD5(){ return "b6466ea7c9ababd4e7ce8d08d651a271"; };

  };

  class GetNodes {
    public:
    typedef GetNodesRequest Request;
    typedef GetNodesResponse Response;
  };

}
#endif
