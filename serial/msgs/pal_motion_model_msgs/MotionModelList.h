#ifndef _ROS_pal_motion_model_msgs_MotionModelList_h
#define _ROS_pal_motion_model_msgs_MotionModelList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_motion_model_msgs/MotionModel.h"

namespace pal_motion_model_msgs
{

  class MotionModelList : public ros::Msg
  {
    public:
      uint32_t models_length;
      typedef pal_motion_model_msgs::MotionModel _models_type;
      _models_type st_models;
      _models_type * models;

    MotionModelList():
      models_length(0), models(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->models_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->models_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->models_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->models_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->models_length);
      for( uint32_t i = 0; i < models_length; i++){
      offset += this->models[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t models_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      models_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      models_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      models_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->models_length);
      if(models_lengthT > models_length)
        this->models = (pal_motion_model_msgs::MotionModel*)realloc(this->models, models_lengthT * sizeof(pal_motion_model_msgs::MotionModel));
      models_length = models_lengthT;
      for( uint32_t i = 0; i < models_length; i++){
      offset += this->st_models.deserialize(inbuffer + offset);
        memcpy( &(this->models[i]), &(this->st_models), sizeof(pal_motion_model_msgs::MotionModel));
      }
     return offset;
    }

    const char * getType(){ return "pal_motion_model_msgs/MotionModelList"; };
    const char * getMD5(){ return "f24b8d6d6a0a1542de28f172c2da67ff"; };

  };

}
#endif