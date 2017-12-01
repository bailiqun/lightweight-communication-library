#ifndef _ROS_pal_detection_msgs_FaceDetection_h
#define _ROS_pal_detection_msgs_FaceDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point32.h"

namespace pal_detection_msgs
{

  class FaceDetection : public ros::Msg
  {
    public:
      typedef int32_t _x_type;
      _x_type x;
      typedef int32_t _y_type;
      _y_type y;
      typedef int32_t _width_type;
      _width_type width;
      typedef int32_t _height_type;
      _height_type height;
      typedef bool _eyesLocated_type;
      _eyesLocated_type eyesLocated;
      typedef int32_t _leftEyeX_type;
      _leftEyeX_type leftEyeX;
      typedef int32_t _leftEyeY_type;
      _leftEyeY_type leftEyeY;
      typedef int32_t _rightEyeX_type;
      _rightEyeX_type rightEyeX;
      typedef int32_t _rightEyeY_type;
      _rightEyeY_type rightEyeY;
      typedef geometry_msgs::Point32 _position_type;
      _position_type position;
      typedef const char* _name_type;
      _name_type name;
      typedef float _confidence_type;
      _confidence_type confidence;
      typedef const char* _expression_type;
      _expression_type expression;
      typedef float _expression_confidence_type;
      _expression_confidence_type expression_confidence;
      typedef float _emotion_anger_confidence_type;
      _emotion_anger_confidence_type emotion_anger_confidence;
      typedef float _emotion_disgust_confidence_type;
      _emotion_disgust_confidence_type emotion_disgust_confidence;
      typedef float _emotion_fear_confidence_type;
      _emotion_fear_confidence_type emotion_fear_confidence;
      typedef float _emotion_happiness_confidence_type;
      _emotion_happiness_confidence_type emotion_happiness_confidence;
      typedef float _emotion_neutral_confidence_type;
      _emotion_neutral_confidence_type emotion_neutral_confidence;
      typedef float _emotion_sadness_confidence_type;
      _emotion_sadness_confidence_type emotion_sadness_confidence;
      typedef float _emotion_surprise_confidence_type;
      _emotion_surprise_confidence_type emotion_surprise_confidence;
      enum { EXPRESSION_NEUTRAL = "neutral" };
      enum { EXPRESSION_SMILE = "smile" };
      enum { EXPRESSION_RAISED_BROWS = "raised brows" };
      enum { EXPRESSION_EYES_AWAY = "eyes away" };
      enum { EXPRESSION_SQUINTING = "squinting" };
      enum { EXPRESSION_FROWNING = "frowning" };

