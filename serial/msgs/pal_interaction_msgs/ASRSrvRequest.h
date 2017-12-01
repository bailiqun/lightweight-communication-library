#ifndef _ROS_pal_interaction_msgs_ASRSrvRequest_h
#define _ROS_pal_interaction_msgs_ASRSrvRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_interaction_msgs/ASRActivation.h"
#include "pal_interaction_msgs/ASRLangModelMngmt.h"
#include "pal_interaction_msgs/ASRLanguage.h"

namespace pal_interaction_msgs
{

  class ASRSrvRequest : public ros::Msg
  {
    public:
      uint32_t requests_length;
      typedef int8_t _requests_type;
      _requests_type st_requests;
      _requests_type * requests;
      typedef pal_interaction_msgs::ASRActivation _activation_type;
      _activation_type activation;
      typedef pal_interaction_msgs::ASRLangModelMngmt _model_type;
      _model_type model;
      typedef pal_interaction_msgs::ASRLanguage _lang_type;
      _lang_type lang;
      enum { ACTIVATION =  1 };
      enum { GRAMMAR =  2 };
      enum { LANGUAGE =  3 };
      enum { STATUS =  4 };
      enum { KWSPOTTING =  5 };

    ASRSrvRequest():
      requests_length(0), requests(NULL),
      activation(),
      model(),
      lang()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->requests_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->requests_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->requests_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->requests_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->requests_length);
      for( uint32_t i = 0; i < requests_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_requestsi;
      u_requestsi.real = this->requests[i];
      *(outbuffer + offset + 0) = (u_requestsi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->requests[i]);
      }
      offset += this->activation.serialize(outbuffer + offset);
      offset += this->model.serialize(outbuffer + offset);
      offset += this->lang.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t requests_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      requests_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      requests_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      requests_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->requests_length);
      if(requests_lengthT > requests_length)
        this->requests = (int8_t*)realloc(this->requests, requests_lengthT * sizeof(int8_t));
      requests_length = requests_lengthT;
      for( uint32_t i = 0; i < requests_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_st_requests;
      u_st_requests.base = 0;
      u_st_requests.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_requests = u_st_requests.real;
      offset += sizeof(this->st_requests);
        memcpy( &(this->requests[i]), &(this->st_requests), sizeof(int8_t));
      }
      offset += this->activation.deserialize(inbuffer + offset);
      offset += this->model.deserialize(inbuffer + offset);
      offset += this->lang.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/ASRSrvRequest"; };
    const char * getMD5(){ return "18340721947db95a89c5d69f8dcbb2cc"; };

  };

}
#endif