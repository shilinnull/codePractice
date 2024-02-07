#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

//��ʼ���ڱ�λ
LTNode* LTInit()
{
	LTNode* phead = LTcreate(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//�����ڵ�
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

//����
void LTDestroy(LTNode* phead);
//��ӡ
void LTPrint(LTNode* phead)
{
	assert(phead);
	printf("�ڱ�λ<->");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<->", cur->val);
		cur = cur->next;
	}
	printf("\n");
}
//�ж��Ƿ�Ϊ��
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	return phead->val == 0;
}

//β��
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


//βɾ
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
//ͷ��
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
//ͷɾ
void LTPopFront(LTNode* phead)
{
	assert(phead);
	LTNode* first = phead->next;
	LTNode* second = first->next;
	free(first);
	phead->next = second;
	second->prev = phead;
}

//����
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

//ָ��λ�õ�ǰ�����
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
//ָ��λ��ɾ��
LTNode* LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* posprev = pos->prev;
	LTNode* posnext = pos->next;
	free(pos);
	posprev->next = posnext;
	posprev = posprev;
}

