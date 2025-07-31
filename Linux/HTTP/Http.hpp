#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <functional>

#include "Logger.hpp"

// #define Debug
static const std::string linesep = "\r\n";
static const std::string innersep1 = " ";
static const std::string innersep2 = ": ";
static const std::string webroot = "./wwwroot";
static const std::string defaulthome = "index.html";
// static const std::string webroot = "./wwwroot_blog";
// static const std::string defaulthome = "blog_login.html";
static const std::string defaultHtml404 = "404.html";
static const std::string suffixsep = ".";
static const std::string argssep = "?";

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
        reqstr.erase(0, pos + linesep.size()); // 删除读取到的元素
        return line;
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

        std::stringstream ss(reqline);
        ss >> _method >> _uri >> _httpversion;

#ifndef Debug
        LOG(LogLevel::DEBUG) << _method << " " << _uri << " " << _httpversion;
#endif

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
                LOG(LogLevel::DEBUG) << "解析到了空行";
                _back_line = linesep; // 解析到空行就退出
                break;
            }
            else
            {
                LOG(LogLevel::DEBUG) << "非法请求";
                // return false;
                break;
            }
        }

        _req_body = reqstr; // 剩下的就是内容
        _path = webroot;    // 默认目录

        if (_uri == "/")                // 如直接请求的默认就是/ 此时直接跳转到默认目录
            _path += "/" + defaulthome; // 默认文件
        else
            _path += _uri;

#ifndef Debug

        LOG(LogLevel::DEBUG) << "反序列化: ";
        for (auto &[x, y] : _req_handers)
            LOG(LogLevel::DEBUG) << "kv: " << x << ": " << y;

        LOG(LogLevel::DEBUG) << "查看解析前的路径: " << _path;
        LOG(LogLevel::DEBUG) << "查看请求体: " << _req_body;
#endif
        // 解析参数
        if (_method == "GET")
        {
            auto pos = _path.find(argssep);
            if (pos != std::string::npos)
            {
                _req_body = _path.substr(pos + argssep.size());
                _path = _path.substr(0, pos);
            }
#ifndef Debug
            LOG(LogLevel::DEBUG) << "查看解析后的路径: " << _path;
            LOG(LogLevel::DEBUG) << "查看解析后的参数: " << _req_body;
#endif
        }
        else if (_method == "POST")
        {
            _req_body = reqstr;
#ifndef Debug
            LOG(LogLevel::DEBUG) << "查看解析后的参数: " << _req_body;
#endif
        }
        else
        {
            // 还没有写
        }

        return true;
    }
    std::string Path()
    {
        return _path;
    }

    void SetPath(const std::string &path)
    {
        _path = path;
    }

    std::string Body()
    {
        return _req_body;
    }

    std::string Suffix()
    {
        if (_path.empty())
            return std::string();
        else
        {
            auto pos = _path.rfind(suffixsep);
            if (pos == std::string::npos)
                return std::string();
            else
                return _path.substr(pos); // 截取后缀
        }
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
private:
    std::string Code2Desc(int code)
    {
        switch (code)
        {
        // 2xx Success
        case 200:
            return "OK";
        case 201:
            return "Created";
        case 202:
            return "Accepted";
        case 204:
            return "No Content";

        // 3xx Redirection
        case 301:
            return "Moved Permanently";
        case 302:
            return "Found";
        case 303:
            return "See Other";
        case 304:
            return "Not Modified";
        case 307:
            return "Temporary Redirect";
        case 308:
            return "Permanent Redirect";

        // 4xx Client Errors
        case 400:
            return "Bad Request";
        case 401:
            return "Unauthorized";
        case 403:
            return "Forbidden";
        case 404:
            return "Not Found";
        case 405:
            return "Method Not Allowed";
        case 408:
            return "Request Timeout";
        case 409:
            return "Conflict";
        case 413:
            return "Payload Too Large";
        case 415:
            return "Unsupported Media Type";
        case 429:
            return "Too Many Requests";

        // 5xx Server Errors
        case 500:
            return "Internal Server Error";
        case 501:
            return "Not Implemented";
        case 502:
            return "Bad Gateway";
        case 503:
            return "Service Unavailable";
        case 504:
            return "Gateway Timeout";

        default:
            return "";
        }
    }

public:
    HttpResponse() : _httpversion("HTTP/1.1"), _black_line(linesep) {}

    std::string Serialize()
    {
        // 添加状态行
        std::string respstr = _httpversion + innersep1 + std::to_string(_code) +
                              innersep1 + _desc + linesep;
        // 添加Content-Length
        if (!_resp_body.empty())
        {
            std::string len = std::to_string(_resp_body.size());
            LOG(LogLevel::DEBUG) << "_resp_body 的大小: " << _resp_body.size();

            SetHeader("Content-Length", len);
        }

        // 添加相应报头
        for (auto &[x, y] : _req_handers)
        {
            respstr += x + innersep2 + y + linesep;
        }

        // 添加cookies
        for (auto &cookie : _cookies)
        {
            respstr += cookie;
            respstr += linesep;
        }

#ifndef Debug
        LOG(LogLevel::DEBUG) << "序列化: ";
        for (auto &[x, y] : _req_handers)
            LOG(LogLevel::DEBUG) << "kv: " << x << ": " << y;
#endif

        respstr += _black_line; // 添加空行
        respstr += _resp_body;  // 添加正文
        // LOG(LogLevel::DEBUG) << "_resp_body 的内容: \n" << _resp_body;
        return respstr;
    }

    bool ReadContent(const std::string &path)
    {
        // 以二级制方式读取
        // 打开文件，二进制模式
        std::ifstream file(path, std::ios::binary);
        if (!file.is_open())
        {
            LOG(LogLevel::WARNING) << path << " 资源不存在!";
            file.close();
            return false;
        }

        // 定位到文件末尾获取文件大小
        file.seekg(0, std::ios::end);
        std::streampos fileSize = file.tellg(); // 获取文件大小
        file.seekg(0, std::ios::beg);

        // 创建足够大的字符串来保存数据
        _resp_body.resize(static_cast<size_t>(fileSize));

        // 读取文件内容到字符串
        file.read(&_resp_body[0], fileSize);
        file.close();

        return true;
    }

    void SetCode(int code)
    {
        if (code >= 100 && code < 600)
        {
            _code = code;
            _desc = Code2Desc(code);
        }
        else
        {
            LOG(LogLevel::DEBUG) << "非法的状态码: " << code;
        }
    }

    void SetHeader(const std::string &key, const std::string &value)
    {
        _req_handers[key] = value;
    }

    void SetCookie(const std::string& key, const std::string &value)
    {
        std::string cookie = key;
        cookie += ": ";
        cookie += value;
        _cookies.push_back(cookie);
    }

private:
    std::string _httpversion;
    int _code;
    std::string _desc;
    std::unordered_map<std::string, std::string> _req_handers;
    std::string _black_line;
    std::string _resp_body;

    std::vector<std::string> _cookies;
};

