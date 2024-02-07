#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;


//初始化顺序表
void SLInit(SL* ps);

//销毁顺序表
void SLDestroy(SL* ps);

//尾插
void SLPushBack(SL* ps, SLDataType x);

//头插
void SLPushFront(SL* ps, SLDataType x);

//尾删
void SLPopBack(SL* ps);

//头删
void SLPopFront(SL* ps);

//打印顺序表
void SLPrint(SL* ps);

//判断是否为空
bool SLIsEmpty(SL* ps);

//在任意位置之前插入
void SLInsert(SL* ps, int pos, SLDataType x);

//在任意位置之前删除
void SLErase(SL* ps, int pos);

//查找顺序表
bool SLFind(SL* ps, SLDataType x);



