#ifndef _ROS_SERVICE_AddTexturedObject_h
#define _ROS_SERVICE_AddTexturedObject_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"

namespace pal_detection_msgs
{

static const char ADDTEXTUREDOBJECT[] = "pal_detection_msgs/AddTexturedObject";

  class AddTexturedObjectRequest : public ros::Msg
  {
    public:
      typedef sensor_msgs::Image _img_type;
      _img_type img;
      typedef const char* _fullPathFileName_type;
      _fullPathFileName_type fullPathFileName;

    AddTexturedObjectRequest():
      img(),
      fullPathFileName("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->img.serialize(outbuffer + offset);
      uint32_t length_fullPathFileName = strlen(this->fullPathFileName);
      varToArr(outbuffer + offset, length_fullPathFileName);
      offset += 4;
      memcpy(outbuffer + offset, this->fullPathFileName, length_fullPathFileName);
      offset += length_fullPathFileName;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->img.deserialize(inbuffer + offset);
      uint32_t length_fullPathFileName;
      arrToVar(length_fullPathFileName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_fullPathFileName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_fullPathFileName-1]=0;
      this->fullPathFileName = (char *)(inbuffer + offset-1);
      offset += length_fullPathFileName;
     return offset;
    }

    const char * getType(){ return ADDTEXTUREDOBJECT; };
    const char * getMD5(){ return "0f96af0a8a35c0ce1d024a65fb87b554"; };

  };

  class AddTexturedObjectResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    AddTexturedObjectResponse():
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

    const char * getType(){ return ADDTEXTUREDOBJECT; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class AddTexturedObject {
    public:
    typedef AddTexturedObjectRequest Request;
    typedef AddTexturedObjectResponse Response;
  };

}
#endif
