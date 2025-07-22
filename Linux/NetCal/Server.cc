#include <memory>

#include "TcpServer.hpp"


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

    std::unique_ptr<TcpServer> tsock = std::make_unique<TcpServer>(port);
    tsock->Run();

    return 0;
}