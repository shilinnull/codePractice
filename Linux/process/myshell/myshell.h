#pragma once


#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 1024

void InitGlobal();
void PrintCommand();
bool GetCommandStr(char *cmd, int len);
void ParseCommandStr(char *cmd);
bool BuiltInCommandExec();
void ForkAndExec();
