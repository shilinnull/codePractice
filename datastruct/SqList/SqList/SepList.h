#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int SLDataType;

typedef struct Seqlist {
	SLDataType* arr;
	int size;
	int capacity;
}SL;

// 初始化和销毁
void SLInit(SL* ps);
void SLDestory(SL* ps);

// 打印
void SLPrint(SL* ps);


// 检查容量
void SLCheckCapacity(SL* ps);
// 尾插
void SLPushBack(SL* ps,SLDataType x);
// 尾删
void SLPopBack(SL* ps);
// 头插
void SLPushFront(SL* ps,SLDataType x);
// 头删
void SLPopFront(SL* ps);
// 指定位置插入数据
void SLInsert(SL* ps, int pos, SLDataType x);

// 指定位置删除数据
void SLErase(SL* ps, int pos);

// 查找
bool SLFind(SL* ps, SLDataType x);

