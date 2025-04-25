#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
    // 1. 打开目标文件
    int fd = open("log.txt", O_CREAT | O_WRONLY, 0666);
    
    // 2. 输出重定向
    dup2(fd, 1);

    // 3. exec*替换，不影响重定向
    execl("/usr/bin/ls", "ls","-al", NULL);

    return 0;
}



// int main()
// {
//     pid_t id = fork();
//     if(id == 0)
//     {
//         while(1)
//         {
//             // child
//             printf("我是子进程\n");
//             sleep(1);
//         }
//     }
//     else 
//     {
//         sleep(2);
//         // parent
//         printf("parent马上要关闭了标准输出\n");
//         close(1);
//         printf("父进程就看不到这句话了，但是子进程还是不影响\n");
//         pid_t rid = waitpid(id, NULL, 0);
//         if(rid > 0)
//         {
//             printf("等待成功\n");
//         }
//     }
//     return 0;
// }
