#pragma once 

#include <iostream>
#include <string>
#include <json/json.h>

//nick_name("zs"),school("XUST"),message("nihao"),type("Nonae") -> ""
//"{nick_name : "zs", school : "XUST",message : "nihao",type : "None"}"

class data 
{
  public:
    data();
    void serialize(std::string& out_string);
    void unserialize(std::string& in_string);
    ~data();

  public:
    std::string nick_name;
    std::string school;
    std::string message;
    std::string type;
};
