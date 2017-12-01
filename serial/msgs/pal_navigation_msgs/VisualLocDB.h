#ifndef _ROS_pal_navigation_msgs_VisualLocDB_h
#define _ROS_pal_navigation_msgs_VisualLocDB_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

  class VisualLocDB : public ros::Msg
  {
    public:
      uint32_t documents_length;
      typedef uint8_t _documents_type;
      _documents_type st_documents;
      _documents_type * documents;
      uint32_t tree_length;
      typedef uint8_t _tree_type;
      _tree_type st_tree;
      _tree_type * tree;
      uint32_t weights_length;
      typedef uint8_t _weights_type;
      _weights_type st_weights;
      _weights_type * weights;

    VisualLocDB():
      documents_length(0), documents(NULL),
      tree_length(0), tree(NULL),
      weights_length(0), weights(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->documents_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->documents_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->documents_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->documents_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->documents_length);
      for( uint32_t i = 0; i < documents_length; i++){
      *(outbuffer + offset + 0) = (this->documents[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->documents[i]);
      }
      *(outbuffer + offset + 0) = (this->tree_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tree_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tree_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tree_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tree_length);
      for( uint32_t i = 0; i < tree_length; i++){
      *(outbuffer + offset + 0) = (this->tree[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tree[i]);
      }
      *(outbuffer + offset + 0) = (this->weights_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->weights_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->weights_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->weights_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->weights_length);
      for( uint32_t i = 0; i < weights_length; i++){
      *(outbuffer + offset + 0) = (this->weights[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->weights[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t documents_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      documents_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      documents_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      documents_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->documents_length);
      if(documents_lengthT > documents_length)
        this->documents = (uint8_t*)realloc(this->documents, documents_lengthT * sizeof(uint8_t));
      documents_length = documents_lengthT;
      for( uint32_t i = 0; i < documents_length; i++){
      this->st_documents =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_documents);
        memcpy( &(this->documents[i]), &(this->st_documents), sizeof(uint8_t));
      }
      uint32_t tree_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tree_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tree_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tree_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tree_length);
      if(tree_lengthT > tree_length)
        this->tree = (uint8_t*)realloc(this->tree, tree_lengthT * sizeof(uint8_t));
      tree_length = tree_lengthT;
      for( uint32_t i = 0; i < tree_length; i++){
      this->st_tree =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_tree);
        memcpy( &(this->tree[i]), &(this->st_tree), sizeof(uint8_t));
      }
      uint32_t weights_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      weights_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      weights_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      weights_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->weights_length);
      if(weights_lengthT > weights_length)
        this->weights = (uint8_t*)realloc(this->weights, weights_lengthT * sizeof(uint8_t));
      weights_length = weights_lengthT;
      for( uint32_t i = 0; i < weights_length; i++){
      this->st_weights =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_weights);
        memcpy( &(this->weights[i]), &(this->st_weights), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/VisualLocDB"; };
    const char * getMD5(){ return "ecd1514e0345ae95252fcd0c3269725c"; };

  };

}
#endif