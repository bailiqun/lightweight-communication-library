#ifndef _ROS_pal_interaction_msgs_TtsFeedback_h
#define _ROS_pal_interaction_msgs_TtsFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "pal_interaction_msgs/TtsMark.h"

namespace pal_interaction_msgs
{

  class TtsFeedback : public ros::Msg
  {
    public:
      typedef uint16_t _event_type_type;
      _event_type_type event_type;
      typedef ros::Time _timestamp_type;
      _timestamp_type timestamp;
      typedef const char* _text_said_type;
      _text_said_type text_said;
      typedef const char* _next_word_type;
      _next_word_type next_word;
      typedef pal_interaction_msgs::TtsMark _marks_type;
      _marks_type marks;
      enum { TTS_EVENT_INITIALIZATION =  1 };
      enum { TTS_EVENT_SHUTDOWN =  2 };
      enum { TTS_EVENT_SYNCHRONIZATION =  4 };
      enum { TTS_EVENT_FINISHED_PLAYING_UTTERANCE =  8 };
      enum { TTS_EVENT_MARK =  16 };
      enum { TTS_EVENT_STARTED_PLAYING_WORD =  32 };
      enum { TTS_EVENT_FINISHED_PLAYING_PHRASE =  64 };
      enum { TTS_EVENT_FINISHED_PLAYING_SENTENCE =  128 };

    TtsFeedback():
      event_type(0),
      timestamp(),
      text_said(""),
      next_word(""),
      marks()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->event_type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->event_type >> (8 * 1)) & 0xFF;
      offset += sizeof(this->event_type);
      *(outbuffer + offset + 0) = (this->timestamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp.sec);
      *(outbuffer + offset + 0) = (this->timestamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp.nsec);
      uint32_t length_text_said = strlen(this->text_said);
      varToArr(outbuffer + offset, length_text_said);
      offset += 4;
      memcpy(outbuffer + offset, this->text_said, length_text_said);
      offset += length_text_said;
      uint32_t length_next_word = strlen(this->next_word);
      varToArr(outbuffer + offset, length_next_word);
      offset += 4;
      memcpy(outbuffer + offset, this->next_word, length_next_word);
      offset += length_next_word;
      offset += this->marks.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->event_type =  ((uint16_t) (*(inbuffer + offset)));
      this->event_type |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->event_type);
      this->timestamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp.sec);
      this->timestamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp.nsec);
      uint32_t length_text_said;
      arrToVar(length_text_said, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text_said; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text_said-1]=0;
      this->text_said = (char *)(inbuffer + offset-1);
      offset += length_text_said;
      uint32_t length_next_word;
      arrToVar(length_next_word, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_next_word; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_next_word-1]=0;
      this->next_word = (char *)(inbuffer + offset-1);
      offset += length_next_word;
      offset += this->marks.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/TtsFeedback"; };
    const char * getMD5(){ return "012a1f226b229db44faa41be67e26d4b"; };

  };

}
#endif