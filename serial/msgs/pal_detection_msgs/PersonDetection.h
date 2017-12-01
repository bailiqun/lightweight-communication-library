#ifndef _ROS_pal_detection_msgs_PersonDetection_h
#define _ROS_pal_detection_msgs_PersonDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_detection_msgs/Detection2d.h"
#include "pal_detection_msgs/FaceDetection.h"
#include "pal_detection_msgs/LegDetections.h"
#include "geometry_msgs/PointStamped.h"

namespace pal_detection_msgs
{

  class PersonDetection : public ros::Msg
  {
    public:
      typedef pal_detection_msgs::Detection2d _full_body_type;
      _full_body_type full_body;
      typedef pal_detection_msgs::FaceDetection _face_type;
      _face_type face;
      typedef pal_detection_msgs::LegDetections _legs_type;
      _legs_type legs;
      typedef geometry_msgs::PointStamped _position3D_type;
      _position3D_type position3D;

    PersonDetection():
      full_body(),
      face(),
      legs(),
      position3D()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->full_body.serialize(outbuffer + offset);
      offset += this->face.serialize(outbuffer + offset);
      offset += this->legs.serialize(outbuffer + offset);
      offset += this->position3D.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->full_body.deserialize(inbuffer + offset);
      offset += this->face.deserialize(inbuffer + offset);
      offset += this->legs.deserialize(inbuffer + offset);
      offset += this->position3D.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_detection_msgs/PersonDetection"; };
    const char * getMD5(){ return "348d9a2450d9fe1842079b742c10982b"; };

  };

}
#endif