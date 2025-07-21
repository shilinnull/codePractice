#include "Command.hpp"
#include "CommandServer.hpp"
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
    
    // 要执行的命令对象
    Command cmdobj;
    
    std::unique_ptr<CommandServer> server = std::make_unique<CommandServer>([&cmdobj](const std::string &cmd)->std::string{
        return cmdobj.Exec(cmd);
    }, port);
    
    server->Init();
    server->Start();

    return 0;
}
