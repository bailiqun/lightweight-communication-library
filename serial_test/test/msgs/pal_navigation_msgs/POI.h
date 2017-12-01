#ifndef _ROS_pal_navigation_msgs_POI_h
#define _ROS_pal_navigation_msgs_POI_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud.h"
#include "std_msgs/String.h"

namespace pal_navigation_msgs
{

  class POI : public ros::Msg
  {
    public:
      typedef sensor_msgs::PointCloud _points_type;
      _points_type points;
      uint32_t ids_length;
      typedef std_msgs::String _ids_type;
      _ids_type st_ids;
      _ids_type * ids;
      typedef std_msgs::String _map_id_type;
      _map_id_type map_id;

    POI():
      points(),
      ids_length(0), ids(NULL),
      map_id()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->points.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ids_length);
      for( uint32_t i = 0; i < ids_length; i++){
      offset += this->ids[i].serialize(outbuffer + offset);
      }
      offset += this->map_id.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->points.deserialize(inbuffer + offset);
      uint32_t ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ids_length);
      if(ids_lengthT > ids_length)
        this->ids = (std_msgs::String*)realloc(this->ids, ids_lengthT * sizeof(std_msgs::String));
      ids_length = ids_lengthT;
      for( uint32_t i = 0; i < ids_length; i++){
      offset += this->st_ids.deserialize(inbuffer + offset);
        memcpy( &(this->ids[i]), &(this->st_ids), sizeof(std_msgs::String));
      }
      offset += this->map_id.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/POI"; };
    const char * getMD5(){ return "accd8dd07484c01aa4180821c83d7d4f"; };

  };

}
#endif