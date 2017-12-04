#ifndef _DRIVER_H_
#define _DRIVER_H_

#include <iostream>
#include <sys/select.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <vector>

class TCPServer
{
private:
    typedef enum{
        error,
        ok
    }state;

    int init_state;
    int accept_state;

    int  fd;         //server socket file descri
    int  client_fd;  //client socket file descri

    int  read_len;

    struct sockaddr_in local_addr;
    struct sockaddr_in remote_addr;

    bool close_;

    void Warn(const char* words)
    {
        std::cerr<<"[WARN] "<<words<<std::endl;
    }
    void Error(const char* words)
    {
        std::cerr<<"[ERROR] "<<words<<std::endl;
    }
    void Info(const char* words)
    {
        std::cout<<"[INFO] "<<words<<std::endl;
    }

    int getSocket(){
        int opt = 1;
        fd =socket( AF_INET, SOCK_STREAM, 0 );
        setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
        if(-1 == fd){
            Error("Error, fd is -1");
        }
        return fd;
    }

    int wait_client()
    {
        accept_state = error;
        while(accept_state == error)
        {
            listen(fd, 10);
            int sin_size=sizeof(struct sockaddr_in);
            client_fd = accept(fd,  (struct sockaddr*) &remote_addr, (socklen_t*)&sin_size);
            if(client_fd < 0){
                Error("Accept error in spin()");
                accept_state = error;
                continue;
            }
            accept_state = ok;
            sleep(1);
        }
    }


public:

    TCPServer(int port=6000):init_state(error),close_(false)
    {
        if(port < 0 )
        {
            port = 6000;
            Info("Port is invalid, Use default port 6000.");
        }

        while(init_state == error && (!close_))
        {
            try
            {
                fd = getSocket();
                if(fd < 0){
                    Error("Error in init(), get socket fail");
                    init_state = error;
                }
                 //服务器端网络地址结构体
                memset(&local_addr,0,sizeof(local_addr)); //数据初始化--清零
                local_addr.sin_family=AF_INET; //设置为IP通信
                local_addr.sin_addr.s_addr=htons(INADDR_ANY);//服务器IP地址
                local_addr.sin_port = htons(port); //服务器端口号
                int bind_result = bind(fd, (struct sockaddr*) &local_addr, sizeof(struct sockaddr));
                if(bind_result < 0){
                    Error("Bind Error in init()");
                    init_state = error;
                    sleep(1);
                    continue;
                }
                init_state = ok;
            }
            catch(std::exception& e)
            {
                Error("Port bind error in init()");
                sleep(1);
            }
        }
        Info("Binding success.Listen port.");
    }

    int send(const char* str)
    {
       int len = write(client_fd, str, strlen(str));
       if(len <= 0)
       {
           return 1;
       }
       return 0;
    }

    int recv(uint8_t* data)
    {
        int len = read(client_fd, data, 1);
        if(len <= 0)
        {
            Error("Connection may interrupt. Waiting connection.");
            close(client_fd);
            wait_client();
            Info("Connected.");
        }
        return len;
    }

};

class Hardware
{
public:
    virtual int open();
    virtual int close();
    virtual int read(uint8_t* data);
    virtual int write(uint8_t* data);
    virtual int check();
};

class HardwareTCPServer
{
  public:
    virtual ~HardwareTCPServer()
    {
        delete tcp;
    }

    virtual int open()
    {
        if(!tcp)
        {
            return 1;
        }
        tcp = new TCPServer(6000);
        return 0;
    }

    int read(uint8_t* data)
    {
        int size = 0;
        size = tcp->recv(data);
        return size;
    }

    int write(uint8_t* data)
    {

    }

    unsigned long time()
    {
        return 0;
    }

  protected:
    TCPServer* tcp;
};


#endif
