#include <iostream>
#include <memory>
#include "EpollServer.hpp"


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

    std::unique_ptr<EpollServer> epollsvr =  std::make_unique<EpollServer>(serverport);
    epollsvr->Run();

    return 0;
}