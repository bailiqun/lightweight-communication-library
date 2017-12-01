#ifndef _ROS_pal_navigation_msgs_PolarReadingScan_h
#define _ROS_pal_navigation_msgs_PolarReadingScan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pal_navigation_msgs/PolarReading.h"

namespace pal_navigation_msgs
{

  class PolarReadingScan : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t readings_length;
      typedef pal_navigation_msgs::PolarReading _readings_type;
      _readings_type st_readings;
      _readings_type * readings;

    PolarReadingScan():
      header(),
      readings_length(0), readings(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->readings_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->readings_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->readings_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->readings_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->readings_length);
      for( uint32_t i = 0; i < readings_length; i++){
      offset += this->readings[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t readings_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      readings_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      readings_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      readings_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->readings_length);
      if(readings_lengthT > readings_length)
        this->readings = (pal_navigation_msgs::PolarReading*)realloc(this->readings, readings_lengthT * sizeof(pal_navigation_msgs::PolarReading));
      readings_length = readings_lengthT;
      for( uint32_t i = 0; i < readings_length; i++){
      offset += this->st_readings.deserialize(inbuffer + offset);
        memcpy( &(this->readings[i]), &(this->st_readings), sizeof(pal_navigation_msgs::PolarReading));
      }
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/PolarReadingScan"; };
    const char * getMD5(){ return "31bf8adf3389c9066eb83f63abcbe26f"; };

  };

}
#endif