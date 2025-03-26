//
// Created by ATT on 2024/3/28.
//

#include <stdio.h>

#define TOSTR(s) #s

int main()
{
    printf(TOSTR(12345));
    return 0;
}