#ifndef _ROS_pal_interaction_msgs_ASREvent_h
#define _ROS_pal_interaction_msgs_ASREvent_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_interaction_msgs/asrresult.h"

namespace pal_interaction_msgs
{

  class ASREvent : public ros::Msg
  {
    public:
      typedef int8_t _event_id_type;
      _event_id_type event_id;
      typedef int8_t _listen_state_type;
      _listen_state_type listen_state;
      typedef pal_interaction_msgs::asrresult _recognized_utterance_type;
      _recognized_utterance_type recognized_utterance;
      typedef bool _active_type;
      _active_type active;
      enum { EVENT_UNDEFINED =  -1 };
      enum { EVENT_LISTEN_STATE =  1 };
      enum { EVENT_RECOGNIZED_UTT =  2 };
      enum { EVENT_ASR_ACTIVATION =  3 };
      enum { EVENT_FAILED_DECODING =  4 };
      enum { LISTEN_UNDEFINED =  20 };
      enum { LISTEN_CALIBRATION =  21 };
      enum { LISTEN_WAITING_FOR_SPEECH =  22 };
      enum { LISTEN_SPEECH_DETECTED =  23 };
      enum { LISTEN_END_OF_SPEECH =  24 };

    ASREvent():
      event_id(0),
      listen_state(0),
      recognized_utterance(),
      active(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_event_id;
      u_event_id.real = this->event_id;
      *(outbuffer + offset + 0) = (u_event_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->event_id);
      union {
        int8_t real;
        uint8_t base;
      } u_listen_state;
      u_listen_state.real = this->listen_state;
      *(outbuffer + offset + 0) = (u_listen_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->listen_state);
      offset += this->recognized_utterance.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_active;
      u_active.real = this->active;
      *(outbuffer + offset + 0) = (u_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_event_id;
      u_event_id.base = 0;
      u_event_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->event_id = u_event_id.real;
      offset += sizeof(this->event_id);
      union {
        int8_t real;
        uint8_t base;
      } u_listen_state;
      u_listen_state.base = 0;
      u_listen_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->listen_state = u_listen_state.real;
      offset += sizeof(this->listen_state);
      offset += this->recognized_utterance.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_active;
      u_active.base = 0;
      u_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->active = u_active.real;
      offset += sizeof(this->active);
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/ASREvent"; };
    const char * getMD5(){ return "e26dacd12290ffb6af0944d5b6ae9ffd"; };

  };

}
#endif