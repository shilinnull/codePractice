#include <iostream>
#include <string>
#include <memory>

#include "Socket.hpp"
#include "InetAddr.hpp"
#include "Protocol.hpp"

void Usage(std::string proc)
{
    std::cerr << "Usage: " << proc << " <serverip> <serverport>" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(0);
    }

    std::string serverip = argv[1];
    uint16_t serverport = std::stoi(argv[2]);

    std::unique_ptr<Socket> sockptr = std::make_unique<TcpSocket>();
    sockptr->BuildClientSocketMethod();

    InetAddr server(serverport, serverip);
    if (sockptr->Connect(server)) // 连接
    {
        std::string inbuffer;
        for (;;)
        {
            // 1. 构建请求
            Request req;
            int x, y;
            char oper;

            std::cout << "Please Enter X:";
            std::cin >> x;
            req.SetX(x);

            std::cout << "Please Enter Y:";
            std::cin >> y;
            req.SetY(y);

            std::cout << "Please Enter Oper:";
            std::cin >> oper;
            req.SetOper(oper);

            // 2. 序列化
            std::string jsonstr;
            req.Serialize(&jsonstr);
            // std::cout << "jsonstr: \r\n" << jsonstr << std::endl;

            // 3 打包
            std::string sendstr = ProtoCol::Package(jsonstr);
            // std::cout << "sendstr: \r\n" << sendstr << std::endl;

            // 4. 发送
            sockptr->Send(sendstr);

            // 5. 接收
            sockptr->Recv(&inbuffer);

            // 6. 反序列化
            std::string package;
            int n = ProtoCol::Unpack(inbuffer, &package);
            if (n > 0)
            {
                Response resp;
                bool r = resp.Deserialize(package);
                if (r)
                {
                    resp.Print();
                }
            }
        }
    }
    return 0;
}