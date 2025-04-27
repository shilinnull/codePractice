#include "myFile.h"

int main()
{
    myFILE *fp = my_fopen("log.txt", "w");
    if(!fp) return 1;
    
    char buffer[128];
    const char* s = "hello Linux";
    int cnt = 10;
    while(cnt--)
    {
        snprintf(buffer, sizeof(buffer),"%s:%d\n", s, cnt);
// #define DEBUG
#ifdef DEBUG
        printf("%s", buffer);
        sleep(1);
#endif
        my_write(buffer, strlen(buffer), fp);
    }
    my_close(fp);
    return 0;
}
