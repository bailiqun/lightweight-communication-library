#ifndef _VELOCITY_MSG_H_
#define _VELOCITY_MSG_H_

#include "serial/msg.h"

class VelocityMsg: public serial::Msg
{
public:
    virtual int serialize(uint8_t* outbuffer) const
    {
        DataType_Float v1;
        DataType_Float v2;
        DataType_Float v3;
        DataType_Float v4;

        v1.raw = this->v1;
        v2.raw = this->v2;
        v3.raw = this->v3;
        v4.raw = this->v4;

        *(outbuffer + 0) = v1.byte[0];
        *(outbuffer + 1) = v1.byte[1];
        *(outbuffer + 2) = v1.byte[2];
        *(outbuffer + 3) = v1.byte[3];

        *(outbuffer + 4) = v2.byte[0];
        *(outbuffer + 5) = v2.byte[1];
        *(outbuffer + 6) = v2.byte[2];
        *(outbuffer + 7) = v2.byte[3];

        *(outbuffer + 8) =  v3.byte[0];
        *(outbuffer + 9) =  v3.byte[1];
        *(outbuffer + 10) = v3.byte[2];
        *(outbuffer + 11) = v3.byte[3];

        *(outbuffer + 12) = v4.byte[0];
        *(outbuffer + 13) = v4.byte[1];
        *(outbuffer + 14) = v4.byte[2];
        *(outbuffer + 15) = v4.byte[3];

        return 0;
    }

    virtual int deserialize(uint8_t* inbuffer)
    {
        DataType_Float v1;
        DataType_Float v2;
        DataType_Float v3;
        DataType_Float v4;

        v1.byte[0] = *(inbuffer + 0);
        v1.byte[1] = *(inbuffer + 1);
        v1.byte[2] = *(inbuffer + 2);
        v1.byte[3] = *(inbuffer + 3);

        v2.byte[0] = *(inbuffer + 4);
        v2.byte[1] = *(inbuffer + 5);
        v2.byte[2] = *(inbuffer + 6);
        v2.byte[3] = *(inbuffer + 7);

        v3.byte[0] = *(inbuffer + 8);
        v3.byte[1] = *(inbuffer + 9);
        v3.byte[2] = *(inbuffer + 10);
        v3.byte[3] = *(inbuffer + 11);

        v4.byte[0] = *(inbuffer + 12);
        v4.byte[1] = *(inbuffer + 13);
        v4.byte[2] = *(inbuffer + 14);
        v4.byte[3] = *(inbuffer + 15);

        this->v1 = v1.raw;
        this->v2 = v2.raw;
        this->v3 = v3.raw;
        this->v4 = v4.raw;

        return 0;
    }

    virtual const char* getType() {return "WheelVolcity";}
    virtual const char* getMD5()  {return "xcjefidkdgj32fds0g";}
    int getByte() {return 16;}

    typedef union
    {
        uint8_t byte[4];
        float raw;
    }DataType_Float;

    float v1;
    float v2;
    float v3;
    float v4;
};

#endif
