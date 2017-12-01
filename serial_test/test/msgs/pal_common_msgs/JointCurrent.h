#ifndef _ROS_pal_common_msgs_JointCurrent_h
#define _ROS_pal_common_msgs_JointCurrent_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_common_msgs
{

  class JointCurrent : public ros::Msg
  {
    public:
      typedef const char* _joints_type;
      _joints_type joints;
      typedef float _current_limit_type;
      _current_limit_type current_limit;

    JointCurrent():
      joints(""),
      current_limit(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_joints = strlen(this->joints);
      varToArr(outbuffer + offset, length_joints);
      offset += 4;
      memcpy(outbuffer + offset, this->joints, length_joints);
      offset += length_joints;
      union {
        float real;
        uint32_t base;
      } u_current_limit;
      u_current_limit.real = this->current_limit;
      *(outbuffer + offset + 0) = (u_current_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_limit);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_joints;
      arrToVar(length_joints, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_joints; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_joints-1]=0;
      this->joints = (char *)(inbuffer + offset-1);
      offset += length_joints;
      union {
        float real;
        uint32_t base;
      } u_current_limit;
      u_current_limit.base = 0;
      u_current_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_limit = u_current_limit.real;
      offset += sizeof(this->current_limit);
     return offset;
    }

    const char * getType(){ return "pal_common_msgs/JointCurrent"; };
    const char * getMD5(){ return "aa38356f1b4f7b710d0060415affb648"; };

  };

}
#endif