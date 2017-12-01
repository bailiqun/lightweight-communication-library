#ifndef _ROS_pal_detection_msgs_RecognizedActions_h
#define _ROS_pal_detection_msgs_RecognizedActions_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pal_detection_msgs
{

  class RecognizedActions : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t action_name_length;
      typedef char* _action_name_type;
      _action_name_type st_action_name;
      _action_name_type * action_name;
      uint32_t u_length;
      typedef int64_t _u_type;
      _u_type st_u;
      _u_type * u;
      uint32_t v_length;
      typedef int64_t _v_type;
      _v_type st_v;
      _v_type * v;

    RecognizedActions():
      header(),
      action_name_length(0), action_name(NULL),
      u_length(0), u(NULL),
      v_length(0), v(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->action_name_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->action_name_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->action_name_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->action_name_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->action_name_length);
      for( uint32_t i = 0; i < action_name_length; i++){
      uint32_t length_action_namei = strlen(this->action_name[i]);
      varToArr(outbuffer + offset, length_action_namei);
      offset += 4;
      memcpy(outbuffer + offset, this->action_name[i], length_action_namei);
      offset += length_action_namei;
      }
      *(outbuffer + offset + 0) = (this->u_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->u_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->u_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->u_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->u_length);
      for( uint32_t i = 0; i < u_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_ui;
      u_ui.real = this->u[i];
      *(outbuffer + offset + 0) = (u_ui.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ui.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ui.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ui.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ui.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ui.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ui.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ui.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->u[i]);
      }
      *(outbuffer + offset + 0) = (this->v_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->v_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->v_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->v_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v_length);
      for( uint32_t i = 0; i < v_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_vi;
      u_vi.real = this->v[i];
      *(outbuffer + offset + 0) = (u_vi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->v[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t action_name_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      action_name_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      action_name_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      action_name_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->action_name_length);
      if(action_name_lengthT > action_name_length)
        this->action_name = (char**)realloc(this->action_name, action_name_lengthT * sizeof(char*));
      action_name_length = action_name_lengthT;
      for( uint32_t i = 0; i < action_name_length; i++){
      uint32_t length_st_action_name;
      arrToVar(length_st_action_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_action_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_action_name-1]=0;
      this->st_action_name = (char *)(inbuffer + offset-1);
      offset += length_st_action_name;
        memcpy( &(this->action_name[i]), &(this->st_action_name), sizeof(char*));
      }
      uint32_t u_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      u_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      u_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      u_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->u_length);
      if(u_lengthT > u_length)
        this->u = (int64_t*)realloc(this->u, u_lengthT * sizeof(int64_t));
      u_length = u_lengthT;
      for( uint32_t i = 0; i < u_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_u;
      u_st_u.base = 0;
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_u = u_st_u.real;
      offset += sizeof(this->st_u);
        memcpy( &(this->u[i]), &(this->st_u), sizeof(int64_t));
      }
      uint32_t v_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      v_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      v_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      v_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->v_length);
      if(v_lengthT > v_length)
        this->v = (int64_t*)realloc(this->v, v_lengthT * sizeof(int64_t));
      v_length = v_lengthT;
      for( uint32_t i = 0; i < v_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_v;
      u_st_v.base = 0;
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_v = u_st_v.real;
      offset += sizeof(this->st_v);
        memcpy( &(this->v[i]), &(this->st_v), sizeof(int64_t));
      }
     return offset;
    }

    const char * getType(){ return "pal_detection_msgs/RecognizedActions"; };
    const char * getMD5(){ return "e6c6e85fc615700151c9f88b60277903"; };

  };

}
#endif