#ifndef _ROS_pal_device_msgs_BatteryState_h
#define _ROS_pal_device_msgs_BatteryState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_device_msgs
{

  class BatteryState : public ros::Msg
  {
    public:
      typedef int8_t _chargeState_type;
      _chargeState_type chargeState;
      typedef float _batteryPercentage_type;
      _batteryPercentage_type batteryPercentage;
      enum { FULL =  5 };
      enum { HIGH =  4 };
      enum { MEDIUM =  3 };
      enum { LOW =  2 };
      enum { CRITICAL_LOW =  1 };

    BatteryState():
      chargeState(0),
      batteryPercentage(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_chargeState;
      u_chargeState.real = this->chargeState;
      *(outbuffer + offset + 0) = (u_chargeState.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->chargeState);
      union {
        float real;
        uint32_t base;
      } u_batteryPercentage;
      u_batteryPercentage.real = this->batteryPercentage;
      *(outbuffer + offset + 0) = (u_batteryPercentage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_batteryPercentage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_batteryPercentage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_batteryPercentage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->batteryPercentage);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_chargeState;
      u_chargeState.base = 0;
      u_chargeState.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->chargeState = u_chargeState.real;
      offset += sizeof(this->chargeState);
      union {
        float real;
        uint32_t base;
      } u_batteryPercentage;
      u_batteryPercentage.base = 0;
      u_batteryPercentage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_batteryPercentage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_batteryPercentage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_batteryPercentage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->batteryPercentage = u_batteryPercentage.real;
      offset += sizeof(this->batteryPercentage);
     return offset;
    }

    const char * getType(){ return "pal_device_msgs/BatteryState"; };
    const char * getMD5(){ return "ffbf73d789e375a8bace732de9096d5f"; };

  };

}
#endif