#include"SepList.h"

//��ʼ��˳���
void SLInit(SL* ps)
{
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//����˳���
void SLDestroy(SL* ps)
{
	if(ps->a)
		free(ps->a);
	ps->capacity = ps->size = 0;
}

//�������
void SLCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity) {
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//�ռ䲻������Ҫ����
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL) {
			perror("realloc fail!");
			return;
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}

//β��
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//�жϿռ乻������
	SLCheckCapacity(ps);
	//ֱ�Ӳ�������
	ps->a[ps->size++] = x;
}

//ͷ��
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	//�жϿռ��Ƿ��㹻������������
	SLCheckCapacity(ps);
	//�ռ��㹻����ʷ���ݺ���һλ
	// Ų������
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
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
	//�ú����������ǰŲ��һλ
	for (size_t i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//��ӡ˳���
void SLPrint(SL* ps)
{
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//�жϿռ��Ƿ�Ϊ��
bool SLIsEmpty(SL* ps)
{
	assert(ps);
	return ps->size == 0;
}


//������λ��֮ǰ����
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	//��Ҫ���Ʒ�Χ
	assert(pos >= 0 && pos <= ps->size);
	//�������
	SLCheckCapacity(ps);
	
	for (size_t i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}

//������λ��֮ǰɾ��
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(!SLIsEmpty(ps));
	//assert(ps->size > 0);//Ҳ��������д

	assert(pos >= 0 && pos <= ps->size);//����pos

	for (size_t i = pos; i < ps->size-1; i++)
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
	}
	return false;
}


