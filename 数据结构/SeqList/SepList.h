#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//类型重命名
typedef int SLDataType;

//结构体的定义
typedef struct SeqList
{
	SLDataType* a;
	int size;//记录多少个有效数据
	int capacity;//空间容量
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

