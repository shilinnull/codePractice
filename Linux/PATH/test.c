#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *str = getenv("USER");
    if(strcmp(str,"lin"))
    {
        printf("不是你的程序，不能执行！user: %s\n",str);
        return 1;
    }
    printf("是你的程序，可以执行！user: %s\n",str);

    return 0;
}
