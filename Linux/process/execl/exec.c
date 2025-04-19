#include <stdio.h>
#include <unistd.h>

int main()
{
    // .c --> .exe --> load into memory --> process --> running
    printf("The process is running...\n");
    // 传参以NULL结尾，来表示传参结束                                                        
    // execl("/usr/bin/ls","ls","-a","-l","--color=auto",NULL);
    // execlp("ls", "ls","-a","-l",NULL);
    // execle("ls","ls","-a","-1",envp);
    

    printf("The process finishes running...\n");
    return 0;
}
