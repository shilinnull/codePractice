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

// ��ʼ��������

void SLInit(SL* ps);
void SLDestory(SL* ps);
