#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//������
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

//���
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

	//���µ�������

	//for (int i = 0; i < sz; i++)
	//{
	//	AdjustUp(a, i);
	//}

	for (int i = (sz-1-1)/2; i >= 0; --i)
	{
		AdjustDown(a, sz,i);
	}

	//��ӡ
	printf("����ǰ:");
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");

	//����
	int end = sz - 1;
	while (end > 0)
	{
		//�������һ��ֵ���н��������һ�����������������
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}

	printf("�����:");
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}