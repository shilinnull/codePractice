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
	//每次（孩子节点-1/2）就是父亲节点
	int parent = (child - 1) / 2;
	//当child大于0就继续
	while (child > 0)
	{
		//这里建立的小堆，如果孩子节点小于父亲节就交换
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);

			//然后将父亲更新
			child = parent;
			parent =(child - 1) / 2;
		}
		else
		{
			//如果大于父亲或者等于就不跳出了
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

	//push是到最后了
	php->a[php->size] = x;
	php->size++;

	//向上调整,因为size是先放值后++，所以最后一个位置是size-1
	AdjustUp(php->a, php->size - 1);
}

void AdjustDown(HPDataType* a, int size, int parent)
{
	//孩子就是父亲*2+1
	int child = parent * 2 + 1;
	//如果孩子小于个数就继续
	while (child < size)
	{
		//假设左孩子小，如果假设错了，更新一下
		//如果孩子已经到最后，最后的下一个必须小于个数才能继续
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
	删除节点是将顶上的元素进行删除
	先进行交换，将第一个元素和最后一个元素进行交换
	然后进行将有效个数--
	*/
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	
	//向下调整
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

