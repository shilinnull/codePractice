#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

//初始化哨兵位
LTNode* LTInit()
{
	LTNode* phead = LTcreate(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//创建节点
LTNode* LTcreate(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!\n");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->val = x;
	return newnode;
} 

//销毁
void LTDestroy(LTNode* phead);
//打印
void LTPrint(LTNode* phead)
{
	assert(phead);
	printf("哨兵位<->");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<->", cur->val);
		cur = cur->next;
	}
	printf("\n");
}
//判断是否为空
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	return phead->val == 0;
}

//尾插
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTcreate(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}


//尾删
void LTPopBack(LTNode* phead)
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* tailprev = tail->prev;
	free(tail);
	tail = NULL;
	tailprev->next = phead;
	phead->prev = tailprev;
}
//头插
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTcreate(x);
	LTNode* cur = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	cur->prev = newnode;
	newnode->next = cur;
}
//头删
void LTPopFront(LTNode* phead)
{
	assert(phead);
	LTNode* first = phead->next;
	LTNode* second = first->next;
	free(first);
	phead->next = second;
	second->prev = phead;
}

//查找
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//指定位置的前面插入
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTcreate(x);
	LTNode* posprev = pos->prev;
	posprev->next = newnode;
	newnode->prev = posprev;

	newnode->next = pos;
	pos->prev = newnode;

}
//指定位置删除
LTNode* LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* posprev = pos->prev;
	LTNode* posnext = pos->next;
	free(pos);
	posprev->next = posnext;
	posprev = posprev;
}

