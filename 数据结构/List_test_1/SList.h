#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int SLNDataType;

typedef struct SListNode
{
	SLNDataType val;
	struct SListNode* next;
}SLNode;

//打印
void SLTPrint(SLNode* phead);

//尾插
void SLTPushBack(SLNode** pphead, SLNDataType x);

//头插
void SLTPushFront(SLNode** pphead, SLNDataType x);

//尾删
void SLTPopBack(SLNode** pphead);

//头删
void SLTPopFront(SLNode** pphead);

//查找
SLNode* SListFind(SLNode** phead, SLNDataType x);

//在指定位置之前插入数据
void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x);

//删除pos节点
void SLTErase(SLNode** pphead, SLNode* pos);

//在指定位置之后插入数据
void SLTInsertAfter(SLNode* pos, SLNDataType x);

//删除pos之后的节点
void SLTEraseAfter(SLNode* pos);

//销毁链表
void SListDesTroy(SLNode** pphead);