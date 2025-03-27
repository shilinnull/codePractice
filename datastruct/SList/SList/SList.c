#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"


void SLTPrint(SLTNode* phead) {
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->val);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

SLTNode* SLTBuyNode(SLTDataType x) {
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (!newnode) {
		perror("malloc fail!\n");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* node = SLTBuyNode(x);
	if (*pphead == NULL) {
		*pphead = node;
	}
	else {
		// 找尾
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		ptail->next = node;
	}
}
//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* node = SLTBuyNode(x);
	node->next = *pphead;
	*pphead = node;
}
//尾删
void SLTPopBack(SLTNode** pphead) {
	assert(*pphead && pphead);
	
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else {
		// 找尾
		SLTNode* ptail = *pphead, * prev = NULL;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}

		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}

//头删
void SLTPopFront(SLTNode** pphead) {
	assert(*pphead && pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x) {
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->val == x)
			return pcur;
		pcur = pcur->next;
	}
	return NULL;
}

//在指定位置之前插⼊数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(*pphead && pphead);
	SLTNode* node = SLTBuyNode(x);
	if (pos == *pphead) {
		SLTPushFront(pphead, x);
	}
	else {
		// 找前一个
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		node->next = pos;
		prev->next = node;
	}
}
//在指定位置之后插⼊数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* node = SLTBuyNode(x);
	node->next = pos->next;
	pos->next = node;
}

//删除pos结点
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(pos && pphead && *pphead);
	if (pos == *pphead) {
		// 头删
		SLTPopFront(pphead);
	}
	else {
		// 找前一个
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;

		free(pos);
		pos = NULL;
	}
}
//删除pos之后的结点
void SLTEraseAfter(SLTNode* pos) {
	assert(pos && pos->next);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

//销毁链表
void SListDestroy(SLTNode** pphead) {
	assert(*pphead && pphead);
	SLTNode* del = *pphead;
	while (del)
	{
		SLTNode* next = del->next;
		free(del);
		del = next;
	}
	*pphead = NULL;
}





