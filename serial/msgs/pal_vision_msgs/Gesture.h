#ifndef _ROS_pal_vision_msgs_Gesture_h
#define _ROS_pal_vision_msgs_Gesture_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace pal_vision_msgs
{

  class Gesture : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _gestureId_type;
      _gestureId_type gestureId;
      typedef geometry_msgs::Point _position3D_type;
      _position3D_type position3D;

    Gesture():
      header(),
      gestureId(""),
      position3D()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_gestureId = strlen(this->gestureId);
      varToArr(outbuffer + offset, length_gestureId);
      offset += 4;
      memcpy(outbuffer + offset, this->gestureId, length_gestureId);
      offset += length_gestureId;
      offset += this->position3D.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_gestureId;
      arrToVar(length_gestureId, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gestureId; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gestureId-1]=0;
      this->gestureId = (char *)(inbuffer + offset-1);
      offset += length_gestureId;
      offset += this->position3D.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_vision_msgs/Gesture"; };
    const char * getMD5(){ return "1bc7e8240ed437c7df9ff2c69342d63a"; };

  };

}
#endif