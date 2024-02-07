#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"
//��ʼ��˳���
void SLInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}



//����˳���
void SLDestroy(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//����
void SLDilatation(SL* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		SLDataType newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			return;
		}
		ps->capacity = newcapacity;
		ps->a = tmp;
	}
}

//β��
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLDilatation(ps);
	ps->a[ps->size++] = x;
}

//ͷ��
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLDilatation(ps);
	
	SLDataType tail = ps->size-1;
	while (tail>=0)
	{
		ps->a[tail + 1] = ps->a[tail];
		tail--;
	}
	ps->a[0] = x;
	ps->size++;
}

//βɾ
void SLPopBack(SL* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("û�������ˣ��޷�ɾ��\n");
	}
	else
	{
		ps->size--;
	}
}

//�ж��Ƿ�Ϊ��

SL* Islepper(SL* ps)
{
	assert(ps);
	return ps->size == 0;
}

//ͷɾ
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(!Islepper(ps));
	SLDataType prev = 0;
	while (prev < ps->size-1)
	{
		ps->a[prev] = ps->a[prev + 1];
		prev++;
	}
	ps->size--;
}

//��ӡ˳���
void SLPrint(SL* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}



//������λ��֮ǰ����
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLDilatation(ps);
	
	for (size_t i = ps->size+1; i > pos; i--)
	{
		ps->a[i] = ps->a[i-1];
	}
	ps->a[pos-1] = x;
	ps->size++;
}

//������λ��֮ǰɾ��
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	for (size_t i = pos-1; i <ps->size-1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//����˳���
bool SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return true;
		else
			return false;
	}
}

