#ifndef _ROS_pal_vision_msgs_FaceDetection_h
#define _ROS_pal_vision_msgs_FaceDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "pal_vision_msgs/Rectangle.h"

namespace pal_vision_msgs
{

  class FaceDetection : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _position3D_type;
      _position3D_type position3D;
      typedef pal_vision_msgs::Rectangle _imageBoundingBox_type;
      _imageBoundingBox_type imageBoundingBox;
      uint32_t hog_length;
      typedef float _hog_type;
      _hog_type st_hog;
      _hog_type * hog;

    FaceDetection():
      position3D(),
      imageBoundingBox(),
      hog_length(0), hog(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->position3D.serialize(outbuffer + offset);
      offset += this->imageBoundingBox.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->hog_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hog_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hog_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hog_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hog_length);
      for( uint32_t i = 0; i < hog_length; i++){
      union {
        float real;
        uint32_t base;
      } u_hogi;
      u_hogi.real = this->hog[i];
      *(outbuffer + offset + 0) = (u_hogi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hogi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hogi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hogi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hog[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->position3D.deserialize(inbuffer + offset);
      offset += this->imageBoundingBox.deserialize(inbuffer + offset);
      uint32_t hog_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      hog_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      hog_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      hog_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->hog_length);
      if(hog_lengthT > hog_length)
        this->hog = (float*)realloc(this->hog, hog_lengthT * sizeof(float));
      hog_length = hog_lengthT;
      for( uint32_t i = 0; i < hog_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_hog;
      u_st_hog.base = 0;
      u_st_hog.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_hog.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_hog.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_hog.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_hog = u_st_hog.real;
      offset += sizeof(this->st_hog);
        memcpy( &(this->hog[i]), &(this->st_hog), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "pal_vision_msgs/FaceDetection"; };
    const char * getMD5(){ return "bf1d543fd0ed58f92521046e9c5f942a"; };

  };

}
#endif