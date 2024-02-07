#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SLNodeInit(SLNode* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void CreateNode(SLNode* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		SLDateType newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDateType* tmp = (SLDateType*)realloc(ps->a, newcapacity * sizeof(SLDateType));
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			return;
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SLNodePushBack(SLNode* ps, SLDateType x)
{
	assert(ps);
	//检查容量，是否需要扩容
	CreateNode(ps);
	ps->a[ps->size++] = x;
}

void SLNodePrint(SLNode* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void SLNodeFrond(SLNode* ps, SLDateType x)
{
	assert(ps);
	CreateNode(ps);

	SLDateType end = ps->size + 1;
	while (end > 0)
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}

	ps->a[0] = x;
	ps->size++;
}

void SLNodePop(SLNode* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}

void SLNodePopFrond(SLNode* ps)
{
	assert(ps);
	assert(!SLNodeIsEmpty(ps));
	SLDateType cur = 0;
	while (cur <= ps->size + 1)
	{
		ps->a[cur] = ps->a[cur + 1];
		cur++;
	}
	ps->size--;
}

bool SLNodeIsEmpty(SLNode* ps)
{
	assert(ps);
	return ps->size == 0;
}

void SLInsert(SLNode* ps, int pos, SLDateType x)
{
	assert(ps);
	assert(!SLNodeIsEmpty(ps));
	assert(pos >= 0 && pos <= ps->size);
	CreateNode(ps);

	SLDateType cur = ps->size;
	while (cur > pos)
	{
		ps->a[cur] = ps->a[cur - 1];
		cur--;
	}
	ps->size++;
	ps->a[pos] = x;
}

void SLErase(SLNode* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	SLDateType cur = pos - 1;
	while (cur < ps->size - 1)
	{
		ps->a[cur] = ps->a[cur + 1];
		cur++;
	}
	ps->size--;
}

bool SLFind(SLNode* ps, SLDateType x)
{
	assert(ps);
	int i = 0;
	while (i < ps->size)
	{
		if (ps->a[i] == x)
		{
			return true;
		}
		i++;
	}
	return false;
}