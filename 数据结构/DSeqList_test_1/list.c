#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"


//打印
void SLTPrint(SLNode* phead)
{
	assert(phead);
	SLNode* end = phead;
	while (end != NULL)
	{
		printf("%d->", end->val);
		end = end->next;
	}
	printf("NULL\n");
}

SLNode* CreateNode(SLNDataType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("malloc fail\n");
		return -1;
	}
	newnode->next = NULL;
	newnode->val = x;
	return newnode;
}

//尾插
void SLTPushBack(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* newnode = CreateNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//头插
void SLTPushFront(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* newnode = CreateNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
}

//尾删
void SLTPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//定义一个快慢指针
		SLNode* ptail = *pphead;
		SLNode* prev = NULL;
		//ptail的next不等于NULL就一直找
		while (ptail->next != NULL)
		{
			//将ptail的地址赋给慢指针prev
			prev = ptail;
			//ptail继续往下找
			ptail = ptail->next;
		}
		free(ptail);
		prev->next = NULL;
	}
	
}

//头删
void SLTPopFront(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLNode* cur = (*pphead)->next;;
	free(*pphead);
	*pphead = cur;
}

//查找
SLNode* SListFind(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* cur = *pphead;
	while (cur != NULL)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在指定位置之前插入数据
void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x)
{
	assert(pphead);
	assert(pos);
	SLNode* newnode = CreateNode(x);
	if (*pphead == NULL || pos == *pphead)
	{
		newnode->next = *pphead;
		*pphead = newnode;
		return;
	}
	SLNode* next = pos;
	SLNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	prev->next = newnode;
	newnode->next = next;
}

//删除pos节点
void SLTErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);
	if (*pphead == pos)
	{
		free(*pphead);
		pphead = NULL;
		return;
	}

	SLNode* next = pos->next;
	SLNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	free(pos);
	pos = NULL;
	prev->next = next;
}

//在指定位置之后插入数据
void SLTInsertAfter(SLNode* pos, SLNDataType x)
{
	assert(pos && pos->next);
	SLNode* newnode = CreateNode(x);
	SLNode* cur = pos->next;
	pos->next = newnode;
	newnode->next = cur;
}

//删除pos之后的节点
void SLTEraseAfter(SLNode* pos)
{
	assert(pos);
	SLNode* del = pos->next;
	SLNode* cur = del->next;
	pos->next = cur;
	free(del);
	del = NULL;
}

//销毁链表
void SListDesTroy(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLNode* pcur = *pphead;
	if (pcur == NULL)
	{
		SLNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}