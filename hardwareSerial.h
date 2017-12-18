#ifndef _DRIVER_H_
#define _DRIVER_H_

#include <iostream>
#include <boost/thread.hpp>
#include <boost/asio.hpp>

using namespace boost::asio;
using namespace std;

class BSPSerial
{
private:
    bool is_open_;
    bool is_configure_;

    uint32_t  baud_rate_;
    boost::mutex mutex_;
    std::string  port_;

    boost::system::error_code error_;
    boost::asio::io_service   ios_;
    boost::asio::serial_port* serial_port_;

    boost::thread*    thread_;
    boost::thread::id thread_id_;

    uint8_t buffer_[256];
public:
    enum open_state
    {
        OPEN,
        CLOSE,
        EXCEPTION
    };

    BSPSerial():is_configure_(false),is_open_(CLOSE),thread_(NULL)
    {
        serial_port_=new boost::asio::serial_port(ios_);
    }

    virtual ~BSPSerial()
    {
        if(serial_port_)  delete serial_port_;
        if(thread_)       delete thread_;
    }

    int open(const std::string& port="/dev/ttyUSB0", uint32_t baud_rate=115200)
    {
        boost::system::error_code serial_state;

        if(is_configure_ == false)
        {
            is_configure_ = true;
            while(is_open_ != OPEN)
            {
                if(!serial_port_)
                {
                    std::cerr<<"Boost can't allcate memory."<<std::endl;
                    return -1;
                }
                try
                {
                    port_ = port;
                    baud_rate_ = baud_rate;
                    if(serial_port_)
                    {
                        serial_state = serial_port_->open(port_, error_);
                        serial_port_->set_option(boost::asio::serial_port_base::baud_rate(baud_rate_),error_);
                        serial_port_->set_option(serial_port::flow_control(serial_port::flow_control::none));
                        serial_port_->set_option(serial_port::parity(serial_port::parity::none));
                        serial_port_->set_option(serial_port::stop_bits(serial_port::stop_bits::one));
                        serial_port_->set_option(serial_port::character_size(8));
                        is_open_ = OPEN;
                    }
                }
                catch(boost::exception& e)
                {
                    is_open_ = EXCEPTION;
                    switch(serial_state.value())
                    {
                    case 2: std::cerr<<"Serial Disonnected."<<std::endl;break;
                    case 13:std::cerr<<"Serial Permission Denied."<<std::endl;break;
                    default:std::cerr<<"Serial Unknown Error."<<std::endl;
                    }
                    sleep(1);
                }
            }
        }
    }

    uint8_t read()
    {
        uint8_t tmp = '\0';
        try
        {
            boost::asio::read(*serial_port_, boost::asio::buffer(&tmp,1));
        }
        catch(boost::exception& e)
        {
            close();
            std::cerr<<"[Disconnected physically] Read error,"<<std::endl;
            open(port_, baud_rate_);
        }
        return tmp;
    }

    int write(uint8_t* data,uint32_t size)
    {
        try
        {
            size_t len =  boost::asio::write(*serial_port_, boost::asio::buffer(data, size), error_);
            if(size != len)
            {
                std::cerr<<"[Err] Write error."<<std::endl;
                close();
                open(port_, baud_rate_);
                sleep(1);
            }
        }
        catch(boost::exception& e)
        {
            std::cerr<<"[Disconnected physically] Write error."<<std::endl;
            close();
            open(port_, baud_rate_);
        }
        return 0;
    }

    void close(void)
    {
        if(is_open_ == OPEN)
        {
            is_open_ = CLOSE;
            is_configure_ = false;
            serial_port_->close();
        }
    }

    virtual void doDecode(uint8_t data,std::size_t len){

    }

};


class HardwareSerial
{
public:
    HardwareSerial()
    {
        serial = new BSPSerial();
    }

    void init()
    {
        serial->open("/dev/ttyUSB0",115200);
    }

    uint8_t read()
    {
        return serial->read();
    }

    int write(uint8_t* data, int size)
    {
        return serial->write((uint8_t*)data,size);
    }

    int close()
    {
        serial->close();
    }
    unsigned long time(){return 0;}
protected:
    BSPSerial* serial;
};


#endif
