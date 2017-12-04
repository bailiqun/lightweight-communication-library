#include <iostream>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "serial.h"

using namespace std;


namespace std_msgs
{

  class String : public serial::Msg
  {
    public:
      typedef const char* _data_type;
      _data_type data;

    String():
      data("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_data = strlen(this->data);
      varToArr(outbuffer + offset, length_data);
      offset += 4;
      memcpy(outbuffer + offset, this->data, length_data);
      offset += length_data;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_data=0;
      arrToVar(length_data, (inbuffer + offset));
      this->data = (char *)(inbuffer);
      return offset;
    }

    const char * getType(){ return "std_msgs/String"; }
    const char * getMD5(){ return "992ce8a1687cec8c8bd883ec73ca41d1"; }

  };

}

class DummyMsg
{
public:
  int serialize(unsigned char *outbuffer) const { return 0; }
  int deserialize(unsigned char *inbuffer) { return 0; }
  const char * getType() { return ""; }
  const char * getMD5() { return ""; }
};

class DummyClass
{
public:
  static void staticCallback(const DummyMsg& msg)
  {
    //callbackCalled = true;
  }
  void memberCallback(const DummyMsg& msg)
  {
    std::cout<<"DummyClass::memberCallback()"<<std::endl;
  }
};

void Callback(const std_msgs::String& msg)
{
  std::cout<<"Callback()"<<msg.data<<std::endl;
}

int main(int argc, char *argv[])
{

    NodeHandleTCP n;
    DummyClass cl;

    n.subscribe<std_msgs::String>(2,"std_msgs::String", &Callback);
    n.subscribe<DummyMsg>(1,"DummyMsg", &DummyClass::memberCallback, &cl);

    n.spinOnce();
    return 0;
}
