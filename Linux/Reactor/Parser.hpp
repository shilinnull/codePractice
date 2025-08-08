#pragma once

#include <functional>

#include "Parser.hpp"
#include "Calculator.hpp"
#include "Protocol.hpp"
#include "Logger.hpp"

using handler_t = std::function<Response(Request &req)>;

class Parser
{
public:
    Parser(handler_t handler) : _handler(handler)
    {
    }

    std::string Parse(std::string &inbuffer)
    {
        LOG(LogLevel::DEBUG) << "inbuffer: \r\n"
                             << inbuffer;

        std::string send_str;
        for (;;) // 获取到的数据不一定是全部的，需要循环获取, 当获取完一个整个报文后回掉回去进行发送
        {
            std::string jsonstr;
            // 解析报文
            int n = ProtoCol::Unpack(inbuffer, &jsonstr);
            if (n < 0)
                break; // 解包错误
            else if (n == 0)
                break; // 已经处理完毕了
            else 
            {
                LOG(LogLevel::DEBUG) << "jsonstr: \r\n"
                                     << jsonstr;

                // 反序列化
                Request req;
                if (!req.Deserialize(jsonstr))
                {
                    return std::string();
                }

                Response resp = _handler(req); // 回掉函数到上层处理业务

                // 序列化
                std::string resp_json;
                if (!resp.Serialize(&resp_json))
                {
                    return std::string();
                }

                // 打包
                send_str += ProtoCol::Package(resp_json);
            }
        }
        return send_str; // 回掉回去然后进行发送数据
    }

private:
    handler_t _handler;
};
