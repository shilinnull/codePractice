#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
int main()
{
    pid_t id = fork();
    assert(id != -1);
    if(id == 0)
    {
        // child 
        int cnt = 10;
        while(cnt)
        {
            printf("child process running，pid:%d，ppid:%d，cnt:%d\n",getpid(),getppid(),cnt--);
            sleep(1);
        }
        exit(10);
    }

    // 等待子进程
    int status=0;
    int ret = waitpid(id,&status,0);
    if(ret > 0)
    {
        if(WIFEXITED(status)) // 如果正常退出返回结果为真，然后查看退出码
            printf("child process exit normally，exit code:%d\n", WEXITSTATUS(status));
        else
            printf("child process don't exit normally\n");
    }
    return 0;
}
