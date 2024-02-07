#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//堆排序
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(int* a,int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
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

//大堆
void AdjustDown(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
		{
			++child;
		}

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

int main()
{
	int a[] = { 4,6,2,1,5,8,2,9 };
	int sz = sizeof(a) / sizeof(a[0]);

	//向下调整建堆

	//for (int i = 0; i < sz; i++)
	//{
	//	AdjustUp(a, i);
	//}

	for (int i = (sz-1-1)/2; i >= 0; --i)
	{
		AdjustDown(a, sz,i);
	}

	//打印
	printf("排序前:");
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");

	//排序
	int end = sz - 1;
	while (end > 0)
	{
		//根和最后一个值进行交换，最后一个数不看做堆里面的
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}

	printf("排序后:");
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}