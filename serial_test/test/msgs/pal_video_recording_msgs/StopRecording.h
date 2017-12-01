#ifndef _ROS_SERVICE_StopRecording_h
#define _ROS_SERVICE_StopRecording_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_video_recording_msgs
{

static const char STOPRECORDING[] = "pal_video_recording_msgs/StopRecording";

  class StopRecordingRequest : public ros::Msg
  {
    public:

    StopRecordingRequest()
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

    const char * getType(){ return STOPRECORDING; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class StopRecordingResponse : public ros::Msg
  {
    public:

    StopRecordingResponse()
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

    const char * getType(){ return STOPRECORDING; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class StopRecording {
    public:
    typedef StopRecordingRequest Request;
    typedef StopRecordingResponse Response;
  };

}
#endif
