#ifndef _ROS_aruco_mapping_ArucoMarker_h
#define _ROS_aruco_mapping_ArucoMarker_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"

namespace aruco_mapping
{

  class ArucoMarker : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _visibility_type;
      _visibility_type visibility;
      typedef int32_t _numberOfMarkers_type;
      _numberOfMarkers_type numberOfMarkers;
      typedef geometry_msgs::Pose _globalPose_type;
      _globalPose_type globalPose;
      uint32_t markersID_length;
      typedef int32_t _markersID_type;
      _markersID_type st_markersID;
      _markersID_type * markersID;
      uint32_t markersPose_length;
      typedef geometry_msgs::Pose _markersPose_type;
      _markersPose_type st_markersPose;
      _markersPose_type * markersPose;
      uint32_t cameraPose_length;
      typedef geometry_msgs::Pose _cameraPose_type;
      _cameraPose_type st_cameraPose;
      _cameraPose_type * cameraPose;

    ArucoMarker():
      header(),
      visibility(0),
      numberOfMarkers(0),
      globalPose(),
      markersID_length(0), markersID(NULL),
      markersPose_length(0), markersPose(NULL),
      cameraPose_length(0), cameraPose(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_visibility;
      u_visibility.real = this->visibility;
      *(outbuffer + offset + 0) = (u_visibility.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->visibility);
      union {
        int32_t real;
        uint32_t base;
      } u_numberOfMarkers;
      u_numberOfMarkers.real = this->numberOfMarkers;
      *(outbuffer + offset + 0) = (u_numberOfMarkers.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_numberOfMarkers.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_numberOfMarkers.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_numberOfMarkers.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->numberOfMarkers);
      offset += this->globalPose.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->markersID_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->markersID_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->markersID_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->markersID_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->markersID_length);
      for( uint32_t i = 0; i < markersID_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_markersIDi;
      u_markersIDi.real = this->markersID[i];
      *(outbuffer + offset + 0) = (u_markersIDi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_markersIDi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_markersIDi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_markersIDi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->markersID[i]);
      }
      *(outbuffer + offset + 0) = (this->markersPose_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->markersPose_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->markersPose_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->markersPose_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->markersPose_length);
      for( uint32_t i = 0; i < markersPose_length; i++){
      offset += this->markersPose[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cameraPose_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cameraPose_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cameraPose_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cameraPose_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cameraPose_length);
      for( uint32_t i = 0; i < cameraPose_length; i++){
      offset += this->cameraPose[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_visibility;
      u_visibility.base = 0;
      u_visibility.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->visibility = u_visibility.real;
      offset += sizeof(this->visibility);
      union {
        int32_t real;
        uint32_t base;
      } u_numberOfMarkers;
      u_numberOfMarkers.base = 0;
      u_numberOfMarkers.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_numberOfMarkers.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_numberOfMarkers.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_numberOfMarkers.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->numberOfMarkers = u_numberOfMarkers.real;
      offset += sizeof(this->numberOfMarkers);
      offset += this->globalPose.deserialize(inbuffer + offset);
      uint32_t markersID_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      markersID_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      markersID_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      markersID_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->markersID_length);
      if(markersID_lengthT > markersID_length)
        this->markersID = (int32_t*)realloc(this->markersID, markersID_lengthT * sizeof(int32_t));
      markersID_length = markersID_lengthT;
      for( uint32_t i = 0; i < markersID_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_markersID;
      u_st_markersID.base = 0;
      u_st_markersID.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_markersID.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_markersID.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_markersID.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_markersID = u_st_markersID.real;
      offset += sizeof(this->st_markersID);
        memcpy( &(this->markersID[i]), &(this->st_markersID), sizeof(int32_t));
      }
      uint32_t markersPose_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      markersPose_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      markersPose_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      markersPose_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->markersPose_length);
      if(markersPose_lengthT > markersPose_length)
        this->markersPose = (geometry_msgs::Pose*)realloc(this->markersPose, markersPose_lengthT * sizeof(geometry_msgs::Pose));
      markersPose_length = markersPose_lengthT;
      for( uint32_t i = 0; i < markersPose_length; i++){
      offset += this->st_markersPose.deserialize(inbuffer + offset);
        memcpy( &(this->markersPose[i]), &(this->st_markersPose), sizeof(geometry_msgs::Pose));
      }
      uint32_t cameraPose_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cameraPose_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cameraPose_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cameraPose_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cameraPose_length);
      if(cameraPose_lengthT > cameraPose_length)
        this->cameraPose = (geometry_msgs::Pose*)realloc(this->cameraPose, cameraPose_lengthT * sizeof(geometry_msgs::Pose));
      cameraPose_length = cameraPose_lengthT;
      for( uint32_t i = 0; i < cameraPose_length; i++){
      offset += this->st_cameraPose.deserialize(inbuffer + offset);
        memcpy( &(this->cameraPose[i]), &(this->st_cameraPose), sizeof(geometry_msgs::Pose));
      }
     return offset;
    }

    const char * getType(){ return "aruco_mapping/ArucoMarker"; };
    const char * getMD5(){ return "9f58304cb815509a29efc7960d7023aa"; };

  };

}
#endif