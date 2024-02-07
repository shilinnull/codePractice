#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int LTDataType;

typedef struct ListNode {
	LTDataType val;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//初始化哨兵位
LTNode* LTInit();
//创建节点
LTNode* LTcreate(LTDataType x);
//销毁
void LTDestroy(LTNode* phead);
//打印
void LTPrint(LTNode* phead);
//判断是否为空
bool LTEmpty(LTNode* phead);
//尾插
void LTPushBack(LTNode* phead, LTDataType x);
//尾删
void LTPopBack(LTNode* phead);
//头插
void LTPushFront(LTNode* phead, LTDataType x);
//头删
void LTPopFront(LTNode* phead);
//指定位置插入
void LTInsert(LTNode* pos, LTDataType x);
//指定位置删除
LTNode* LTErase(LTNode* pos);
//查找
LTNode* LTFind(LTNode* phead, LTDataType x);
