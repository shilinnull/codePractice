#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//哨兵位初始化
ListNode* ListInit() {
	ListNode* pHead = ListCreate(-1);
	pHead->_next = pHead->_prev = pHead;
	return pHead;
}
// 创建返回链表的头结点.
ListNode* ListCreate(LTDataType x) {
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL) {
		perror("malloc fail!\n");
		exit(-1);
	}
	newnode->_next = NULL;
	newnode->_prev = NULL;
	newnode->_val = x;
	return newnode;
}
// 双向链表销毁
void ListDestory(ListNode* pHead) {
	assert(pHead);
	ListNode* pcur = pHead->_next;
	while (pcur != pHead)
	{
		ListNode* next = pcur->_next;
		free(pcur);
		pcur = next;
	}
	free(pHead);
	pHead = NULL;
}
// 双向链表打印
void ListPrint(ListNode* pHead) {
	assert(pHead);
	ListNode* pcur = pHead->_next;
	while (pcur != pHead)
	{
		printf("%d->", pcur->_val);
		pcur = pcur->_next;
	}
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* node = ListCreate(x);
	ListNode* pcur = pHead->_prev;
	pcur->_next = node;
	node->_next = pHead;
	node->_prev = pcur;
	pHead->_prev = node;
}
// 双向链表尾删
void ListPopBack(ListNode* pHead) {
	assert(pHead);
	assert(pHead->_next != pHead);
	ListNode* ptail = pHead->_prev->_prev;
	ListNode* del = pHead->_prev;
	ptail->_next = pHead;
	pHead->_prev = ptail;
	free(del);
	del = NULL;
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* node = ListCreate(x);
	ListNode* pcur = pHead->_next;
	node->_next = pcur;
	pcur->_prev = node;
	pHead->_next = node;
	node->_prev = pHead;
}
// 双向链表头删
void ListPopFront(ListNode* pHead) {
	assert(pHead);
	assert(pHead->_next != pHead);
	ListNode* pcur = pHead->_next->_next;
	ListNode* del = pHead->_next;
	pcur->_prev = pHead;
	pHead->_next = pcur;
	free(del);
	del = NULL;
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x) {
	assert(pHead);
	assert(pHead->_next != pHead);
	ListNode* pcur = pHead->_next;
	while (pcur != pHead)
	{
		if (pcur->_val == x)
			return pcur;
		pcur = pcur->_next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x) {
	assert(pos);
	ListNode* pcur = pos->_prev;
	ListNode* node = ListCreate(x);
	pcur->_next = node;
	node->_prev = pcur;
	node->_next = pos;
	pos->_prev = node;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos) {
	assert(pos);
	ListNode* pcur = pos->_prev;
	ListNode* next = pos->_next;
	pcur->_next = next;
	next->_prev = pcur;
	free(pos);
	pos = NULL;
}