#ifndef _ROS_SERVICE_BehaviourEvent_h
#define _ROS_SERVICE_BehaviourEvent_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_behaviour_msgs/BehaviourArgument.h"

namespace pal_behaviour_msgs
{

static const char BEHAVIOUREVENT[] = "pal_behaviour_msgs/BehaviourEvent";

  class BehaviourEventRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      uint32_t arguments_length;
      typedef pal_behaviour_msgs::BehaviourArgument _arguments_type;
      _arguments_type st_arguments;
      _arguments_type * arguments;

    BehaviourEventRequest():
      name(""),
      arguments_length(0), arguments(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
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
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
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

    const char * getType(){ return BEHAVIOUREVENT; };
    const char * getMD5(){ return "e79d496ead939847a2522e7338b0a011"; };

  };

  class BehaviourEventResponse : public ros::Msg
  {
    public:
      typedef const char* _response_type;
      _response_type response;

    BehaviourEventResponse():
      response("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_response = strlen(this->response);
      varToArr(outbuffer + offset, length_response);
      offset += 4;
      memcpy(outbuffer + offset, this->response, length_response);
      offset += length_response;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_response;
      arrToVar(length_response, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_response; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_response-1]=0;
      this->response = (char *)(inbuffer + offset-1);
      offset += length_response;
     return offset;
    }

    const char * getType(){ return BEHAVIOUREVENT; };
    const char * getMD5(){ return "6de314e2dc76fbff2b6244a6ad70b68d"; };

  };

  class BehaviourEvent {
    public:
    typedef BehaviourEventRequest Request;
    typedef BehaviourEventResponse Response;
  };

}
#endif
