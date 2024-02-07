
#include"Heap.h"

//С���㷨

// �ѵĹ���
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}

//����
void Swap(int* p1, int* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//���ϵ���
void AjustUp(HPDataType* a, HPDataType child)
{
	HPDataType parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->capacity == hp->size)
	{
		int newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			exit(-1);
		}
		hp->a = tmp;
		hp->capacity = newcapacity;
	}

	hp->a[hp->size] = x;
	hp->size++;

	AjustUp(hp->a, hp->size - 1);
}

//���µ���
void AdjustDown(int* a, int size, int parent)
{
	//��������С��������˾͸���
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);

	//��β����
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;

	//�Ӹ����µ���
	AdjustDown(hp->a, hp->size, 0);
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);

	return hp->a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->size;
}
// �ѵ��п�
bool HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->size == 0;
}

// �ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);

	free(hp->a);
	hp->capacity = hp->size = 0;
}