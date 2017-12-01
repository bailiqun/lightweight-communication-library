#ifndef _ROS_pal_wifi_localization_msgs_WifiSignalMap_h
#define _ROS_pal_wifi_localization_msgs_WifiSignalMap_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "nav_msgs/MapMetaData.h"
#include "pal_wifi_localization_msgs/WifiSignalList.h"

namespace pal_wifi_localization_msgs
{

  class WifiSignalMap : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef nav_msgs::MapMetaData _info_type;
      _info_type info;
      typedef uint32_t _sectors_type;
      _sectors_type sectors;
      uint32_t data_length;
      typedef pal_wifi_localization_msgs::WifiSignalList _data_type;
      _data_type st_data;
      _data_type * data;

    WifiSignalMap():
      header(),
      info(),
      sectors(0),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->info.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->sectors >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sectors >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sectors >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sectors >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sectors);
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
      this->sectors =  ((uint32_t) (*(inbuffer + offset)));
      this->sectors |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sectors |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sectors |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sectors);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (pal_wifi_localization_msgs::WifiSignalList*)realloc(this->data, data_lengthT * sizeof(pal_wifi_localization_msgs::WifiSignalList));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      offset += this->st_data.deserialize(inbuffer + offset);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(pal_wifi_localization_msgs::WifiSignalList));
      }
     return offset;
    }

    const char * getType(){ return "pal_wifi_localization_msgs/WifiSignalMap"; };
    const char * getMD5(){ return "5083f884f6a479bea709736f39c4131f"; };

  };

}
#endif