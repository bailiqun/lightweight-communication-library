#ifndef _ROS_pal_tablet_msgs_RobotStatus_h
#define _ROS_pal_tablet_msgs_RobotStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_tablet_msgs/FunctionalityStatus.h"

namespace pal_tablet_msgs
{

  class RobotStatus : public ros::Msg
  {
    public:
      uint32_t messages_length;
      typedef pal_tablet_msgs::FunctionalityStatus _messages_type;
      _messages_type st_messages;
      _messages_type * messages;

    RobotStatus():
      messages_length(0), messages(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->messages_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->messages_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->messages_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->messages_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->messages_length);
      for( uint32_t i = 0; i < messages_length; i++){
      offset += this->messages[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t messages_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      messages_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      messages_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      messages_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->messages_length);
      if(messages_lengthT > messages_length)
        this->messages = (pal_tablet_msgs::FunctionalityStatus*)realloc(this->messages, messages_lengthT * sizeof(pal_tablet_msgs::FunctionalityStatus));
      messages_length = messages_lengthT;
      for( uint32_t i = 0; i < messages_length; i++){
      offset += this->st_messages.deserialize(inbuffer + offset);
        memcpy( &(this->messages[i]), &(this->st_messages), sizeof(pal_tablet_msgs::FunctionalityStatus));
      }
     return offset;
    }

    const char * getType(){ return "pal_tablet_msgs/RobotStatus"; };
    const char * getMD5(){ return "3495bf9d81b79deaa82f3652871818c5"; };

  };

}
#endif