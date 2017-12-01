#ifndef _ROS_pal_behaviour_msgs_PresentationGoal_h
#define _ROS_pal_behaviour_msgs_PresentationGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_behaviour_msgs
{

  class PresentationGoal : public ros::Msg
  {
    public:
      typedef const char* _presentationFile_type;
      _presentationFile_type presentationFile;

    PresentationGoal():
      presentationFile("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_presentationFile = strlen(this->presentationFile);
      varToArr(outbuffer + offset, length_presentationFile);
      offset += 4;
      memcpy(outbuffer + offset, this->presentationFile, length_presentationFile);
      offset += length_presentationFile;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_presentationFile;
      arrToVar(length_presentationFile, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_presentationFile; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_presentationFile-1]=0;
      this->presentationFile = (char *)(inbuffer + offset-1);
      offset += length_presentationFile;
     return offset;
    }

    const char * getType(){ return "pal_behaviour_msgs/PresentationGoal"; };
    const char * getMD5(){ return "2fabda36f289edf937fcb83c63997aa0"; };

  };

}
#endif