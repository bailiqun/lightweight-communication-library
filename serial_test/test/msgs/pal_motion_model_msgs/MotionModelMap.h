#ifndef _ROS_pal_motion_model_msgs_MotionModelMap_h
#define _ROS_pal_motion_model_msgs_MotionModelMap_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "nav_msgs/MapMetaData.h"
#include "pal_motion_model_msgs/MotionModelList.h"

namespace pal_motion_model_msgs
{

  class MotionModelMap : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef nav_msgs::MapMetaData _info_type;
      _info_type info;
      uint32_t data_length;
      typedef pal_motion_model_msgs::MotionModelList _data_type;
      _data_type st_data;
      _data_type * data;

    MotionModelMap():
      header(),
      info(),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->info.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      offset += this->data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->info.deserialize(inbuffer + offset);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (pal_motion_model_msgs::MotionModelList*)realloc(this->data, data_lengthT * sizeof(pal_motion_model_msgs::MotionModelList));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      offset += this->st_data.deserialize(inbuffer + offset);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(pal_motion_model_msgs::MotionModelList));
      }
     return offset;
    }

    const char * getType(){ return "pal_motion_model_msgs/MotionModelMap"; };
    const char * getMD5(){ return "b6bcccd2088596e98ba83bc65b2b504e"; };

  };

}
#endif