#ifndef _ROS_pal_vision_msgs_FaceRecognitionFeedback_h
#define _ROS_pal_vision_msgs_FaceRecognitionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_vision_msgs
{

  class FaceRecognitionFeedback : public ros::Msg
  {
    public:
      typedef uint8_t _order_id_type;
      _order_id_type order_id;
      uint32_t names_length;
      typedef char* _names_type;
      _names_type st_names;
      _names_type * names;
      uint32_t confidence_length;
      typedef float _confidence_type;
      _confidence_type st_confidence;
      _confidence_type * confidence;

    FaceRecognitionFeedback():
      order_id(0),
      names_length(0), names(NULL),
      confidence_length(0), confidence(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->order_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->order_id);
      *(outbuffer + offset + 0) = (this->names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->names_length);
      for( uint32_t i = 0; i < names_length; i++){
      uint32_t length_namesi = strlen(this->names[i]);
      varToArr(outbuffer + offset, length_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->names[i], length_namesi);
      offset += length_namesi;
      }
      *(outbuffer + offset + 0) = (this->confidence_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->confidence_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->confidence_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->confidence_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence_length);
      for( uint32_t i = 0; i < confidence_length; i++){
      union {
        float real;
        uint32_t base;
      } u_confidencei;
      u_confidencei.real = this->confidence[i];
      *(outbuffer + offset + 0) = (u_confidencei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidencei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidencei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidencei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->order_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->order_id);
      uint32_t names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->names_length);
      if(names_lengthT > names_length)
        this->names = (char**)realloc(this->names, names_lengthT * sizeof(char*));
      names_length = names_lengthT;
      for( uint32_t i = 0; i < names_length; i++){
      uint32_t length_st_names;
      arrToVar(length_st_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_names-1]=0;
      this->st_names = (char *)(inbuffer + offset-1);
      offset += length_st_names;
        memcpy( &(this->names[i]), &(this->st_names), sizeof(char*));
      }
      uint32_t confidence_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      confidence_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      confidence_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      confidence_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->confidence_length);
      if(confidence_lengthT > confidence_length)
        this->confidence = (float*)realloc(this->confidence, confidence_lengthT * sizeof(float));
      confidence_length = confidence_lengthT;
      for( uint32_t i = 0; i < confidence_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_confidence;
      u_st_confidence.base = 0;
      u_st_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_confidence = u_st_confidence.real;
      offset += sizeof(this->st_confidence);
        memcpy( &(this->confidence[i]), &(this->st_confidence), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "pal_vision_msgs/FaceRecognitionFeedback"; };
    const char * getMD5(){ return "1354b7478703dcb5d9e033b8bdfafb3b"; };

  };

}
#endif