#include <iostream>
#include <memory>

#include "Http.hpp"
#include "TcpServer.hpp"

using namespace std;
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
    std::unique_ptr<Http> http = std::make_unique<Http>();

    uint16_t serverport = std::stoi(argv[1]);
    std::unique_ptr<TcpServer> tsock = std::make_unique<TcpServer>(serverport, [&http](std::string& reqstr)->std::string{
        return http->HandlerRequest(reqstr);
    });

    tsock->Run();
    
    return 0;
}