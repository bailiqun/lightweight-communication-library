#ifndef _ROS_pal_multirobot_msgs_WifiServiceDetection_h
#define _ROS_pal_multirobot_msgs_WifiServiceDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pal_multirobot_msgs
{

  class WifiServiceDetection : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _id_type;
      _id_type id;
      typedef int16_t _signal_type;
      _signal_type signal;

    WifiServiceDetection():
      header(),
      id(""),
      signal(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      union {
        int16_t real;
        uint16_t base;
      } u_signal;
      u_signal.real = this->signal;
      *(outbuffer + offset + 0) = (u_signal.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_signal.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->signal);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      union {
        int16_t real;
        uint16_t base;
      } u_signal;
      u_signal.base = 0;
      u_signal.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_signal.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->signal = u_signal.real;
      offset += sizeof(this->signal);
     return offset;
    }

    const char * getType(){ return "pal_multirobot_msgs/WifiServiceDetection"; };
    const char * getMD5(){ return "a2e54cd74d6654020f51ebb6558225d3"; };

  };

}
#endif