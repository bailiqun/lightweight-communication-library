#ifndef _ROS_pal_detection_msgs_Detections2d_h
#define _ROS_pal_detection_msgs_Detections2d_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pal_detection_msgs/Detection2d.h"
#include "geometry_msgs/TransformStamped.h"

namespace pal_detection_msgs
{

  class Detections2d : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t detections_length;
      typedef pal_detection_msgs::Detection2d _detections_type;
      _detections_type st_detections;
      _detections_type * detections;
      typedef geometry_msgs::TransformStamped _camera_pose_type;
      _camera_pose_type camera_pose;

    Detections2d():
      header(),
      detections_length(0), detections(NULL),
      camera_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->detections_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->detections_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->detections_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->detections_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detections_length);
      for( uint32_t i = 0; i < detections_length; i++){
      offset += this->detections[i].serialize(outbuffer + offset);
      }
      offset += this->camera_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t detections_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->detections_length);
      if(detections_lengthT > detections_length)
        this->detections = (pal_detection_msgs::Detection2d*)realloc(this->detections, detections_lengthT * sizeof(pal_detection_msgs::Detection2d));
      detections_length = detections_lengthT;
      for( uint32_t i = 0; i < detections_length; i++){
      offset += this->st_detections.deserialize(inbuffer + offset);
        memcpy( &(this->detections[i]), &(this->st_detections), sizeof(pal_detection_msgs::Detection2d));
      }
      offset += this->camera_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_detection_msgs/Detections2d"; };
    const char * getMD5(){ return "508e4e5ac7930673178d3ead64ba3f4b"; };

  };

}
#endif