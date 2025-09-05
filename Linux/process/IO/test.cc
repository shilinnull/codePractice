#include <iostream>
#include <cstring>

#include <unistd.h>
#include <sys/fcntl.h>


void SetNonBlock(int sockfd)
{
    int fl = fcntl(sockfd, F_GETFL); // 获取
    if(fl < 0)
    {
        std::cerr << "fcntl : " << strerror(errno) << std::endl;
        return;
    }
    //标记位加上非阻塞，然后设置到文件描述符，这个文件描述符就变成了非阻塞
    fcntl(sockfd, F_SETFL, fl | O_NONBLOCK);
}

int main()
{
    SetNonBlock(0); // 设置为非阻塞
    char buffer[1024];
    while(true)
    {
        ssize_t n = read(0, buffer, sizeof(buffer) - 1);
        if(n > 0)
        {
            buffer[n] = 0;
            printf("#%s", buffer);
        }
        else if(n == 0)
        {
            printf("read end of file!\n");
            break;
        }
        else
        {
            printf("read error, read ret : %ld, errno : %d, err message: %s\n", n, errno, strerror(errno));
            // errno = 11 -> EAGAIN or EWOULDBLOCK
            if(errno == EAGAIN || errno == EWOULDBLOCK)
            {
                                 printf("你的数据没有准备好，下次再来吧!\n");
                sleep(1); // 在做其他的事情
                continue;
            }
            if(errno == EINTR)
            {
                sleep(1);
                continue;
            }
            else 
            {
                perror("read error!");
            }
        }
        sleep(1);
    }
    return 0;    
}