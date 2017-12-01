#ifndef _ROS_pal_device_msgs_LedGroup_h
#define _ROS_pal_device_msgs_LedGroup_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_device_msgs
{

  class LedGroup : public ros::Msg
  {
    public:
      typedef uint32_t _ledMask_type;
      _ledMask_type ledMask;
      enum { LEFT_EAR =  1 };
      enum { RIGHT_EAR =  2 };

    LedGroup():
      ledMask(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ledMask >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ledMask >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ledMask >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ledMask >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ledMask);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->ledMask =  ((uint32_t) (*(inbuffer + offset)));
      this->ledMask |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ledMask |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->ledMask |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->ledMask);
     return offset;
    }

    const char * getType(){ return "pal_device_msgs/LedGroup"; };
    const char * getMD5(){ return "a87b0156a2b27c0d0853663fb5884fe4"; };

  };

}
#endif