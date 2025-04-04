#pragma once
#include <string.h>
#include <unistd.h>
#include <stdio.h>

// 进度条箭头
#define TAIL '>'

// 进度条的数组大小
#define Length 102

// 进度条加载的进度条
#define Style '='

// 重定义函数指针
typedef void (*callback_t)(double, double);

// 进度条的实现
void ProcBar(double total, double current);
