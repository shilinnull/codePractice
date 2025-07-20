#include <iostream>
#include <string>
#include <thread>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>

void Usage(std::string proc)
{
    std::cerr << "Usage: " << proc << " serverip serverport" << std::endl;
}

int sockfd = -1;
std::string server_ip;
uint16_t server_port;

void InitClient(const std::string &server_ip, uint16_t server_port)
{
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        std::cerr << "Create socket error" << std::endl;
        exit(1);
    }
}

void recver()
{
    for (;;)
    {
        char buffer[1024];
        struct sockaddr_in temp_addr;
        socklen_t len = sizeof(temp_addr);
        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&temp_addr, &len);
        if (n > 0)
        {
            buffer[n] = 0;
            std::cerr << buffer << std::endl; // 输出接收到的消息
        }
    }
}

void sender()
{
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr)); // 清空结构体
    server_addr.sin_family = AF_INET;                           // 使用IPv4地址族
    server_addr.sin_addr.s_addr = inet_addr(server_ip.c_str()); // 将IP地址从字符串转换为网络字节序的整数
    server_addr.sin_port = htons(server_port);                  // 主机字节序转网络字节序

    for (;;)
    {
        std::cout << "Please input your message: ";
        std::string message;
        std::getline(std::cin, message);
        sendto(sockfd, message.c_str(), message.size(), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(0);
    }

    server_ip = argv[1];
    server_port = atoi(argv[2]);
    InitClient(server_ip, server_port); // 初始化客户端

    std::thread trecv(recver);
    std::thread tsend(sender);

    trecv.join();
    tsend.join();

    return 0;
}