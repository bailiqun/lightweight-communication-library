#ifndef _ROS_SERVICE_ASRService_h
#define _ROS_SERVICE_ASRService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_interaction_msgs/ASRSrvResponse.h"
#include "pal_interaction_msgs/ASRSrvRequest.h"

namespace pal_interaction_msgs
{

static const char ASRSERVICE[] = "pal_interaction_msgs/ASRService";

  class ASRServiceRequest : public ros::Msg
  {
    public:
      typedef pal_interaction_msgs::ASRSrvRequest _request_type;
      _request_type request;

    ASRServiceRequest():
      request()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->request.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->request.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return ASRSERVICE; };
    const char * getMD5(){ return "bf3afdb7a9717c398d58f3a78181472c"; };

  };

  class ASRServiceResponse : public ros::Msg
  {
    public:
      typedef pal_interaction_msgs::ASRSrvResponse _response_type;
      _response_type response;

    ASRServiceResponse():
      response()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->response.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->response.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return ASRSERVICE; };
    const char * getMD5(){ return "ea637128b99766dfe061d621936cbd13"; };

  };

  class ASRService {
    public:
    typedef ASRServiceRequest Request;
    typedef ASRServiceResponse Response;
  };

}
#endif
