#ifndef _ROS_SERVICE_SetDatabase_h
#define _ROS_SERVICE_SetDatabase_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_detection_msgs
{

static const char SETDATABASE[] = "pal_detection_msgs/SetDatabase";

  class SetDatabaseRequest : public ros::Msg
  {
    public:
      typedef const char* _databaseName_type;
      _databaseName_type databaseName;
      typedef bool _purgeAll_type;
      _purgeAll_type purgeAll;

    SetDatabaseRequest():
      databaseName(""),
      purgeAll(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_databaseName = strlen(this->databaseName);
      varToArr(outbuffer + offset, length_databaseName);
      offset += 4;
      memcpy(outbuffer + offset, this->databaseName, length_databaseName);
      offset += length_databaseName;
      union {
        bool real;
        uint8_t base;
      } u_purgeAll;
      u_purgeAll.real = this->purgeAll;
      *(outbuffer + offset + 0) = (u_purgeAll.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->purgeAll);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_databaseName;
      arrToVar(length_databaseName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_databaseName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_databaseName-1]=0;
      this->databaseName = (char *)(inbuffer + offset-1);
      offset += length_databaseName;
      union {
        bool real;
        uint8_t base;
      } u_purgeAll;
      u_purgeAll.base = 0;
      u_purgeAll.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->purgeAll = u_purgeAll.real;
      offset += sizeof(this->purgeAll);
     return offset;
    }

    const char * getType(){ return SETDATABASE; };
    const char * getMD5(){ return "1cf0b9bc147e7ba402d13d5645c217d7"; };

  };

  class SetDatabaseResponse : public ros::Msg
  {
    public:

    SetDatabaseResponse()
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

    const char * getType(){ return SETDATABASE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetDatabase {
    public:
    typedef SetDatabaseRequest Request;
    typedef SetDatabaseResponse Response;
  };

}
#endif
