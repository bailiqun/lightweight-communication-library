#ifndef _ROS_pal_vision_msgs_FaceRecognitionGoal_h
#define _ROS_pal_vision_msgs_FaceRecognitionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_vision_msgs
{

  class FaceRecognitionGoal : public ros::Msg
  {
    public:
      typedef uint8_t _order_id_type;
      _order_id_type order_id;
      typedef const char* _order_argument_type;
      _order_argument_type order_argument;

    FaceRecognitionGoal():
      order_id(0),
      order_argument("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->order_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->order_id);
      uint32_t length_order_argument = strlen(this->order_argument);
      varToArr(outbuffer + offset, length_order_argument);
      offset += 4;
      memcpy(outbuffer + offset, this->order_argument, length_order_argument);
      offset += length_order_argument;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->order_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->order_id);
      uint32_t length_order_argument;
      arrToVar(length_order_argument, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_order_argument; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_order_argument-1]=0;
      this->order_argument = (char *)(inbuffer + offset-1);
      offset += length_order_argument;
     return offset;
    }

    const char * getType(){ return "pal_vision_msgs/FaceRecognitionGoal"; };
    const char * getMD5(){ return "12fa0d0af9b141eceafa42011d31f9c2"; };

  };

}
#endif