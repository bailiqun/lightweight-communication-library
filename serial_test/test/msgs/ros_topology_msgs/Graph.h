#ifndef _ROS_ros_topology_msgs_Graph_h
#define _ROS_ros_topology_msgs_Graph_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros_topology_msgs/Node.h"
#include "ros_topology_msgs/Topic.h"

namespace ros_topology_msgs
{

  class Graph : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _master_type;
      _master_type master;
      uint32_t nodes_length;
      typedef ros_topology_msgs::Node _nodes_type;
      _nodes_type st_nodes;
      _nodes_type * nodes;
      uint32_t topics_length;
      typedef ros_topology_msgs::Topic _topics_type;
      _topics_type st_topics;
      _topics_type * topics;

    Graph():
      header(),
      master(""),
      nodes_length(0), nodes(NULL),
      topics_length(0), topics(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_master = strlen(this->master);
      varToArr(outbuffer + offset, length_master);
      offset += 4;
      memcpy(outbuffer + offset, this->master, length_master);
      offset += length_master;
      *(outbuffer + offset + 0) = (this->nodes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->nodes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->nodes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->nodes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nodes_length);
      for( uint32_t i = 0; i < nodes_length; i++){
      offset += this->nodes[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->topics_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->topics_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->topics_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->topics_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->topics_length);
      for( uint32_t i = 0; i < topics_length; i++){
      offset += this->topics[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_master;
      arrToVar(length_master, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_master; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_master-1]=0;
      this->master = (char *)(inbuffer + offset-1);
      offset += length_master;
      uint32_t nodes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->nodes_length);
      if(nodes_lengthT > nodes_length)
        this->nodes = (ros_topology_msgs::Node*)realloc(this->nodes, nodes_lengthT * sizeof(ros_topology_msgs::Node));
      nodes_length = nodes_lengthT;
      for( uint32_t i = 0; i < nodes_length; i++){
      offset += this->st_nodes.deserialize(inbuffer + offset);
        memcpy( &(this->nodes[i]), &(this->st_nodes), sizeof(ros_topology_msgs::Node));
      }
      uint32_t topics_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->topics_length);
      if(topics_lengthT > topics_length)
        this->topics = (ros_topology_msgs::Topic*)realloc(this->topics, topics_lengthT * sizeof(ros_topology_msgs::Topic));
      topics_length = topics_lengthT;
      for( uint32_t i = 0; i < topics_length; i++){
      offset += this->st_topics.deserialize(inbuffer + offset);
        memcpy( &(this->topics[i]), &(this->st_topics), sizeof(ros_topology_msgs::Topic));
      }
     return offset;
    }

    const char * getType(){ return "ros_topology_msgs/Graph"; };
    const char * getMD5(){ return "01c216943d54a2b673ba09f40ec3fe51"; };

  };

}
#endif