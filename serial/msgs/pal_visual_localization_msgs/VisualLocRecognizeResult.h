#ifndef _ROS_pal_visual_localization_msgs_VisualLocRecognizeResult_h
#define _ROS_pal_visual_localization_msgs_VisualLocRecognizeResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"

namespace pal_visual_localization_msgs
{

  class VisualLocRecognizeResult : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef float _confidence_type;
      _confidence_type confidence;
      typedef geometry_msgs::PoseWithCovarianceStamped _estimatedPose_type;
      _estimatedPose_type estimatedPose;

    VisualLocRecognizeResult():
      success(0),
      confidence(0),
      estimatedPose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      offset += serializeAvrFloat64(outbuffer + offset, this->confidence);
      offset += this->estimatedPose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->confidence));
      offset += this->estimatedPose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_visual_localization_msgs/VisualLocRecognizeResult"; };
    const char * getMD5(){ return "af944bb003989194ffe33120c472f3ed"; };

  };

}
#endif