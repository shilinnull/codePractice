#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

typedef struct Seqlist {
	SLDataType* arr;
	int size;
	int capacity;
}SL;

// 初始化和销毁

void SLInit(SL* ps);
void SLDestory(SL* ps);
