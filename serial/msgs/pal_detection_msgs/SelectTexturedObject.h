#ifndef _ROS_SERVICE_SelectTexturedObject_h
#define _ROS_SERVICE_SelectTexturedObject_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_detection_msgs
{

static const char SELECTTEXTUREDOBJECT[] = "pal_detection_msgs/SelectTexturedObject";

  class SelectTexturedObjectRequest : public ros::Msg
  {
    public:
      typedef const char* _imageFullPathFileName_type;
      _imageFullPathFileName_type imageFullPathFileName;
      typedef float _width_type;
      _width_type width;
      typedef float _height_type;
      _height_type height;

    SelectTexturedObjectRequest():
      imageFullPathFileName(""),
      width(0),
      height(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_imageFullPathFileName = strlen(this->imageFullPathFileName);
      varToArr(outbuffer + offset, length_imageFullPathFileName);
      offset += 4;
      memcpy(outbuffer + offset, this->imageFullPathFileName, length_imageFullPathFileName);
      offset += length_imageFullPathFileName;
      offset += serializeAvrFloat64(outbuffer + offset, this->width);
      offset += serializeAvrFloat64(outbuffer + offset, this->height);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_imageFullPathFileName;
      arrToVar(length_imageFullPathFileName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_imageFullPathFileName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_imageFullPathFileName-1]=0;
      this->imageFullPathFileName = (char *)(inbuffer + offset-1);
      offset += length_imageFullPathFileName;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->width));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->height));
     return offset;
    }

    const char * getType(){ return SELECTTEXTUREDOBJECT; };
    const char * getMD5(){ return "9e19a1b55ded74005b343f07cfe126b1"; };

  };

  class SelectTexturedObjectResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    SelectTexturedObjectResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return SELECTTEXTUREDOBJECT; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class SelectTexturedObject {
    public:
    typedef SelectTexturedObjectRequest Request;
    typedef SelectTexturedObjectResponse Response;
  };

}
#endif
