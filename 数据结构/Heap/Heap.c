
#include"Heap.h"

//小堆算法

// 堆的构建
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}

//交换
void Swap(int* p1, int* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//向上调整
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

// 堆的插入
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

//向下调整
void AdjustDown(int* a, int size, int parent)
{
	//假设左孩子小，假设错了就更新
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
// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);

	//首尾交换
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;

	//从根向下调整
	AdjustDown(hp->a, hp->size, 0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);

	return hp->a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->size;
}
// 堆的判空
bool HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->size == 0;
}

// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);

	free(hp->a);
	hp->capacity = hp->size = 0;
}