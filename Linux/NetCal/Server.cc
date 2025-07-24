#include <memory>

#include "TcpServer.hpp" // Tcp
#include "Parser.hpp"    // 序列化与分序列化
#include "Calculator.hpp"// 计算
#include "daemon.hpp"    // 守护进程

void Usage(std::string proc)
{
    std::cerr << "Usage : " << proc << " <prot>" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(0);
    }
    EnableFileLog(); // 开启文件日志
    myDaemon(); // 守护进程化
    
    // 计算器模块
    std::unique_ptr<Calculator> cal = std::make_unique<Calculator>();

    // 协议解析模块
    std::unique_ptr<Parser> parser = std::make_unique<Parser>([&cal](Request &req) -> Response
                                                              { return cal->Exec(req); });

    uint16_t port = std::stoi(argv[1]);
    // 网络通信模块
    std::unique_ptr<TcpServer> tsock = std::make_unique<TcpServer>(port, [&parser](std::string &inbuffer) -> std::string
                                                                   { return parser->Parse(inbuffer); });

    tsock->Run();

    return 0;
}