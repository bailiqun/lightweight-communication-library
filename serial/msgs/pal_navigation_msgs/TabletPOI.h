#ifndef _ROS_pal_navigation_msgs_TabletPOI_h
#define _ROS_pal_navigation_msgs_TabletPOI_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "std_msgs/String.h"

namespace pal_navigation_msgs
{

  class TabletPOI : public ros::Msg
  {
    public:
      uint32_t POIs_length;
      typedef geometry_msgs::Point _POIs_type;
      _POIs_type st_POIs;
      _POIs_type * POIs;
      uint32_t IDs_length;
      typedef std_msgs::String _IDs_type;
      _IDs_type st_IDs;
      _IDs_type * IDs;
      typedef std_msgs::String _map_id_type;
      _map_id_type map_id;

    TabletPOI():
      POIs_length(0), POIs(NULL),
      IDs_length(0), IDs(NULL),
      map_id()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->POIs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->POIs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->POIs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->POIs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->POIs_length);
      for( uint32_t i = 0; i < POIs_length; i++){
      offset += this->POIs[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->IDs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->IDs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->IDs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->IDs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->IDs_length);
      for( uint32_t i = 0; i < IDs_length; i++){
      offset += this->IDs[i].serialize(outbuffer + offset);
      }
      offset += this->map_id.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t POIs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      POIs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      POIs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      POIs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->POIs_length);
      if(POIs_lengthT > POIs_length)
        this->POIs = (geometry_msgs::Point*)realloc(this->POIs, POIs_lengthT * sizeof(geometry_msgs::Point));
      POIs_length = POIs_lengthT;
      for( uint32_t i = 0; i < POIs_length; i++){
      offset += this->st_POIs.deserialize(inbuffer + offset);
        memcpy( &(this->POIs[i]), &(this->st_POIs), sizeof(geometry_msgs::Point));
      }
      uint32_t IDs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      IDs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      IDs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      IDs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->IDs_length);
      if(IDs_lengthT > IDs_length)
        this->IDs = (std_msgs::String*)realloc(this->IDs, IDs_lengthT * sizeof(std_msgs::String));
      IDs_length = IDs_lengthT;
      for( uint32_t i = 0; i < IDs_length; i++){
      offset += this->st_IDs.deserialize(inbuffer + offset);
        memcpy( &(this->IDs[i]), &(this->st_IDs), sizeof(std_msgs::String));
      }
      offset += this->map_id.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/TabletPOI"; };
    const char * getMD5(){ return "2ec4b22e981d882e9e77e8562cb8c5fe"; };

  };

}
#endif