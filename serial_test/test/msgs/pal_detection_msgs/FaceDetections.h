#ifndef _ROS_pal_detection_msgs_FaceDetections_h
#define _ROS_pal_detection_msgs_FaceDetections_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pal_detection_msgs/FaceDetection.h"
#include "geometry_msgs/TransformStamped.h"

namespace pal_detection_msgs
{

  class FaceDetections : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t faces_length;
      typedef pal_detection_msgs::FaceDetection _faces_type;
      _faces_type st_faces;
      _faces_type * faces;
      typedef geometry_msgs::TransformStamped _camera_pose_type;
      _camera_pose_type camera_pose;

    FaceDetections():
      header(),
      faces_length(0), faces(NULL),
      camera_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->faces_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->faces_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->faces_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->faces_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->faces_length);
      for( uint32_t i = 0; i < faces_length; i++){
      offset += this->faces[i].serialize(outbuffer + offset);
      }
      offset += this->camera_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t faces_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      faces_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      faces_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      faces_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->faces_length);
      if(faces_lengthT > faces_length)
        this->faces = (pal_detection_msgs::FaceDetection*)realloc(this->faces, faces_lengthT * sizeof(pal_detection_msgs::FaceDetection));
      faces_length = faces_lengthT;
      for( uint32_t i = 0; i < faces_length; i++){
      offset += this->st_faces.deserialize(inbuffer + offset);
        memcpy( &(this->faces[i]), &(this->st_faces), sizeof(pal_detection_msgs::FaceDetection));
      }
      offset += this->camera_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_detection_msgs/FaceDetections"; };
    const char * getMD5(){ return "15793d06a28d1474a785b598600bb247"; };

  };

}
#endif