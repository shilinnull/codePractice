#pragma once

#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>

class Request
{
public:
    Request()
    {}

    bool Serialize(std::string *out)
    {
        Json::Value root;
        root["x"] = _x;
        root["y"] = _y;
        root["oper"] = _oper;
    
        Json::StyledWriter writer;
        *out = writer.write(root);
        
        if(out->empty())
            return false;
        return true;
    }

    bool Deserialize(std::string &in)
    {
        Json::Reader reader;
        Json::Value root;
        if(!reader.parse(in, root))
            return false;

        _x = root["x"].asInt();
        _y = root["y"].asInt();
        _oper = root["oper"].asInt();
        return true;
    }
    ~Request(){}
private:
    int _x;
    int _y;
    char _oper;
};



class Response
{
public:
    Response()
    {}

    bool Serialize(std::string *out)
    {
        Json::Value root;
        root["result"] = _result;
        root["code"] = _code;
    
        Json::StyledWriter writer;
        *out = writer.write(root);
        
        if(out->empty())
            return false;
        return true;
    }

    bool Deserialize(std::string &in)
    {
        Json::Reader reader;
        Json::Value root;
        if(!reader.parse(in, root))
            return false;

        _result = root["result"].asInt();
        _code = root["code"].asInt();
        return true;
    }
    
    ~Response(){}
private:
    int _result;
    char _code;
};