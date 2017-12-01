#ifndef _ROS_moveit_simple_grasps_GenerateGraspsGoal_h
#define _ROS_moveit_simple_grasps_GenerateGraspsGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "moveit_simple_grasps/GraspGeneratorOptions.h"

namespace moveit_simple_grasps
{

  class GenerateGraspsGoal : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef float _width_type;
      _width_type width;
      uint32_t options_length;
      typedef moveit_simple_grasps::GraspGeneratorOptions _options_type;
      _options_type st_options;
      _options_type * options;

    GenerateGraspsGoal():
      pose(),
      width(0),
      options_length(0), options(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->width);
      *(outbuffer + offset + 0) = (this->options_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->options_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->options_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->options_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->options_length);
      for( uint32_t i = 0; i < options_length; i++){
      offset += this->options[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->width));
      uint32_t options_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      options_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      options_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      options_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->options_length);
      if(options_lengthT > options_length)
        this->options = (moveit_simple_grasps::GraspGeneratorOptions*)realloc(this->options, options_lengthT * sizeof(moveit_simple_grasps::GraspGeneratorOptions));
      options_length = options_lengthT;
      for( uint32_t i = 0; i < options_length; i++){
      offset += this->st_options.deserialize(inbuffer + offset);
        memcpy( &(this->options[i]), &(this->st_options), sizeof(moveit_simple_grasps::GraspGeneratorOptions));
      }
     return offset;
    }

    const char * getType(){ return "moveit_simple_grasps/GenerateGraspsGoal"; };
    const char * getMD5(){ return "162875df5b62e9fb4be6d2aa5a67176d"; };

  };

}
#endif