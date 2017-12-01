#ifndef _ROS_pal_vision_msgs_LegDetections_h
#define _ROS_pal_vision_msgs_LegDetections_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace pal_vision_msgs
{

  class LegDetections : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t position3D_length;
      typedef geometry_msgs::Point _position3D_type;
      _position3D_type st_position3D;
      _position3D_type * position3D;

    LegDetections():
      header(),
      position3D_length(0), position3D(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->position3D_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position3D_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->position3D_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->position3D_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position3D_length);
      for( uint32_t i = 0; i < position3D_length; i++){
      offset += this->position3D[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t position3D_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      position3D_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      position3D_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      position3D_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->position3D_length);
      if(position3D_lengthT > position3D_length)
        this->position3D = (geometry_msgs::Point*)realloc(this->position3D, position3D_lengthT * sizeof(geometry_msgs::Point));
      position3D_length = position3D_lengthT;
      for( uint32_t i = 0; i < position3D_length; i++){
      offset += this->st_position3D.deserialize(inbuffer + offset);
        memcpy( &(this->position3D[i]), &(this->st_position3D), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "pal_vision_msgs/LegDetections"; };
    const char * getMD5(){ return "817c989208cff6eff51aae475bf50d0f"; };

  };

}
#endif