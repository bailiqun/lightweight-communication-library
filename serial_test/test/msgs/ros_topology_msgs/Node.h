#ifndef _ROS_ros_topology_msgs_Node_h
#define _ROS_ros_topology_msgs_Node_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros_topology_msgs/Connection.h"
#include "ros_topology_msgs/Service.h"

namespace ros_topology_msgs
{

  class Node : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _uri_type;
      _uri_type uri;
      uint32_t publishes_length;
      typedef char* _publishes_type;
      _publishes_type st_publishes;
      _publishes_type * publishes;
      uint32_t subscribes_length;
      typedef char* _subscribes_type;
      _subscribes_type st_subscribes;
      _subscribes_type * subscribes;
      uint32_t connections_length;
      typedef ros_topology_msgs::Connection _connections_type;
      _connections_type st_connections;
      _connections_type * connections;
      uint32_t provides_length;
      typedef ros_topology_msgs::Service _provides_type;
      _provides_type st_provides;
      _provides_type * provides;

    Node():
      name(""),
      uri(""),
      publishes_length(0), publishes(NULL),
      subscribes_length(0), subscribes(NULL),
      connections_length(0), connections(NULL),
      provides_length(0), provides(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_uri = strlen(this->uri);
      varToArr(outbuffer + offset, length_uri);
      offset += 4;
      memcpy(outbuffer + offset, this->uri, length_uri);
      offset += length_uri;
      *(outbuffer + offset + 0) = (this->publishes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->publishes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->publishes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->publishes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->publishes_length);
      for( uint32_t i = 0; i < publishes_length; i++){
      uint32_t length_publishesi = strlen(this->publishes[i]);
      varToArr(outbuffer + offset, length_publishesi);
      offset += 4;
      memcpy(outbuffer + offset, this->publishes[i], length_publishesi);
      offset += length_publishesi;
      }
      *(outbuffer + offset + 0) = (this->subscribes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->subscribes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->subscribes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->subscribes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->subscribes_length);
      for( uint32_t i = 0; i < subscribes_length; i++){
      uint32_t length_subscribesi = strlen(this->subscribes[i]);
      varToArr(outbuffer + offset, length_subscribesi);
      offset += 4;
      memcpy(outbuffer + offset, this->subscribes[i], length_subscribesi);
      offset += length_subscribesi;
      }
      *(outbuffer + offset + 0) = (this->connections_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->connections_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->connections_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->connections_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->connections_length);
      for( uint32_t i = 0; i < connections_length; i++){
      offset += this->connections[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->provides_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->provides_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->provides_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->provides_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->provides_length);
      for( uint32_t i = 0; i < provides_length; i++){
      offset += this->provides[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_uri;
      arrToVar(length_uri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_uri-1]=0;
      this->uri = (char *)(inbuffer + offset-1);
      offset += length_uri;
      uint32_t publishes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      publishes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      publishes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      publishes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->publishes_length);
      if(publishes_lengthT > publishes_length)
        this->publishes = (char**)realloc(this->publishes, publishes_lengthT * sizeof(char*));
      publishes_length = publishes_lengthT;
      for( uint32_t i = 0; i < publishes_length; i++){
      uint32_t length_st_publishes;
      arrToVar(length_st_publishes, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_publishes; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_publishes-1]=0;
      this->st_publishes = (char *)(inbuffer + offset-1);
      offset += length_st_publishes;
        memcpy( &(this->publishes[i]), &(this->st_publishes), sizeof(char*));
      }
      uint32_t subscribes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      subscribes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      subscribes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      subscribes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->subscribes_length);
      if(subscribes_lengthT > subscribes_length)
        this->subscribes = (char**)realloc(this->subscribes, subscribes_lengthT * sizeof(char*));
      subscribes_length = subscribes_lengthT;
      for( uint32_t i = 0; i < subscribes_length; i++){
      uint32_t length_st_subscribes;
      arrToVar(length_st_subscribes, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_subscribes; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_subscribes-1]=0;
      this->st_subscribes = (char *)(inbuffer + offset-1);
      offset += length_st_subscribes;
        memcpy( &(this->subscribes[i]), &(this->st_subscribes), sizeof(char*));
      }
      uint32_t connections_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      connections_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      connections_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      connections_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->connections_length);
      if(connections_lengthT > connections_length)
        this->connections = (ros_topology_msgs::Connection*)realloc(this->connections, connections_lengthT * sizeof(ros_topology_msgs::Connection));
      connections_length = connections_lengthT;
      for( uint32_t i = 0; i < connections_length; i++){
      offset += this->st_connections.deserialize(inbuffer + offset);
        memcpy( &(this->connections[i]), &(this->st_connections), sizeof(ros_topology_msgs::Connection));
      }
      uint32_t provides_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      provides_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      provides_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      provides_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->provides_length);
      if(provides_lengthT > provides_length)
        this->provides = (ros_topology_msgs::Service*)realloc(this->provides, provides_lengthT * sizeof(ros_topology_msgs::Service));
      provides_length = provides_lengthT;
      for( uint32_t i = 0; i < provides_length; i++){
      offset += this->st_provides.deserialize(inbuffer + offset);
        memcpy( &(this->provides[i]), &(this->st_provides), sizeof(ros_topology_msgs::Service));
      }
     return offset;
    }

    const char * getType(){ return "ros_topology_msgs/Node"; };
    const char * getMD5(){ return "e793d9f25902b39f1451f272b3499991"; };

  };

}
#endif