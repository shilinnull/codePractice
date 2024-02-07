#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"


//��ӡ
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

//β��
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

//ͷ��
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

//βɾ
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
		//����һ������ָ��
		SLNode* ptail = *pphead;
		SLNode* prev = NULL;
		//ptail��next������NULL��һֱ��
		while (ptail->next != NULL)
		{
			//��ptail�ĵ�ַ������ָ��prev
			prev = ptail;
			//ptail����������
			ptail = ptail->next;
		}
		free(ptail);
		prev->next = NULL;
	}
	
}

//ͷɾ
void SLTPopFront(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLNode* cur = (*pphead)->next;;
	free(*pphead);
	*pphead = cur;
}

//����
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

//��ָ��λ��֮ǰ��������
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

//ɾ��pos�ڵ�
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

//��ָ��λ��֮���������
void SLTInsertAfter(SLNode* pos, SLNDataType x)
{
	assert(pos && pos->next);
	SLNode* newnode = CreateNode(x);
	SLNode* cur = pos->next;
	pos->next = newnode;
	newnode->next = cur;
}

//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLNode* pos)
{
	assert(pos);
	SLNode* del = pos->next;
	SLNode* cur = del->next;
	pos->next = cur;
	free(del);
	del = NULL;
}

//��������
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