#ifndef _ROS_pal_vision_msgs_HogDetection_h
#define _ROS_pal_vision_msgs_HogDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_vision_msgs/Rectangle.h"
#include "geometry_msgs/Vector3.h"
#include "std_msgs/ColorRGBA.h"

namespace pal_vision_msgs
{

  class HogDetection : public ros::Msg
  {
    public:
      typedef pal_vision_msgs::Rectangle _imageBoundingBox_type;
      _imageBoundingBox_type imageBoundingBox;
      typedef geometry_msgs::Vector3 _direction_type;
      _direction_type direction;
      uint32_t hog_length;
      typedef float _hog_type;
      _hog_type st_hog;
      _hog_type * hog;
      typedef std_msgs::ColorRGBA _principalEigenVectorRGB_type;
      _principalEigenVectorRGB_type principalEigenVectorRGB;
      uint32_t rgbClusterCenters_length;
      typedef std_msgs::ColorRGBA _rgbClusterCenters_type;
      _rgbClusterCenters_type st_rgbClusterCenters;
      _rgbClusterCenters_type * rgbClusterCenters;
      uint32_t rgbDescriptor1_length;
      typedef uint32_t _rgbDescriptor1_type;
      _rgbDescriptor1_type st_rgbDescriptor1;
      _rgbDescriptor1_type * rgbDescriptor1;
      uint32_t rgbDescriptor2_length;
      typedef uint32_t _rgbDescriptor2_type;
      _rgbDescriptor2_type st_rgbDescriptor2;
      _rgbDescriptor2_type * rgbDescriptor2;

    HogDetection():
      imageBoundingBox(),
      direction(),
      hog_length(0), hog(NULL),
      principalEigenVectorRGB(),
      rgbClusterCenters_length(0), rgbClusterCenters(NULL),
      rgbDescriptor1_length(0), rgbDescriptor1(NULL),
      rgbDescriptor2_length(0), rgbDescriptor2(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->imageBoundingBox.serialize(outbuffer + offset);
      offset += this->direction.serialize(outbuffer + offset);
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
      offset += this->principalEigenVectorRGB.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->rgbClusterCenters_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rgbClusterCenters_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rgbClusterCenters_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rgbClusterCenters_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rgbClusterCenters_length);
      for( uint32_t i = 0; i < rgbClusterCenters_length; i++){
      offset += this->rgbClusterCenters[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->rgbDescriptor1_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rgbDescriptor1_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rgbDescriptor1_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rgbDescriptor1_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rgbDescriptor1_length);
      for( uint32_t i = 0; i < rgbDescriptor1_length; i++){
      *(outbuffer + offset + 0) = (this->rgbDescriptor1[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rgbDescriptor1[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rgbDescriptor1[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rgbDescriptor1[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rgbDescriptor1[i]);
      }
      *(outbuffer + offset + 0) = (this->rgbDescriptor2_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rgbDescriptor2_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rgbDescriptor2_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rgbDescriptor2_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rgbDescriptor2_length);
      for( uint32_t i = 0; i < rgbDescriptor2_length; i++){
      *(outbuffer + offset + 0) = (this->rgbDescriptor2[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rgbDescriptor2[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rgbDescriptor2[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rgbDescriptor2[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rgbDescriptor2[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->imageBoundingBox.deserialize(inbuffer + offset);
      offset += this->direction.deserialize(inbuffer + offset);
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
      offset += this->principalEigenVectorRGB.deserialize(inbuffer + offset);
      uint32_t rgbClusterCenters_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      rgbClusterCenters_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      rgbClusterCenters_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      rgbClusterCenters_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->rgbClusterCenters_length);
      if(rgbClusterCenters_lengthT > rgbClusterCenters_length)
        this->rgbClusterCenters = (std_msgs::ColorRGBA*)realloc(this->rgbClusterCenters, rgbClusterCenters_lengthT * sizeof(std_msgs::ColorRGBA));
      rgbClusterCenters_length = rgbClusterCenters_lengthT;
      for( uint32_t i = 0; i < rgbClusterCenters_length; i++){
      offset += this->st_rgbClusterCenters.deserialize(inbuffer + offset);
        memcpy( &(this->rgbClusterCenters[i]), &(this->st_rgbClusterCenters), sizeof(std_msgs::ColorRGBA));
      }
      uint32_t rgbDescriptor1_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      rgbDescriptor1_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      rgbDescriptor1_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      rgbDescriptor1_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->rgbDescriptor1_length);
      if(rgbDescriptor1_lengthT > rgbDescriptor1_length)
        this->rgbDescriptor1 = (uint32_t*)realloc(this->rgbDescriptor1, rgbDescriptor1_lengthT * sizeof(uint32_t));
      rgbDescriptor1_length = rgbDescriptor1_lengthT;
      for( uint32_t i = 0; i < rgbDescriptor1_length; i++){
      this->st_rgbDescriptor1 =  ((uint32_t) (*(inbuffer + offset)));
      this->st_rgbDescriptor1 |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_rgbDescriptor1 |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_rgbDescriptor1 |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_rgbDescriptor1);
        memcpy( &(this->rgbDescriptor1[i]), &(this->st_rgbDescriptor1), sizeof(uint32_t));
      }
      uint32_t rgbDescriptor2_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      rgbDescriptor2_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      rgbDescriptor2_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      rgbDescriptor2_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->rgbDescriptor2_length);
      if(rgbDescriptor2_lengthT > rgbDescriptor2_length)
        this->rgbDescriptor2 = (uint32_t*)realloc(this->rgbDescriptor2, rgbDescriptor2_lengthT * sizeof(uint32_t));
      rgbDescriptor2_length = rgbDescriptor2_lengthT;
      for( uint32_t i = 0; i < rgbDescriptor2_length; i++){
      this->st_rgbDescriptor2 =  ((uint32_t) (*(inbuffer + offset)));
      this->st_rgbDescriptor2 |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_rgbDescriptor2 |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_rgbDescriptor2 |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_rgbDescriptor2);
        memcpy( &(this->rgbDescriptor2[i]), &(this->st_rgbDescriptor2), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return "pal_vision_msgs/HogDetection"; };
    const char * getMD5(){ return "33e1731149b6e078eff6e4b55c75f260"; };

  };

}
#endif