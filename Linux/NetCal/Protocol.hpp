#pragma once

#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>

class Request
{
public:
    Request() : _x(0), _y(0), _oper(0)
    {
    }

    bool Serialize(std::string *out)
    {
        Json::Value root;
        root["x"] = _x;
        root["y"] = _y;
        root["oper"] = _oper;

        Json::StyledWriter writer;
        *out = writer.write(root);

        if (out->empty())
            return false;
        return true;
    }

    bool Deserialize(std::string &in)
    {
        Json::Reader reader;
        Json::Value root;
        if (!reader.parse(in, root))
            return false;

        _x = root["x"].asInt();
        _y = root["y"].asInt();
        _oper = root["oper"].asInt();
        return true;
    }

    int GetX()
    {
        return _x;
    }

    int GetY()
    {
        return _y;
    }

    char GetOper()
    {
        return _oper;
    }

    void SetX(int x)
    {
        _x = x;
    }

    void SetY(int y)
    {
        _y = y;
    }

    void SetOper(char oper)
    {
        _oper = oper;
    }

    ~Request() {}

private:
    int _x;
    int _y;
    char _oper;
};

class Response
{
public:
    Response() : _result(0), _code(0)
    {
    }

    bool Serialize(std::string *out)
    {
        Json::Value root;
        root["result"] = _result;
        root["code"] = _code;

        Json::StyledWriter writer;
        *out = writer.write(root);

        if (out->empty())
            return false;
        return true;
    }

    bool Deserialize(std::string &in)
    {
        Json::Reader reader;
        Json::Value root;
        if (!reader.parse(in, root))
            return false;

        _result = root["result"].asInt();
        _code = root["code"].asInt();
        return true;
    }

    void Print()
    {
        std::cout << "result: " << _result << " [" << _code << "]" << std::endl;
    }

    int GetResult()
    {
        return _result;
    }

    int GetCode()
    {
        return _code;
    }

    void SetResult(int result)
    {
        _result = result;
    }

    void SetCode(int code)
    {
        _code = code;
    }

    ~Response() {}

private:
    int _result;
    int _code;
};

static const std::string sep = "\r\n";

class ProtoCol
{
public:
    static std::string Package(const std::string &jsonstr)
    {
        if (jsonstr.empty())
            return std::string();

        std::string json_len = std::to_string(jsonstr.size());

        return json_len + sep + jsonstr + sep; // 有效载荷长度\r\n有效载荷内容\r\n
    }

    /**
     *  返回值说明：
     *              0:表示没有内容
     *             -1:表示错误字符
     *             <0: 表示解包后的字符串的长度
     */
    static int Unpack(std::string &origin_str, std::string *package)
    {
        if (!package)
            return 0;
        auto pos = origin_str.find(sep); // 查找\r\n
        if (pos == std::string::npos)
            return 0;

        std::string len_str = origin_str.substr(0, pos); // 截取有效载荷字符串
        if (!DigitSafeCheck(len_str))
            return -1;

        int digit_len = std::stoi(len_str);                                    // 获取有效载荷长度
        int target_len = len_str.size() + sep.size() + digit_len + sep.size(); // eg:  3 \r\n *** \r\n

        if (origin_str.size() < target_len)
            return 0;

        *package = origin_str.substr(pos + sep.size(), digit_len); // 把有效载荷长度带出去
        origin_str.erase(0, target_len);                           // 删除前面的数据

        return package->size();
    }

private:
    static bool DigitSafeCheck(const std::string str)
    {
        for (const auto &ch : str)
        {
            if (!(ch >= '0' && ch <= '9'))
                return false;
        }
        return true;
    }
};