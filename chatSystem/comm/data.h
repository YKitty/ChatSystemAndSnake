#pragma once 

#include <iostream>
#include "json/json.h"

//nick_name("zs"),school("XUST"),message("nihao"),type -> ""
//JSON的格式"{"nick_name" : "zs","school":"XUST","message":"nihao","type":"None"}"
//JSON自动把上面的字符串转化成下面的字符串

class data 
{
  public:
    data(); 
    //序列化
    void serialize(std::string & in_string);
    //反序列化
    void unserialize(std::string & out_string);
    ~data();
 // private:
    std::string nick_name;
    std::string school;
    std::string message;
    std::string type;
};
