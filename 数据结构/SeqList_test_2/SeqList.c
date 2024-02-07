

#include"SepList.h"


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

void SLCheckCapacity(SL* ps)
{
	assert(ps);

	if (ps->capacity == ps->size)
	{
		SLDataType newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * 2 * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}


//β��
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//�������
	SLCheckCapacity(ps);

	ps->a[ps->size++] = x;
}

//ͷ��
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	SLCheckCapacity(ps);

	int tail = ps->size-1;

	while (tail > 0)
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
	ps->size--;
}

//ͷɾ
void SLPopFront(SL* ps)
{
	assert(ps);

	for (size_t i = 0; i < ps->size-1; i++)
	{
		ps->a[i] = ps->a[i + 1];
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
	int end = ps->size;
	while (end > pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos - 1] = x;
	ps->size++;
}

//������λ��֮ǰɾ��
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	int end = pos-1;
	while (end<=ps->size)
	{
		ps->a[end - 1] = ps->a[end];
		end++;
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
		{
			return true;
		}
	}
	return false;
}

