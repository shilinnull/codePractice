#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//动态顺序表
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;  //顺序表中有效的数据个数
	int capacity;  //顺序表当前的空间大小
}SL;
//typedef struct SeqList SL;

//对顺序表进行初始化
void SLInit(SL* ps);
void SLDestroy(SL* ps);

//头部/尾部 插入/删除
void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

void SLPrint(SL* ps);
bool SLIsEmpty(SL* ps);