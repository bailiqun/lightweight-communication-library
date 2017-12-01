#ifndef _ROS_pal_navigation_msgs_ServiceStatus_h
#define _ROS_pal_navigation_msgs_ServiceStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace pal_navigation_msgs
{

  class ServiceStatus : public ros::Msg
  {
    public:
      typedef const char* _serviceName_type;
      _serviceName_type serviceName;
      typedef bool _is_running_type;
      _is_running_type is_running;
      typedef float _update_frequency_type;
      _update_frequency_type update_frequency;
      typedef ros::Time _latest_run_time_type;
      _latest_run_time_type latest_run_time;
      typedef bool _status_type;
      _status_type status;

    ServiceStatus():
      serviceName(""),
      is_running(0),
      update_frequency(0),
      latest_run_time(),
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_serviceName = strlen(this->serviceName);
      varToArr(outbuffer + offset, length_serviceName);
      offset += 4;
      memcpy(outbuffer + offset, this->serviceName, length_serviceName);
      offset += length_serviceName;
      union {
        bool real;
        uint8_t base;
      } u_is_running;
      u_is_running.real = this->is_running;
      *(outbuffer + offset + 0) = (u_is_running.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_running);
      union {
        float real;
        uint32_t base;
      } u_update_frequency;
      u_update_frequency.real = this->update_frequency;
      *(outbuffer + offset + 0) = (u_update_frequency.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_update_frequency.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_update_frequency.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_update_frequency.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->update_frequency);
      *(outbuffer + offset + 0) = (this->latest_run_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->latest_run_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->latest_run_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->latest_run_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latest_run_time.sec);
      *(outbuffer + offset + 0) = (this->latest_run_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->latest_run_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->latest_run_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->latest_run_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latest_run_time.nsec);
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_serviceName;
      arrToVar(length_serviceName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_serviceName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_serviceName-1]=0;
      this->serviceName = (char *)(inbuffer + offset-1);
      offset += length_serviceName;
      union {
        bool real;
        uint8_t base;
      } u_is_running;
      u_is_running.base = 0;
      u_is_running.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_running = u_is_running.real;
      offset += sizeof(this->is_running);
      union {
        float real;
        uint32_t base;
      } u_update_frequency;
      u_update_frequency.base = 0;
      u_update_frequency.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_update_frequency.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_update_frequency.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_update_frequency.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->update_frequency = u_update_frequency.real;
      offset += sizeof(this->update_frequency);
      this->latest_run_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->latest_run_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->latest_run_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->latest_run_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->latest_run_time.sec);
      this->latest_run_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->latest_run_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->latest_run_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->latest_run_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->latest_run_time.nsec);
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/ServiceStatus"; };
    const char * getMD5(){ return "b734cea5bf73c81e5fb0d99553451daa"; };

  };

}
#endif