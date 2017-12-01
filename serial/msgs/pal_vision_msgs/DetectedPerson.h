#ifndef _ROS_pal_vision_msgs_DetectedPerson_h
#define _ROS_pal_vision_msgs_DetectedPerson_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/ColorRGBA.h"
#include "geometry_msgs/Point.h"
#include "pal_vision_msgs/Rectangle.h"

namespace pal_vision_msgs
{

  class DetectedPerson : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int64_t _objectId_type;
      _objectId_type objectId;
      typedef std_msgs::ColorRGBA _boxColour_type;
      _boxColour_type boxColour;
      typedef float _confidence_type;
      _confidence_type confidence;
      typedef geometry_msgs::Point _position3D_type;
      _position3D_type position3D;
      typedef pal_vision_msgs::Rectangle _box_type;
      _box_type box;
      typedef pal_vision_msgs::Rectangle _faceBox_type;
      _faceBox_type faceBox;

    DetectedPerson():
      header(),
      objectId(0),
      boxColour(),
      confidence(0),
      position3D(),
      box(),
      faceBox()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_objectId;
      u_objectId.real = this->objectId;
      *(outbuffer + offset + 0) = (u_objectId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_objectId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_objectId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_objectId.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_objectId.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_objectId.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_objectId.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_objectId.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->objectId);
      offset += this->boxColour.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->confidence);
      offset += this->position3D.serialize(outbuffer + offset);
      offset += this->box.serialize(outbuffer + offset);
      offset += this->faceBox.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_objectId;
      u_objectId.base = 0;
      u_objectId.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_objectId.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_objectId.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_objectId.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_objectId.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_objectId.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_objectId.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_objectId.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->objectId = u_objectId.real;
      offset += sizeof(this->objectId);
      offset += this->boxColour.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->confidence));
      offset += this->position3D.deserialize(inbuffer + offset);
      offset += this->box.deserialize(inbuffer + offset);
      offset += this->faceBox.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_vision_msgs/DetectedPerson"; };
    const char * getMD5(){ return "f5d598391f8f6fb6645fe7d38b2e7101"; };

  };

}
#endif