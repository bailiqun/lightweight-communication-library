#ifndef _ROS_SERVICE_SoundLocalisationService_h
#define _ROS_SERVICE_SoundLocalisationService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_interaction_msgs/EnablingSoundLocalisation.h"

namespace pal_interaction_msgs
{

static const char SOUNDLOCALISATIONSERVICE[] = "pal_interaction_msgs/SoundLocalisationService";

  class SoundLocalisationServiceRequest : public ros::Msg
  {
    public:
      typedef pal_interaction_msgs::EnablingSoundLocalisation _enabling_type;
      _enabling_type enabling;

    SoundLocalisationServiceRequest():
      enabling()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->enabling.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->enabling.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SOUNDLOCALISATIONSERVICE; };
    const char * getMD5(){ return "cc68fffb4060073f9a9cee5375c725ea"; };

  };

  class SoundLocalisationServiceResponse : public ros::Msg
  {
    public:

    SoundLocalisationServiceResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SOUNDLOCALISATIONSERVICE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SoundLocalisationService {
    public:
    typedef SoundLocalisationServiceRequest Request;
    typedef SoundLocalisationServiceResponse Response;
  };

}
#endif
