#pragma once 

#include <iostream>
#include <string> 
#include <vector>
#include <semaphore.h>

#define NUM 256

class data_pool
{
  public:
    data_pool(int _cap = NUM);
    void get_message(std::string& out_message);
    void put_message(const std::string& in_message);
    ~data_pool();

  private:
    std::vector<std::string> pool;
    int cap;
    sem_t space_sem;
    sem_t message_sem;
    int consume_step;
    int product_step;
};
