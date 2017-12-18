#ifndef _VELOCITY_MSG_H_
#define _VELOCITY_MSG_H_

#include "serial/msg.h"

class VelocityMsg3: public serial::Msg
{
public:
    virtual int serialize(uint8_t* outbuffer) const
    {
        DataType_Float vx;
        DataType_Float vy;
        DataType_Float vz;

        vx.raw = this->vx;
        vy.raw = this->vy;
        vz.raw = this->vz;

        *(outbuffer + 0) = vx.byte[0];
        *(outbuffer + 1) = vx.byte[1];
        *(outbuffer + 2) = vx.byte[2];
        *(outbuffer + 3) = vx.byte[3];

        *(outbuffer + 4) = vy.byte[0];
        *(outbuffer + 5) = vy.byte[1];
        *(outbuffer + 6) = vy.byte[2];
        *(outbuffer + 7) = vy.byte[3];

        *(outbuffer + 8) =  vz.byte[0];
        *(outbuffer + 9) =  vz.byte[1];
        *(outbuffer + 10) = vz.byte[2];
        *(outbuffer + 11) = vz.byte[3];

        return 0;
    }

    virtual int deserialize(uint8_t* inbuffer)
    {
        DataType_Float vx;
        DataType_Float vy;
        DataType_Float vz;

        vx.byte[0] = *(inbuffer + 0);
        vx.byte[1] = *(inbuffer + 1);
        vx.byte[2] = *(inbuffer + 2);
        vx.byte[3] = *(inbuffer + 3);

        vy.byte[0] = *(inbuffer + 4);
        vy.byte[1] = *(inbuffer + 5);
        vy.byte[2] = *(inbuffer + 6);
        vy.byte[3] = *(inbuffer + 7);

        vz.byte[0] = *(inbuffer + 8);
        vz.byte[1] = *(inbuffer + 9);
        vz.byte[2] = *(inbuffer + 10);
        vz.byte[3] = *(inbuffer + 11);

        this->vx = vx.raw;
        this->vy = vy.raw;
        this->vz = vz.raw;

        return 0;
    }

    virtual const char* getType() { return ""; }
    virtual const char* getMD5()  { return ""; }
    int   getByte() {return 12;}

    typedef union
    {
        uint8_t byte[4];
        float raw;
    }DataType_Float;

    float vx;//   m/s
    float vy;//   m/s
    float vz;//   rad/s
};

#endif
