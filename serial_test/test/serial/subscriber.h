#ifndef _SERIAL_SUBSCRIBER_H_
#define _SERIAL_SUBSCRIBER_H_

#include <stdlib.h>
#include "msg.h"

namespace serial
{
    enum
    {
        ID_PUBLISHER = 0,
        ID_SUBSCRIBER = 1,
        ID_SERVICE_SERVER = 2,
        ID_SERVICE_CLIENT = 4,
        ID_PARAMETER_REQUEST = 6,
        ID_LOG = 7,
        ID_TIME = 10,
        ID_TX_STOP = 11
    };

    class Subscriber_
    {
    public:
        virtual void callback(unsigned char *data)=0;
        virtual int getEndpointType()=0;

        // id_ is set by NodeHandle when we advertise
        int id;

        virtual const char * getMsgType()=0;
        virtual const char * getMsgMD5()=0;
        const char * topic;
    };

    /* Bound function subscriber. */
    template<typename MsgT, typename ObjT=void>
    class Subscriber: public Subscriber_
    {
    public:
        typedef void(ObjT::*CallbackT)(const MsgT&);
        MsgT msg;

        Subscriber(const char * topic_name, CallbackT cb, ObjT* obj):
        cb_(cb),
        obj_(obj)
        {
            topic = topic_name;
        }

        virtual void callback(uint8_t* data)
        {
            msg.deserialize(data);
            (obj_->*cb_)(msg);
        }

        virtual const char * getMsgType() { return this->msg.getType(); }
        virtual const char * getMsgMD5() { return this->msg.getMD5(); }
        virtual int getEndpointType() { return endpoint_; }

        private:
        CallbackT cb_;
        ObjT* obj_;
        int endpoint_;
    };

    /* Standalone function subscriber. */
    template<typename MsgT>
    class Subscriber<MsgT, void>: public Subscriber_
    {
    public:
        typedef void(*CallbackT)(const MsgT&);
        MsgT msg;

        Subscriber(const char * topic_name, CallbackT cb) :
        cb_(cb)
        {
            topic = topic_name;
        }

        virtual void callback(unsigned char* data)
        {
            msg.deserialize(data);
            this->cb_(msg);
        }

        virtual const char * getMsgType() { return this->msg.getType(); }
        virtual const char * getMsgMD5() { return this->msg.getMD5(); }
        virtual int getEndpointType() { return endpoint_; }

    private:
        CallbackT cb_;
        int endpoint_;
    };
}

#endif
