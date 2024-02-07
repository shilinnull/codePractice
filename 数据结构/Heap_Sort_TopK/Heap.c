#include"Heap.h"

void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->capacity = php->size = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustUp(HPDataType* a, int child)
{
	//ÿ�Σ����ӽڵ�-1/2�����Ǹ��׽ڵ�
	int parent = (child - 1) / 2;
	//��child����0�ͼ���
	while (child > 0)
	{
		//���ｨ����С�ѣ�������ӽڵ�С�ڸ��׽ھͽ���
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);

			//Ȼ�󽫸��׸���
			child = parent;
			parent =(child - 1) / 2;
		}
		else
		{
			//������ڸ��׻��ߵ��ھͲ�������
			break;
		}
	}
}

void AdjustUp_Big(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}

	//push�ǵ������
	php->a[php->size] = x;
	php->size++;

	//���ϵ���,��Ϊsize���ȷ�ֵ��++���������һ��λ����size-1
	AdjustUp(php->a, php->size - 1);
}

void AdjustDown(HPDataType* a, int size, int parent)
{
	//���Ӿ��Ǹ���*2+1
	int child = parent * 2 + 1;
	//�������С�ڸ����ͼ���
	while (child < size)
	{
		//��������С�����������ˣ�����һ��
		//��������Ѿ������������һ������С�ڸ������ܼ���
		if (child + 1 < size && a[child + 1] < a[child])
			++child;

		
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
void AdjustDown_Big(HPDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
			++child;
		
		if (a[child] > a[parent])
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

void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	/*
	ɾ���ڵ��ǽ����ϵ�Ԫ�ؽ���ɾ��
	�Ƚ��н���������һ��Ԫ�غ����һ��Ԫ�ؽ��н���
	Ȼ����н���Ч����--
	*/
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	
	//���µ���
	AdjustDown(php->a, php->size - 1, 0);
}
HPDataType HeapTop(HP* php)
{
	assert(php);
	return php->a[0];
}
size_t HeapSize(HP* php)
{
	assert(php);
	return php->size - 1;
}
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

