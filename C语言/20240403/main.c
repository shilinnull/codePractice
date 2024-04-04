#include <stdio.h>
#include <stdarg.h>


//int FindMax(int num,...)
//{
//    va_list arg; // char*
//    va_start(arg,num);
//    int max = va_arg(arg,int);
//    for(int i = 1;i<=num;i++)
//    {
//        int cur = va_arg(arg,int);
//        if(cur > max)
//            max = cur;
//    }
//
//    va_end(arg); // arg = NULL // 0
//    return max;
//}
//
//
//int main() {
//    int max = 0;
//    max = FindMax(1,131,424,25,3,54,6,574,6,1);
//    printf("%d\n",max);
//    return 0;
//}

int main(int argc, char* argv[], char* envp[])
{
    for(int i = 0;i<argc;i++)
    {
        printf("argv[%d]:%s\n",i,argv[i]);
    }

    for(int i = 0;envp[i] != NULL; i++)
    {
        // printf("%s\n",argv[i]);
        printf("env[%d]:%s\n",i,envp[i]);
    }
    return 0;
}


