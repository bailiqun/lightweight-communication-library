#ifndef _ROS_SERVICE_ChangeBuilding_h
#define _ROS_SERVICE_ChangeBuilding_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

static const char CHANGEBUILDING[] = "pal_navigation_msgs/ChangeBuilding";

  class ChangeBuildingRequest : public ros::Msg
  {
    public:
      typedef const char* _building_name_type;
      _building_name_type building_name;
      typedef const char* _floor_name_type;
      _floor_name_type floor_name;

    ChangeBuildingRequest():
      building_name(""),
      floor_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_building_name = strlen(this->building_name);
      varToArr(outbuffer + offset, length_building_name);
      offset += 4;
      memcpy(outbuffer + offset, this->building_name, length_building_name);
      offset += length_building_name;
      uint32_t length_floor_name = strlen(this->floor_name);
      varToArr(outbuffer + offset, length_floor_name);
      offset += 4;
      memcpy(outbuffer + offset, this->floor_name, length_floor_name);
      offset += length_floor_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_building_name;
      arrToVar(length_building_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_building_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_building_name-1]=0;
      this->building_name = (char *)(inbuffer + offset-1);
      offset += length_building_name;
      uint32_t length_floor_name;
      arrToVar(length_floor_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_floor_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_floor_name-1]=0;
      this->floor_name = (char *)(inbuffer + offset-1);
      offset += length_floor_name;
     return offset;
    }

    const char * getType(){ return CHANGEBUILDING; };
    const char * getMD5(){ return "9cd21d3150f8ada4b997571625fab346"; };

  };

  class ChangeBuildingResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    ChangeBuildingResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return CHANGEBUILDING; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class ChangeBuilding {
    public:
    typedef ChangeBuildingRequest Request;
    typedef ChangeBuildingResponse Response;
  };

}
#endif
