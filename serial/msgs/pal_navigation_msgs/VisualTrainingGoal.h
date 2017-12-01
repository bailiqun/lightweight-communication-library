#ifndef _ROS_pal_navigation_msgs_VisualTrainingGoal_h
#define _ROS_pal_navigation_msgs_VisualTrainingGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

  class VisualTrainingGoal : public ros::Msg
  {
    public:
      typedef uint8_t _action_type;
      _action_type action;
      typedef const char* _database_path_type;
      _database_path_type database_path;
      enum { ACTION_TRAIN = 0 };

    VisualTrainingGoal():
      action(0),
      database_path("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->action >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action);
      uint32_t length_database_path = strlen(this->database_path);
      varToArr(outbuffer + offset, length_database_path);
      offset += 4;
      memcpy(outbuffer + offset, this->database_path, length_database_path);
      offset += length_database_path;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->action =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->action);
      uint32_t length_database_path;
      arrToVar(length_database_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_database_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_database_path-1]=0;
      this->database_path = (char *)(inbuffer + offset-1);
      offset += length_database_path;
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/VisualTrainingGoal"; };
    const char * getMD5(){ return "1e49c4ac5474f4adebb02c2483518127"; };

  };

}
#endif