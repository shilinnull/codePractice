#include"SeqList.h"
#include"Contact.h"


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
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

static void SLCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("relloc fail!\n");
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
	SLCheckCapacity(ps);
	ps->a[ps->size++] = x;
}

//ͷ��
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	for (int i = ps->size - 1; i >= 0; --i)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->size++;
}

//βɾ
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(!SLIsEmpty(ps));
	ps->size--;
}

//ͷɾ
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(!SLIsEmpty(ps));
	for (int i = 0; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//��ӡ˳���
void SLPrint(SL* ps)
{
	assert(ps);
	assert(!SLIsEmpty(ps));
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//�ж��Ƿ�Ϊ��
bool SLIsEmpty(SL* ps)
{
	assert(ps);
	return ps->size == 0;
}

//������λ��֮ǰ����
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos - 1] = x;
	ps->size++;
}

//������λ��֮ǰɾ��
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(!SLIsEmpty(ps));
	assert(pos >= 0 && pos <= ps->size);
	for (int i = pos - 1; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//����˳���

//bool SLFind(SL* ps, SLDataType x)
//{
//	assert(ps);
//	assert(!SLIsEmpty(ps));
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (ps->a[i] == x)
//			return true;
//	}
//	return false;
//}
