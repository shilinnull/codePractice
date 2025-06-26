#include "MsgQueue.hpp"

int main()
{

    std::string text;
    Server server;

    while (true)
    {
        // 如果消息队列为空，阻塞等待
        server.Recv(MSG_TYPE_CLIENT, text);
        std::cout << "Received: " << text << std::endl;
        if (text == "exit")
        {
            break;
        }
    }
    return 0;
}