#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//�ڱ�λ��ʼ��
ListNode* ListInit() {
	ListNode* pHead = ListCreate(-1);
	pHead->_next = pHead->_prev = pHead;
	return pHead;
}
// �������������ͷ���.
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
// ˫����������
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
// ˫�������ӡ
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
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* node = ListCreate(x);
	ListNode* pcur = pHead->_prev;
	pcur->_next = node;
	node->_next = pHead;
	node->_prev = pcur;
	pHead->_prev = node;
}
// ˫������βɾ
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
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* node = ListCreate(x);
	ListNode* pcur = pHead->_next;
	node->_next = pcur;
	pcur->_prev = node;
	pHead->_next = node;
	node->_prev = pHead;
}
// ˫������ͷɾ
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
// ˫���������
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
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x) {
	assert(pos);
	ListNode* pcur = pos->_prev;
	ListNode* node = ListCreate(x);
	pcur->_next = node;
	node->_prev = pcur;
	node->_next = pos;
	pos->_prev = node;
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos) {
	assert(pos);
	ListNode* pcur = pos->_prev;
	ListNode* next = pos->_next;
	pcur->_next = next;
	next->_prev = pcur;
	free(pos);
	pos = NULL;
}