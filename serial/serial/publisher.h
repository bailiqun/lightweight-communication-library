#ifndef _SERIAL_PUBLISHER_H_
#define _SERIAL_PUBLISHER_H_

#include "node_handle.h"

namespace serial {

  /* Generic Publisher */
  class Publisher
  {
    public:
      Publisher( const char* topic_name, Msg* msg, int endpoint = ID_PUBLISHER) :
        topic_(topic_name),
        msg_(msg),
        endpoint_(endpoint) {}

      int publish(const Msg * msg) { return nh_->publish(id_, msg); }
      int getEndpointType(){ return endpoint_; }

      const char * topic_;
      Msg *msg_;

      // id_ and no_ are set by NodeHandle when we advertise
      int id_;
      NodeHandleBase* nh_;

    private:
      int endpoint_;
  };

}

#endif