using func_t = std::function<HttpResponse(HttpRequest &)>;

class Http
{
private:
    std::unordered_map<std::string, func_t> _handlers;

private:
    std::string Suffix2Desc(const std::string &suffix)
    {
        if (suffix == ".html" || suffix == ".htm")
        {
            return "text/html";
        }
        else if (suffix == ".css")
        {
            return "text/css";
        }
        else if (suffix == ".js")
        {
            return "application/javascript"; // Updated from x-javascript to standard type
        }
        else if (suffix == ".png")
        {
            return "image/png";
        }
        else if (suffix == ".jpg" || suffix == ".jpeg")
        {
            return "image/jpeg";
        }
        else if (suffix == ".gif")
        {
            return "image/gif";
        }
        else if (suffix == ".txt")
        {
            return "text/plain";
        }
        else if (suffix == ".json")
        {
            return "application/json";
        }
        else if (suffix == ".pdf")
        {
            return "application/pdf";
        }
        else if (suffix == ".xml")
        {
            return "application/xml";
        }
        else if (suffix == ".svg")
        {
            return "image/svg+xml";
        }
        else if (suffix == ".ico")
        {
            return "image/x-icon";
        }
        else if (suffix == ".mp4")
        {
            return "video/mp4";
        }
        else if (suffix == ".webm")
        {
            return "video/webm";
        }
        else if (suffix == ".mp3")
        {
            return "audio/mpeg";
        }
        else if (suffix == ".woff")
        {
            return "font/woff";
        }
        else if (suffix == ".woff2")
        {
            return "font/woff2";
        }
        else
        {
            return "text/html"; // Default fallback
        }
    }

public:
    Http()
    {
    }
    void Register(const std::string &action, func_t handler)
    {
        std::string key = webroot + action;
        _handlers[key] = handler;
    }
    std::string HandlerRequest(std::string &requeststr)
    {
        std::string respstr;
        HttpRequest req;                 // 请求
        if (req.Deserialize(requeststr)) // 反序列化
        {
            HttpResponse resp; // 构建回复
            // 交互式处理
            std::string target = req.Path();
            if (_handlers.find(target) != _handlers.end())
            {
                resp = _handlers[target](req); // 让上层进行处理
            }
            else // 处理静态网页资源
            {
                if (resp.ReadContent(req.Path())) // 读取内容
                {
                    std::string suffix = req.Suffix();                 // 获取后缀
                    std::string mime_type_value = Suffix2Desc(suffix); // 识别类型
                    resp.SetHeader("Content-type", mime_type_value);   // 添加类型
                    resp.SetCode(200);
                }
                else // 没有此路径的文件
                {
                    resp.SetCode(301);
                    resp.SetHeader("Location", "/404.html");

                    // std::string error_404 = webroot + "/" + defaultHtml404;
                    // req.SetPath(error_404);       // 设置状态码
                    // resp.ReadContent(req.Path()); // 读取内容

                    // std::string suffix = req.Suffix();                 // 获取后缀
                    // std::string mime_type_value = Suffix2Desc(suffix); // 识别类型
                    // resp.SetHeader("Content-type", mime_type_value);   // 添加类型
                    // resp.SetCode(404);
                }
            }
            respstr = resp.Serialize(); // 序列化
        }
        return respstr;
    }

    ~Http()
    {
    }
};