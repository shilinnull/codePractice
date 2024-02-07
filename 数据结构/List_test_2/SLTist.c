#include"SLTist.h"
// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc fail!\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

// 单链表打印
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

// 单链表尾插
void SListPushBack(SListNode** pphead, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	if(*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
// 单链表的头插
void SListPushFront(SListNode** pphead, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}
// 单链表的尾删
void SListPopBack(SListNode** pphead)
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
		SListNode* tail = *pphead;
		SListNode* prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
	

}
// 单链表头删
void SListPopFront(SListNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SListNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = NULL;
	*pphead = tmp;
}
// 单链表查找
SListNode* SListFind(SListNode* pphead, SLTDateType x)
{
	assert(pphead);
	SListNode* pcur = pphead;
	while (pcur != NULL)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode** pphead, SListNode* pos, SLTDateType x)
{
	assert(pos);
	assert(pphead);
	assert(*pphead);
	SListNode* node = BuySListNode(x);
	if ((*pphead)->next == NULL)
	{
		*pphead = node;
	}
	SListNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	node->next = pos;
	prev->next = node;
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{

}

// 在pos的前面插入
void SLTInsert(SListNode** pphead, SListNode* pos, SLTDateType x);
// 删除pos位置
void SLTErase(SListNode** pphead, SListNode* pos);
void SLTDestroy(SListNode** pphead);