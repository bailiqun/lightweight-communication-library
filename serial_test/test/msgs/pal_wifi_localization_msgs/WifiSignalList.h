#ifndef _ROS_pal_wifi_localization_msgs_WifiSignalList_h
#define _ROS_pal_wifi_localization_msgs_WifiSignalList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_wifi_localization_msgs/WifiSignal.h"
#include "ros/time.h"

namespace pal_wifi_localization_msgs
{

  class WifiSignalList : public ros::Msg
  {
    public:
      uint32_t networks_length;
      typedef pal_wifi_localization_msgs::WifiSignal _networks_type;
      _networks_type st_networks;
      _networks_type * networks;
      typedef ros::Time _start_time_type;
      _start_time_type start_time;
      typedef ros::Time _end_time_type;
      _end_time_type end_time;

    WifiSignalList():
      networks_length(0), networks(NULL),
      start_time(),
      end_time()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->networks_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->networks_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->networks_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->networks_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->networks_length);
      for( uint32_t i = 0; i < networks_length; i++){
      offset += this->networks[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->start_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_time.sec);
      *(outbuffer + offset + 0) = (this->start_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_time.nsec);
      *(outbuffer + offset + 0) = (this->end_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->end_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->end_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->end_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end_time.sec);
      *(outbuffer + offset + 0) = (this->end_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->end_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->end_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->end_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end_time.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t networks_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      networks_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      networks_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      networks_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->networks_length);
      if(networks_lengthT > networks_length)
        this->networks = (pal_wifi_localization_msgs::WifiSignal*)realloc(this->networks, networks_lengthT * sizeof(pal_wifi_localization_msgs::WifiSignal));
      networks_length = networks_lengthT;
      for( uint32_t i = 0; i < networks_length; i++){
      offset += this->st_networks.deserialize(inbuffer + offset);
        memcpy( &(this->networks[i]), &(this->st_networks), sizeof(pal_wifi_localization_msgs::WifiSignal));
      }
      this->start_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->start_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start_time.sec);
      this->start_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->start_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start_time.nsec);
      this->end_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->end_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->end_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->end_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->end_time.sec);
      this->end_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->end_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->end_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->end_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->end_time.nsec);
     return offset;
    }

    const char * getType(){ return "pal_wifi_localization_msgs/WifiSignalList"; };
    const char * getMD5(){ return "7e7cf55cfdfea3ed97058d9184eceb4c"; };

  };

}
#endif