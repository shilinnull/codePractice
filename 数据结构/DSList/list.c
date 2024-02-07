

#include"list.h"

//哨兵位初始化
ListNode* ListInit()
{
	ListNode* pHead = ListCreate(-1);
	pHead->_next = pHead;
	pHead->_prev = pHead;
	return pHead;
}


// 创建返回链表的头结点
ListNode* ListCreate(LTDataType* x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("malloc fail!\n");
		exit(-1);
	}
	newnode->_val = x;
	newnode->_next = NULL;
	newnode->_prev = NULL;
	return newnode;
}
// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(pHead);
	pHead = NULL;
}
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	ListNode* tail = pHead->_next;
	printf("哨兵位->");
	while (tail != pHead)
	{
		printf("%d->", tail->_val);
		tail = tail->_next;
	}
	printf("NULL\n");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* tail = pHead->_prev;
	ListNode* newnode = ListCreate(x);
	// phead   tail   newnode
	tail->_next = newnode;
	newnode->_prev = tail;
	newnode->_next = pHead;
	pHead->_prev = newnode;
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->_next != pHead);
	ListNode* tail = pHead->_prev;
	ListNode* tailprev = tail->_prev;
	free(tail);
	tailprev->_next = pHead;
	pHead->_prev = tailprev;
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	ListNode* newnode = ListCreate(x);
	pHead->_next = newnode;
	newnode->_prev = pHead;
	newnode->_next = cur;
	cur->_prev = newnode;
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->_next != pHead);
	ListNode* first = pHead->_next;
	ListNode* second = first->_next;
	pHead->_next = second;
	second->_prev = pHead;
	free(first);
	first = NULL;
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_val == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = ListCreate(x);
	ListNode* prev = pos->_prev;
	prev->_next = newnode;
	newnode->_prev = prev;
	pos->_prev = newnode;
	newnode->_next = pos;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}