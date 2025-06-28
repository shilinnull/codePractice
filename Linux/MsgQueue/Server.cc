#include "MsgQueue.hpp"
#include "ChainOfResponsibility.hpp"

int main()
{
    std::string text;
    Server server;
    
    // 责任链模式
    HandlerEntry he;
    // 全部都开启(格式化、保存文件、备份文件)
    he.EnableHandler(true, true, true);

    while (true)
    {
        // 如果消息队列为空，阻塞等待
        server.Recv(MSG_TYPE_CLIENT, text);
        std::cout << "Received: " << text << std::endl;
        if (text == "exit")
        {
            break;
        }
        
        // 加工处理数据，采用责任链模式
        he.Run(text);
    }
    return 0;
}