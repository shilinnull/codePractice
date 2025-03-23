#include <iostream>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <string>
#include <sys/wait.h>
#include <sys/types.h>

const int size = 1024;

std::string getOtherMessage()
{
    // 计数
    static int cnt = 0;
    std::string massageid = std::to_string(cnt);
    cnt++;

    // 获取pid
    pid_t self_id = getpid();
    std::string id = std::to_string(self_id);

    std::string massage = "massage:";
    massage += massageid;
    massage += " my pid is: ";
    massage += id;
    return massage;
}

void SubProcessWrite(int wfd)
{
    int pipesize = 0;
    std::string massage = "father, I am your son prcess!";
    char c = 'A';
    while (true)
    {
        std::cerr << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        std::string info = massage + getOtherMessage(); // 子进程写给父进程的消息
        write(wfd, info.c_str(), info.size());
        std::cerr << info << std::endl;

        // write(wfd,&c,1);
        // std::cout << "pipesize: " << ++pipesize << std::endl;
        // c++;
        // if(c == 'G') break;
        sleep(1);
    }
    std::cout << "child quit..." << std::endl;
}

void FatherProcessRead(int rfd)
{
    char inbuffer[size];
    while (true)
    {
        sleep(2);
        std::cout << "-------------------------------------------" << std::endl;
        ssize_t n = read(rfd, inbuffer, sizeof(inbuffer) - 1); // 注意是sizeof
        if (n > 0)
        {
            inbuffer[n] = 0;
            std::cout << "father get massage: " << inbuffer << std::endl;
        }
        else if (n == 0)
        {
            // read返回值为0表示写端关闭了，读到了文件的结尾
            std::cout << "client quit, father get return val: " << n << "father quit tool!" << std::endl;
            break;
        }
        else if (n < 0)
        {
            std::cerr << " read error" << std::endl;
            break;
        }
    }
}

int main()
{
    // 1.创建管道
    int pipefd[2]; // pipefd里的0号下标保存的是读，1号下标保存的是写
    int n = pipe(pipefd);
    if (n != 0)
    {
        std::cerr << "errno:" << errno << ":"
                  << "errstring:" << strerror(errno) << std::endl;
        return 1;
    }

    std::cout << "pipefd[0]: " << pipefd[0] << " pipefd[1]: " << pipefd[1] << std::endl;

    // 2.fork创建出父子进程
    pid_t id = fork();
    if (id == 0)
    {
        std::cout << "子进程关闭不需要的fd了，准备发消息了" << std::endl;
        sleep(1);

        // 子进程 --- write
        // 3.关闭不需要的文件秒速符
        close(pipefd[0]);
        SubProcessWrite(pipefd[1]); // 子进程写
        // 不用了就关闭
        close(pipefd[1]);
        exit(0);
    }
    std::cout << "父进程关闭不需要的fd了，准备收消息了" << std::endl;

    // 父进程 --- read
    sleep(1);
    // 3.关闭不需要的文件描述符
    close(pipefd[1]);
    FatherProcessRead(pipefd[0]); // 父进程读
    // 不用了就关闭
    close(pipefd[0]);


    int status = 0;
    pid_t rid = waitpid(id, nullptr, 0);
    if (rid > 0)
    {
        std::cout << "wait child process done, exit sig: " << (status & 0x7f) << std::endl;
        std::cout << "wait child process done, exit code(ign): " << ((status >> 8) & 0xFF) << std::endl;
    }
    return 0;
}