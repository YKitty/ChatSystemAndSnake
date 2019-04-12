#include "data.h"

data::data()
{

}
    //序列化
void data::serialize(std::string &out_string)
{
 // Json::Value root;
  ValueObj root;
  root["nick_name"]=nick_name;
  root["school"]=school;
  root["message"]=message;
  root["type"]=type;
  Write mywrite;
  mywrite.run(root,out_string);
//#ifndef FAST 
////  Json::FastWriter w;
//#else 
//  Json::StyledWriter w;
//#endif
//  out_string = w.write(root);//序列化成一个字符串
}
    //反序列化
void data::unserialize(std::string &in_string)
{
 //  Json::Value root;
 //  Json::Reader r;
 //  r.parse(in_string,root,false);//反序列化
 //  nick_name = root["nick_name"].asString();
 //  school = root["school"].asString();
 //  message = root["message"].asString();
 //  type =root["type"].asString();
  ValueObj root;
  Read r;                                                            
  r.run(in_string,root);                                                             
  std::string nick_name1 = root["nick_name"];                                       
  std::string school1 = root["school"];                                             
  std::string message1 = root["message"];        
  std::string  type1 =root["type"];
  nick_name = nick_name1;
  school = school1;
  message=message1;
  type = type1;
}

data::~data()
{

}

//
//int main()
//{
//  data d;
//  d.nick_name = "平凡";
//  d.school="XUST";
//  d.message="hello";
//  d.type="None";
//  std::string out_string;
//  d.serialize(out_string);//序列化成out_string
//  std::cout<<out_string<<std::endl;
//}
