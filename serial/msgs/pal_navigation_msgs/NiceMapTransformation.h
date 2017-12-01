#ifndef _ROS_pal_navigation_msgs_NiceMapTransformation_h
#define _ROS_pal_navigation_msgs_NiceMapTransformation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

  class NiceMapTransformation : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _rotYawRad_type;
      _rotYawRad_type rotYawRad;
      typedef float _scale_type;
      _scale_type scale;

    NiceMapTransformation():
      x(0),
      y(0),
      rotYawRad(0),
      scale(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->rotYawRad);
      offset += serializeAvrFloat64(outbuffer + offset, this->scale);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rotYawRad));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->scale));
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/NiceMapTransformation"; };
    const char * getMD5(){ return "af4c7e65074d9c380c082e0485e8868c"; };

  };

}
#endif