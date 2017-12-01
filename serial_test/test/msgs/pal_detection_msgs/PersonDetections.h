#ifndef _ROS_pal_detection_msgs_PersonDetections_h
#define _ROS_pal_detection_msgs_PersonDetections_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pal_detection_msgs/PersonDetection.h"
#include "geometry_msgs/TransformStamped.h"

namespace pal_detection_msgs
{

  class PersonDetections : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t persons_length;
      typedef pal_detection_msgs::PersonDetection _persons_type;
      _persons_type st_persons;
      _persons_type * persons;
      typedef geometry_msgs::TransformStamped _camera_pose_type;
      _camera_pose_type camera_pose;

    PersonDetections():
      header(),
      persons_length(0), persons(NULL),
      camera_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->persons_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->persons_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->persons_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->persons_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->persons_length);
      for( uint32_t i = 0; i < persons_length; i++){
      offset += this->persons[i].serialize(outbuffer + offset);
      }
      offset += this->camera_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t persons_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      persons_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      persons_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      persons_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->persons_length);
      if(persons_lengthT > persons_length)
        this->persons = (pal_detection_msgs::PersonDetection*)realloc(this->persons, persons_lengthT * sizeof(pal_detection_msgs::PersonDetection));
      persons_length = persons_lengthT;
      for( uint32_t i = 0; i < persons_length; i++){
      offset += this->st_persons.deserialize(inbuffer + offset);
        memcpy( &(this->persons[i]), &(this->st_persons), sizeof(pal_detection_msgs::PersonDetection));
      }
      offset += this->camera_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_detection_msgs/PersonDetections"; };
    const char * getMD5(){ return "2e9459d911994b1f8ae4e54431f0f631"; };

  };

}
#endif