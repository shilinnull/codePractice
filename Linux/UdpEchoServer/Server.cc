#include "UdpServer.hpp"

#include <memory>

void Usage(std::string proc)
{
    std::cerr << "Usage: " << proc << " <Port>" << std::endl;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        Usage(argv[0]);
        exit(1);
    }

    uint16_t port = atoi(argv[1]);
    std::unique_ptr<UdpServer> server = std::make_unique<UdpServer>(port);
    server->Init();
    server->Start();

    return 0;
}