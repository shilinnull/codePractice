#pragma once

#include <string>
#include <unordered_map>
#include <sstream>
#include "Logger.hpp"

static const std::string linesep = "\r\n";
static const std::string innersep1 = " ";
static const std::string innersep2 = ": ";
static const std::string webroot = "./wwwroot/";
static const std::string defaulthome = "index.html";

class HttpRequest
{
private:
    std::string ReadOneLine(std::string &reqstr, bool *status)
    {
        auto pos = reqstr.find(linesep);
        if (pos == std::string::npos)
        {
            *status = false; // 找不到
            return std::string();
        }
        std::string line = reqstr.substr(0, pos);
        reqstr.erase(0, pos + linesep.size());
        return line;
    }

    void ParseReqLine(std::string &reqline)
    {
        std::stringstream ss(reqline);
        ss >> _method >> _uri >> _httpversion;
    }

    void BuildKV(std::string &line, std::string *k, std::string *v)
    {
        auto pos = line.find(innersep2);
        if (pos == std::string::npos)
        {
            *k = *v = std::string();
        }
        *k = line.substr(0, pos);
        *v = line.substr(pos + innersep2.size());
    }

public:
    HttpRequest() {}

    bool Deserialize(std::string &reqstr)
    {
        bool status = true;
        std::string reqline = ReadOneLine(reqstr, &status); // 读取首行
        if (!status)
            return false;

        ParseReqLine(reqline); //  解析数据

        LOG(LogLevel::DEBUG) << _method << " " << _uri << " " << _httpversion;

        for (;;) // 解析kv
        {
            status = true;
            reqline = ReadOneLine(reqstr, &status);
            if (status && !reqline.empty())
            {
                std::string k, v;
                BuildKV(reqline, &k, &v);
                if (k.empty() || v.empty())
                    continue;
                _req_handers.insert(std::make_pair(k, v));
            }
            else if (status)
            {
                _back_line = linesep; // 解析到空行就退出
                break;
            }
            else
            {
                return false;
            }
        }
        for (auto &[x, y] : _req_handers)
        {
            LOG(LogLevel::DEBUG) << "k: " << x << "v: " << y;
        }

        _req_body = reqstr;
        _path = webroot;
        if (_uri == "/")
        {
            _path += defaulthome; // 默认
        }

        LOG(LogLevel::DEBUG) << "_path " << _path;
        return true;
    }
    std::string Path()
    {
        return _path;
    }

    ~HttpRequest() {}

private:
    std::string _method;
    std::string _uri;
    std::string _httpversion;
    std::unordered_map<std::string, std::string> _req_handers;
    std::string _back_line;
    std::string _req_body;

    std::string _path;
};

class HttpResponse
{
public:
    HttpResponse() : _httpversion("HTTP/1.1"), _black_line("\r\n") {}

    std::string Serialize()
    {
        std::string respstr = _httpversion + innersep1 + std::to_string(_code) + innersep1 + _desc + linesep;

        for (auto &[x, y] : _req_handers)
        {
            respstr += x + innersep2 + y + linesep;
        }
        respstr += _black_line;
        respstr += _resp_body;
        return respstr;
    }

    void ReadContent(const std::string &path)
    {
        // 以二级制方式读取
        // 打开文件，二进制模式
        std::ifstream file(path, std::ios::binary);
        if (!file.is_open())
        {
            throw std::runtime_error("无法打开文件: " + path);
        }

        // 定位到文件末尾获取文件大小
        file.seekg(0, std::ios::end);
        std::streampos fileSize = file.tellg(); // 获取文件大小
        file.seekg(0, std::ios::beg);

        // 创建足够大的字符串来保存数据
        _resp_body.resize(static_cast<size_t>(fileSize));

        // 读取文件内容到字符串
        file.read(&_resp_body[0], fileSize);

        // 检查是否读取了所有数据
        if (!file)
        {
            throw std::runtime_error("读取文件时出错: " + path);
        }
        file.close();
    }

    void SetCode(int code, const std::string &desc)
    {
        _code = code;
        _desc = desc;
    }

private:
    std::string _httpversion;
    int _code;
    std::string _desc;
    std::unordered_map<std::string, std::string> _req_handers;
    std::string _black_line;
    std::string _resp_body;
};

class Http
{
public:
    Http()
    {
    }

    std::string HandlerRequest(std::string &requeststr)
    {
        std::string respstr;
        HttpRequest req;
        if (req.Deserialize(requeststr)) // 反序列化成功
        {
            HttpResponse resp;
            resp.ReadContent(req.Path()); // 读取内容
            resp.SetCode(200, "OK");      // 设置状态码
            respstr = resp.Serialize();   // 序列化
        }
        return respstr;
    }

    ~Http()
    {
    }
};