#ifndef _ODOMETRY_MSG_H_
#define _ODOMETRY_MSG_H_

#include "serial/msg.h"

class OdometryMsg: public serial::Msg
{
public:
    OdometryMsg()
    {
        x.raw = 0;
        y.raw = 0;
        z.raw = 0;
    }

    virtual int serialize(uint8_t* outbuffer) const
    {
        *(outbuffer + 0) = x.byte[0];
        *(outbuffer + 1) = x.byte[1];
        *(outbuffer + 2) = x.byte[2];
        *(outbuffer + 3) = x.byte[3];

        *(outbuffer + 4) = y.byte[0];
        *(outbuffer + 5) = y.byte[1];
        *(outbuffer + 6) = y.byte[2];
        *(outbuffer + 7) = y.byte[3];

        *(outbuffer + 8) = z.byte[0];
        *(outbuffer + 9) = z.byte[1];
        *(outbuffer + 10) = z.byte[2];
        *(outbuffer + 11) = z.byte[3];
        return 0;
    }

    virtual int deserialize(uint8_t* inbuffer)
    {
        x.byte[0] = *(inbuffer + 0);
        x.byte[1] = *(inbuffer + 1);
        x.byte[2] = *(inbuffer + 2);
        x.byte[3] = *(inbuffer + 3);

        y.byte[0] = *(inbuffer + 4);
        y.byte[1] = *(inbuffer + 5);
        y.byte[2] = *(inbuffer + 6);
        y.byte[3] = *(inbuffer + 7);

        z.byte[0] = *(inbuffer + 8);
        z.byte[1] = *(inbuffer + 9);
        z.byte[2] = *(inbuffer + 10);
        z.byte[3] = *(inbuffer + 11);
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

    DataType_Float x;
    DataType_Float y;
    DataType_Float z;
};

#endif
