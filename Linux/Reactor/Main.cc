#include <iostream>
#include <memory>

#include "Calculator.hpp"
#include "Protocol.hpp"
#include "Parser.hpp"
#include "Logger.hpp"
#include "Reactor.hpp"
#include "Listener.hpp"

void Usage(std::string proc)
{
    std::cerr << "Usage: " << proc << " localport" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(0);
    }

    uint16_t serverport = std::stoi(argv[1]);

    //  1. 业务对象
    std::unique_ptr<Calculator> cal = std::make_unique<Calculator>();

    // 2. 协议和解析协议对象
    std::unique_ptr<Parser> parse_protocol = std::make_unique<Parser>(
        [&cal](Request &req)->Response{
            return cal->Exec(req);
        }
    );

    // 3. 连接管理器 - Listener
    std::shared_ptr<Connection> listener = std::make_shared<Listener>(serverport);  /* 在使用的时候记住需要把fd设置成非阻塞*/
    listener->SetCallBack([&parse_protocol](std::string &inbuffer)->std::string{
        return parse_protocol->Parse(inbuffer);
    });

    // 4. 构建一个Reactor容器
    std::unique_ptr<Reactor> R = std::make_unique<Reactor>();

    // 给reactor中，把连接管理器添加到Reactor
    R->AddConnection(listener);

    // 启动Reactor
    R->Dispatcher();
    
    return 0;
}