#include "TcpEchoServer.hpp"
#include <memory>


void Usage(std::string proc)
{
    std::cerr << "Usage : " << proc << " <prot>" << std::endl;
}


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        Usage(argv[0]);
        exit(0);
    }

    uint16_t port = std::stoi(argv[1]);
    std::unique_ptr<TcpEchoServer> server = std::make_unique<TcpEchoServer>(port);
    
    server->Init();
    server->Start();

    return 0;
}
