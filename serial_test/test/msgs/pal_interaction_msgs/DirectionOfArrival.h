#ifndef _ROS_pal_interaction_msgs_DirectionOfArrival_h
#define _ROS_pal_interaction_msgs_DirectionOfArrival_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class DirectionOfArrival : public ros::Msg
  {
    public:
      typedef float _doa_type;
      _doa_type doa;
      typedef float _prob_type;
      _prob_type prob;
      typedef float _power_type;
      _power_type power;
      typedef const char* _metadoa_type;
      _metadoa_type metadoa;

    DirectionOfArrival():
      doa(0),
      prob(0),
      power(0),
      metadoa("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_doa;
      u_doa.real = this->doa;
      *(outbuffer + offset + 0) = (u_doa.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_doa.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_doa.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_doa.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->doa);
      union {
        float real;
        uint32_t base;
      } u_prob;
      u_prob.real = this->prob;
      *(outbuffer + offset + 0) = (u_prob.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_prob.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_prob.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_prob.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->prob);
      union {
        float real;
        uint32_t base;
      } u_power;
      u_power.real = this->power;
      *(outbuffer + offset + 0) = (u_power.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_power.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_power.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_power.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->power);
      uint32_t length_metadoa = strlen(this->metadoa);
      varToArr(outbuffer + offset, length_metadoa);
      offset += 4;
      memcpy(outbuffer + offset, this->metadoa, length_metadoa);
      offset += length_metadoa;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_doa;
      u_doa.base = 0;
      u_doa.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_doa.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_doa.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_doa.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->doa = u_doa.real;
      offset += sizeof(this->doa);
      union {
        float real;
        uint32_t base;
      } u_prob;
      u_prob.base = 0;
      u_prob.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_prob.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_prob.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_prob.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->prob = u_prob.real;
      offset += sizeof(this->prob);
      union {
        float real;
        uint32_t base;
      } u_power;
      u_power.base = 0;
      u_power.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_power.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_power.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_power.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->power = u_power.real;
      offset += sizeof(this->power);
      uint32_t length_metadoa;
      arrToVar(length_metadoa, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_metadoa; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_metadoa-1]=0;
      this->metadoa = (char *)(inbuffer + offset-1);
      offset += length_metadoa;
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/DirectionOfArrival"; };
    const char * getMD5(){ return "cbcea81e85fdde7bb3d71de75dea9f5c"; };

  };

}
#endif