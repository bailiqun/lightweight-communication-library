#ifndef _ROS_SERVICE_StartRecording_h
#define _ROS_SERVICE_StartRecording_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_video_recording_msgs
{

static const char STARTRECORDING[] = "pal_video_recording_msgs/StartRecording";

  class StartRecordingRequest : public ros::Msg
  {
    public:

    StartRecordingRequest()
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

    const char * getType(){ return STARTRECORDING; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class StartRecordingResponse : public ros::Msg
  {
    public:

    StartRecordingResponse()
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

    const char * getType(){ return STARTRECORDING; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class StartRecording {
    public:
    typedef StartRecordingRequest Request;
    typedef StartRecordingResponse Response;
  };

}
#endif
