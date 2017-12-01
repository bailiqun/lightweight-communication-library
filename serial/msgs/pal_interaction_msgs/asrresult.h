#ifndef _ROS_pal_interaction_msgs_asrresult_h
#define _ROS_pal_interaction_msgs_asrresult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "pal_interaction_msgs/actiontag.h"

namespace pal_interaction_msgs
{

  class asrresult : public ros::Msg
  {
    public:
      typedef const char* _text_type;
      _text_type text;
      typedef int8_t _confidence_type;
      _confidence_type confidence;
      typedef ros::Time _start_type;
      _start_type start;
      typedef ros::Time _end_type;
      _end_type end;
      uint32_t tags_length;
      typedef pal_interaction_msgs::actiontag _tags_type;
      _tags_type st_tags;
      _tags_type * tags;
      enum { CONFIDENCE_UNDEFINED =  -1 };
      enum { CONFIDENCE_POOR =  1 };
      enum { CONFIDENCE_LOW =  2 };
      enum { CONFIDENCE_GOOD =  3 };
      enum { CONFIDENCE_MAX =  4 };

    asrresult():
      text(""),
      confidence(0),
      start(),
      end(),
      tags_length(0), tags(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_text = strlen(this->text);
      varToArr(outbuffer + offset, length_text);
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
      union {
        int8_t real;
        uint8_t base;
      } u_confidence;
      u_confidence.real = this->confidence;
      *(outbuffer + offset + 0) = (u_confidence.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->confidence);
      *(outbuffer + offset + 0) = (this->start.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start.sec);
      *(outbuffer + offset + 0) = (this->start.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start.nsec);
      *(outbuffer + offset + 0) = (this->end.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->end.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->end.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->end.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end.sec);
      *(outbuffer + offset + 0) = (this->end.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->end.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->end.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->end.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end.nsec);
      *(outbuffer + offset + 0) = (this->tags_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_length);
      for( uint32_t i = 0; i < tags_length; i++){
      offset += this->tags[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_text;
      arrToVar(length_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
      union {
        int8_t real;
        uint8_t base;
      } u_confidence;
      u_confidence.base = 0;
      u_confidence.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->confidence = u_confidence.real;
      offset += sizeof(this->confidence);
      this->start.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->start.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start.sec);
      this->start.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->start.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start.nsec);
      this->end.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->end.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->end.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->end.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->end.sec);
      this->end.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->end.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->end.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->end.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->end.nsec);
      uint32_t tags_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tags_length);
      if(tags_lengthT > tags_length)
        this->tags = (pal_interaction_msgs::actiontag*)realloc(this->tags, tags_lengthT * sizeof(pal_interaction_msgs::actiontag));
      tags_length = tags_lengthT;
      for( uint32_t i = 0; i < tags_length; i++){
      offset += this->st_tags.deserialize(inbuffer + offset);
        memcpy( &(this->tags[i]), &(this->st_tags), sizeof(pal_interaction_msgs::actiontag));
      }
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/asrresult"; };
    const char * getMD5(){ return "a6ebae90936a20cef967166ff7e96f64"; };

  };

}
#endif