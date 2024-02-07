

#include"list.h"

//�ڱ�λ��ʼ��
ListNode* ListInit()
{
	ListNode* pHead = ListCreate(-1);
	pHead->_next = pHead;
	pHead->_prev = pHead;
	return pHead;
}


// �������������ͷ���
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
// ˫����������
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
// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	ListNode* tail = pHead->_next;
	printf("�ڱ�λ->");
	while (tail != pHead)
	{
		printf("%d->", tail->_val);
		tail = tail->_next;
	}
	printf("NULL\n");
}
// ˫������β��
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
// ˫������βɾ
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
// ˫������ͷ��
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
// ˫������ͷɾ
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
// ˫���������
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
// ˫��������pos��ǰ����в���
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
// ˫������ɾ��posλ�õĽڵ�
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