    FaceDetection():
      x(0),
      y(0),
      width(0),
      height(0),
      eyesLocated(0),
      leftEyeX(0),
      leftEyeY(0),
      rightEyeX(0),
      rightEyeY(0),
      position(),
      name(""),
      confidence(0),
      expression(""),
      expression_confidence(0),
      emotion_anger_confidence(0),
      emotion_disgust_confidence(0),
      emotion_fear_confidence(0),
      emotion_happiness_confidence(0),
      emotion_neutral_confidence(0),
      emotion_sadness_confidence(0),
      emotion_surprise_confidence(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        int32_t real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        int32_t real;
        uint32_t base;
      } u_width;
      u_width.real = this->width;
      *(outbuffer + offset + 0) = (u_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      union {
        int32_t real;
        uint32_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      union {
        bool real;
        uint8_t base;
      } u_eyesLocated;
      u_eyesLocated.real = this->eyesLocated;
      *(outbuffer + offset + 0) = (u_eyesLocated.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->eyesLocated);
      union {
        int32_t real;
        uint32_t base;
      } u_leftEyeX;
      u_leftEyeX.real = this->leftEyeX;
      *(outbuffer + offset + 0) = (u_leftEyeX.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_leftEyeX.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_leftEyeX.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_leftEyeX.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->leftEyeX);
      union {
        int32_t real;
        uint32_t base;
      } u_leftEyeY;
      u_leftEyeY.real = this->leftEyeY;
      *(outbuffer + offset + 0) = (u_leftEyeY.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_leftEyeY.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_leftEyeY.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_leftEyeY.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->leftEyeY);
      union {
        int32_t real;
        uint32_t base;
      } u_rightEyeX;
      u_rightEyeX.real = this->rightEyeX;
      *(outbuffer + offset + 0) = (u_rightEyeX.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rightEyeX.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rightEyeX.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rightEyeX.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rightEyeX);
      union {
        int32_t real;
        uint32_t base;
      } u_rightEyeY;
      u_rightEyeY.real = this->rightEyeY;
      *(outbuffer + offset + 0) = (u_rightEyeY.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rightEyeY.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rightEyeY.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rightEyeY.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rightEyeY);
      offset += this->position.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.real = this->confidence;
      *(outbuffer + offset + 0) = (u_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence);
      uint32_t length_expression = strlen(this->expression);
      varToArr(outbuffer + offset, length_expression);
      offset += 4;
      memcpy(outbuffer + offset, this->expression, length_expression);
      offset += length_expression;
      union {
        float real;
        uint32_t base;
      } u_expression_confidence;
      u_expression_confidence.real = this->expression_confidence;
      *(outbuffer + offset + 0) = (u_expression_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_expression_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_expression_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_expression_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->expression_confidence);
      union {
        float real;
        uint32_t base;
      } u_emotion_anger_confidence;
      u_emotion_anger_confidence.real = this->emotion_anger_confidence;
      *(outbuffer + offset + 0) = (u_emotion_anger_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_emotion_anger_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_emotion_anger_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_emotion_anger_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->emotion_anger_confidence);
      union {
        float real;
        uint32_t base;
      } u_emotion_disgust_confidence;
      u_emotion_disgust_confidence.real = this->emotion_disgust_confidence;
      *(outbuffer + offset + 0) = (u_emotion_disgust_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_emotion_disgust_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_emotion_disgust_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_emotion_disgust_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->emotion_disgust_confidence);
      union {
        float real;
        uint32_t base;
      } u_emotion_fear_confidence;
      u_emotion_fear_confidence.real = this->emotion_fear_confidence;
      *(outbuffer + offset + 0) = (u_emotion_fear_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_emotion_fear_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_emotion_fear_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_emotion_fear_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->emotion_fear_confidence);
      union {
        float real;
        uint32_t base;
      } u_emotion_happiness_confidence;
      u_emotion_happiness_confidence.real = this->emotion_happiness_confidence;
      *(outbuffer + offset + 0) = (u_emotion_happiness_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_emotion_happiness_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_emotion_happiness_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_emotion_happiness_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->emotion_happiness_confidence);
      union {
        float real;
        uint32_t base;
      } u_emotion_neutral_confidence;
      u_emotion_neutral_confidence.real = this->emotion_neutral_confidence;
      *(outbuffer + offset + 0) = (u_emotion_neutral_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_emotion_neutral_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_emotion_neutral_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_emotion_neutral_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->emotion_neutral_confidence);
      union {
        float real;
        uint32_t base;
      } u_emotion_sadness_confidence;
      u_emotion_sadness_confidence.real = this->emotion_sadness_confidence;
      *(outbuffer + offset + 0) = (u_emotion_sadness_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_emotion_sadness_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_emotion_sadness_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_emotion_sadness_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->emotion_sadness_confidence);
      union {
        float real;
        uint32_t base;
      } u_emotion_surprise_confidence;
      u_emotion_surprise_confidence.real = this->emotion_surprise_confidence;
      *(outbuffer + offset + 0) = (u_emotion_surprise_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_emotion_surprise_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_emotion_surprise_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_emotion_surprise_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->emotion_surprise_confidence);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        int32_t real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        int32_t real;
        uint32_t base;
      } u_width;
      u_width.base = 0;
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->width = u_width.real;
      offset += sizeof(this->width);
      union {
        int32_t real;
        uint32_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->height = u_height.real;
      offset += sizeof(this->height);
      union {
        bool real;
        uint8_t base;
      } u_eyesLocated;
      u_eyesLocated.base = 0;
      u_eyesLocated.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->eyesLocated = u_eyesLocated.real;
      offset += sizeof(this->eyesLocated);
      union {
        int32_t real;
        uint32_t base;
      } u_leftEyeX;
      u_leftEyeX.base = 0;
      u_leftEyeX.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_leftEyeX.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_leftEyeX.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_leftEyeX.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->leftEyeX = u_leftEyeX.real;
      offset += sizeof(this->leftEyeX);
      union {
        int32_t real;
        uint32_t base;
      } u_leftEyeY;
      u_leftEyeY.base = 0;
      u_leftEyeY.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_leftEyeY.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_leftEyeY.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_leftEyeY.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->leftEyeY = u_leftEyeY.real;
      offset += sizeof(this->leftEyeY);
      union {
        int32_t real;
        uint32_t base;
      } u_rightEyeX;
      u_rightEyeX.base = 0;
      u_rightEyeX.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rightEyeX.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rightEyeX.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rightEyeX.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rightEyeX = u_rightEyeX.real;
      offset += sizeof(this->rightEyeX);
      union {
        int32_t real;
        uint32_t base;
      } u_rightEyeY;
      u_rightEyeY.base = 0;
      u_rightEyeY.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rightEyeY.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rightEyeY.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rightEyeY.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rightEyeY = u_rightEyeY.real;
      offset += sizeof(this->rightEyeY);
      offset += this->position.deserialize(inbuffer + offset);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.base = 0;
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->confidence = u_confidence.real;
      offset += sizeof(this->confidence);
      uint32_t length_expression;
      arrToVar(length_expression, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_expression; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_expression-1]=0;
      this->expression = (char *)(inbuffer + offset-1);
      offset += length_expression;
      union {
        float real;
        uint32_t base;
      } u_expression_confidence;
      u_expression_confidence.base = 0;
      u_expression_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_expression_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_expression_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_expression_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->expression_confidence = u_expression_confidence.real;
      offset += sizeof(this->expression_confidence);
      union {
        float real;
        uint32_t base;
      } u_emotion_anger_confidence;
      u_emotion_anger_confidence.base = 0;
      u_emotion_anger_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_emotion_anger_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_emotion_anger_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_emotion_anger_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->emotion_anger_confidence = u_emotion_anger_confidence.real;
      offset += sizeof(this->emotion_anger_confidence);
      union {
        float real;
        uint32_t base;
      } u_emotion_disgust_confidence;
      u_emotion_disgust_confidence.base = 0;
      u_emotion_disgust_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_emotion_disgust_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_emotion_disgust_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_emotion_disgust_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->emotion_disgust_confidence = u_emotion_disgust_confidence.real;
      offset += sizeof(this->emotion_disgust_confidence);
      union {
        float real;
        uint32_t base;
      } u_emotion_fear_confidence;
      u_emotion_fear_confidence.base = 0;
      u_emotion_fear_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_emotion_fear_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_emotion_fear_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_emotion_fear_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->emotion_fear_confidence = u_emotion_fear_confidence.real;
      offset += sizeof(this->emotion_fear_confidence);
      union {
        float real;
        uint32_t base;
      } u_emotion_happiness_confidence;
      u_emotion_happiness_confidence.base = 0;
      u_emotion_happiness_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_emotion_happiness_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_emotion_happiness_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_emotion_happiness_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->emotion_happiness_confidence = u_emotion_happiness_confidence.real;
      offset += sizeof(this->emotion_happiness_confidence);
      union {
        float real;
        uint32_t base;
      } u_emotion_neutral_confidence;
      u_emotion_neutral_confidence.base = 0;
      u_emotion_neutral_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_emotion_neutral_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_emotion_neutral_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_emotion_neutral_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->emotion_neutral_confidence = u_emotion_neutral_confidence.real;
      offset += sizeof(this->emotion_neutral_confidence);
      union {
        float real;
        uint32_t base;
      } u_emotion_sadness_confidence;
      u_emotion_sadness_confidence.base = 0;
      u_emotion_sadness_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_emotion_sadness_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_emotion_sadness_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_emotion_sadness_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->emotion_sadness_confidence = u_emotion_sadness_confidence.real;
      offset += sizeof(this->emotion_sadness_confidence);
      union {
        float real;
        uint32_t base;
      } u_emotion_surprise_confidence;
      u_emotion_surprise_confidence.base = 0;
      u_emotion_surprise_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_emotion_surprise_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_emotion_surprise_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_emotion_surprise_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->emotion_surprise_confidence = u_emotion_surprise_confidence.real;
      offset += sizeof(this->emotion_surprise_confidence);
     return offset;
    }

    const char * getType(){ return "pal_detection_msgs/FaceDetection"; };
    const char * getMD5(){ return "a17fdb6b06e8f6a7b02b1e50262a787c"; };

  };

}
#endif