
#include"SList.h"


//��ӡ
void SLTPrint(SLNode* phead)
{
	//��ͷ�ڵ�ĵ�ַ���浽cur��
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d-> ", cur->val);
		//cur�Ǳ�����һ���ڵ�ĵ�ַ
		cur = cur->next;
	}
	printf("NULL\n");
}


//���ٿռ�
SLNode* CreateNode(SLNDataType x)
{
	//mallocһ���µĿռ�
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	//��������Ŀռ�ֱ�Ӹ�ֵ
	newnode->val = x;
	//��һ��next��ֵΪ��
	newnode->next = NULL;
	//����һ���µĿռ�
	return newnode;
}



//β��
void SLTPushBack(SLNode** pphead, SLNDataType x)
{
	//��������ռ�
	SLNode* newnode = CreateNode(x);
	//�ж�ͷ�Ƿ�Ϊ�գ����Ϊ�գ��ͽ��¿��ٵĿռ丳��ͷ
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//��ͷָ�����β
		SLNode* tail = *pphead;
		//��β
		while (tail->next != NULL)
		{
			//�ҵ���βȻ�����
			tail = tail->next;
		}
		//���Ǹ����صĿռ丳ֵ��β��next
		tail->next = newnode;
	}
}

//ͷ��
void SLTPushFront(SLNode** pphead, SLNDataType x)
{
	//����ڵ�
	SLNode* newnode = CreateNode(x);
	//���½ڵ��ͷ�ڵ���������
	newnode->next = *pphead;
	//���µĽڵ��Ϊͷ�ڵ�
	*pphead = newnode;	
}


//βɾ
void SLTPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	//��ǰ����ֻ��һ���ڵ��ʱ��
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
		prev->next = ptail->next;
		free(ptail);
		ptail = NULL;
	}
}

//ͷɾ
void SLTPopFront(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	//����һ����ʱָ�룬���ڶ����ڵ㸳ֵ����ʱָ��
	SLNode* next = (*pphead)->next;
	//�ͷ�ͷ�ڵ�
	free(*pphead);
	//����ʱ�ڵ���ͷ�ڵ�
	*pphead = next;
}

//����
SLNode* SListFind(SLNode** phead, SLNDataType x)
{
	assert(phead);
	SLNode* pcur = *phead;
	while (pcur != NULL)
	{
		if (pcur->val == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}


//��ָ��λ��֮ǰ��������
void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x)
{
	assert(pphead);
	//������Ϊ�գ�posҲ����Ϊ��
	assert(pos);
	assert(*pphead);
	SLNode* node = CreateNode(x);
	//����ֻ��һ���ڵ��ֻ��һ���ڵ������£�ֱ�ӽ������������Ľڵ㸳��ͷ
	if ((*pphead)->next == NULL || pos == *pphead)
	{
		node->next = *pphead;
		*pphead = node;
		return;
	}
	SLNode* prev = *pphead;
	//��pos��ǰһ���ڵ�
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	//����
	node->next = pos;
	prev->next = node;
}

//��ָ��λ��֮���������
void SLTInsertAfter(SLNode* pos, SLNDataType x)
{
	assert(pos);
	SLNode* node = CreateNode(x);
	//����
	node->next = pos->next;
	pos->next = node;
}




//ɾ��pos�ڵ�
void SLTErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);
	//�ж�pos�ǲ���ͷ
	if (pos == *pphead)
	{
		*pphead = (*pphead)->next;
		free(pos);
		return;
	}
	//��pos��ǰһ���ڵ�
	SLNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	prev->next = pos->next;
	free(pos);
	pos = NULL;
}



//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLNode* pos)
{
	assert(pos && pos->next);
	SLNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;

}

//��������
void SListDesTroy(SLNode** pphead)
{
	assert(pphead);
	SLNode* pcur = *pphead;

	while (pcur != NULL)
	{
		SLNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}

