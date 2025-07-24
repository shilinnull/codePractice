#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>

void Usage(std::string proc)
{
    std::cerr << "Usage: " << proc << " serverip serverport" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(0);
    }

    std::string server_ip = argv[1];
    uint16_t server_port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        std::cerr << "Create socket error" << std::endl;
        exit(1);
    }

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;                           // 使用IPv4地址族
    server_addr.sin_addr.s_addr = inet_addr(server_ip.c_str()); // 将IP地址从字符串转换为网络字节序的整数
    server_addr.sin_port = htons(server_port);                  // 主机字节序转网络字节序

    for (;;)
    {
        std::cout << "Please Enter@ ";
        std::string line;
        std::getline(std::cin, line);

        // 发送数据到服务器
        sendto(sockfd, line.c_str(), line.size(), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        // 接收服务器的响应
        char buffer[1024];
        struct sockaddr_in temp_addr;
        socklen_t len = sizeof(temp_addr);
        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&temp_addr, &len);
        if (n > 0)
        {
            buffer[n] = 0;
            std::cout << buffer << std::endl;
        }
    }

    return 0;
}