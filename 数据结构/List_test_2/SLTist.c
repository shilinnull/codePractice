#include"SLTist.h"
// ��̬����һ���ڵ�
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

// �������ӡ
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

// ������β��
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
// �������ͷ��
void SListPushFront(SListNode** pphead, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}
// �������βɾ
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
// ������ͷɾ
void SListPopFront(SListNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SListNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = NULL;
	*pphead = tmp;
}
// ���������
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
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
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
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos)
{

}

// ��pos��ǰ�����
void SLTInsert(SListNode** pphead, SListNode* pos, SLTDateType x);
// ɾ��posλ��
void SLTErase(SListNode** pphead, SListNode* pos);
void SLTDestroy(SListNode** pphead);