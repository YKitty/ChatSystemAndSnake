#include "udp_server.h"
#include <pthread.h>
#include <stdlib.h>

void Usage(std::string proc)
{
  std::cout << "Usage: " << proc << "port" << std::endl;
}

void* recv_message(void* arg)
{
  udp_server* sp = (udp_server*)arg;
  std::string message;
  while(1)
  {
    sp->recv_data(message);
    //方便调试
    std::cout << "debug: " << message << std::endl;
  }
}

void* send_message(void* arg)
{
  udp_server* sp = (udp_server*)arg;
  while(1)
  {
    sp->broadcast();
  }
}

//./chatSystem 8080
int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    Usage(argv[0]);
    return 1;
  }

  udp_server ser(atoi(argv[1]));
  ser.init_server();
  pthread_t r, s;
  pthread_create(&r, NULL, recv_message, (void*)&ser);
  pthread_create(&s, NULL, send_message, (void*)&ser);

  pthread_join(r, NULL);
  pthread_join(s, NULL);

  return 0;
}
