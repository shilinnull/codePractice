#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
    chdir("/home/lin/code-exercise/Linux/process/status/dir");
    FILE* fp = fopen("hello.txt","w");
    if(!fp)
    {
        perror("fopen fail!\n");
        exit(-1);
    }
    printf("pid:%d\n",getpid()); 

    while(1);
    fclose(fp);
    return 0;
}

