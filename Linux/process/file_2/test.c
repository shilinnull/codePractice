#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    const char* s1 = "hello printf\n";
    printf(s1);
    const char* s2 = "hello fprintf\n";
    fprintf(stdout, s2);
    const char* s3 = "hello fwrite\n";
    fwrite(s3, strlen(s3), 1, stdout);

    const char* s4 = "hello write[syscall]\n";
    write(1, s4, strlen(s4));

    fork();

    return 0;
}

