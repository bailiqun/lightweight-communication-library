#ifndef _ROS_pal_behaviour_msgs_BehaviourTaskGoal_h
#define _ROS_pal_behaviour_msgs_BehaviourTaskGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_behaviour_msgs/BehaviourArgument.h"

namespace pal_behaviour_msgs
{

  class BehaviourTaskGoal : public ros::Msg
  {
    public:
      typedef const char* _taskName_type;
      _taskName_type taskName;
      uint32_t arguments_length;
      typedef pal_behaviour_msgs::BehaviourArgument _arguments_type;
      _arguments_type st_arguments;
      _arguments_type * arguments;

    BehaviourTaskGoal():
      taskName(""),
      arguments_length(0), arguments(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_taskName = strlen(this->taskName);
      varToArr(outbuffer + offset, length_taskName);
      offset += 4;
      memcpy(outbuffer + offset, this->taskName, length_taskName);
      offset += length_taskName;
      *(outbuffer + offset + 0) = (this->arguments_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->arguments_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->arguments_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->arguments_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->arguments_length);
      for( uint32_t i = 0; i < arguments_length; i++){
      offset += this->arguments[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_taskName;
      arrToVar(length_taskName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_taskName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_taskName-1]=0;
      this->taskName = (char *)(inbuffer + offset-1);
      offset += length_taskName;
      uint32_t arguments_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      arguments_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      arguments_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      arguments_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->arguments_length);
      if(arguments_lengthT > arguments_length)
        this->arguments = (pal_behaviour_msgs::BehaviourArgument*)realloc(this->arguments, arguments_lengthT * sizeof(pal_behaviour_msgs::BehaviourArgument));
      arguments_length = arguments_lengthT;
      for( uint32_t i = 0; i < arguments_length; i++){
      offset += this->st_arguments.deserialize(inbuffer + offset);
        memcpy( &(this->arguments[i]), &(this->st_arguments), sizeof(pal_behaviour_msgs::BehaviourArgument));
      }
     return offset;
    }

    const char * getType(){ return "pal_behaviour_msgs/BehaviourTaskGoal"; };
    const char * getMD5(){ return "f29a8a8019064c8a1f3f3dbe3effeb54"; };

  };

}
#endif