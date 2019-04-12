#pragma once 

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "window.h"

#define SIZE 1024//接收数据的最大长度

class udp_client 
{
  public:
    udp_client(std::string server_ip, int server_port);
    void init_client();
    void recv_data(std::string& out_string);
    void send_data(const std::string& in_string);
    ~udp_client();

  private:
    int sock;
    struct sockaddr_in server;
};
