#include"Sort.h"


void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// ѡ������
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);

		++begin;
		--end;
	}
}

// ������
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
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

void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}

// ð������
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}

// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int left, int right)
{
	int begin = left, end = right;
	int keyi = begin;

	while (begin < end)
	{
		while (begin < end && a[begin] < a[keyi])
		{
			++begin;
		}
		while (begin < end && a[end] > a[keyi])
		{
			--end;
		}

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyi]);
	return begin;
}
// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int key = a[left];
	int holei = left;

	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[holei] = a[right];
		holei = right;
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[holei] = a[left];
		holei = left;
	}
	a[holei] = key;
	return left;
}
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int prev = left, cur = prev + 1;
	int keyi = left;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[cur], &a[prev]);
		++cur;
	}
	Swap(&a[prev], &a[keyi]);
	keyi = prev;
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int key = PartSort3(a, left, right);
	QuickSort(a, left, key - 1);
	QuickSort(a, key+1, right);

}

#include"stack.h"

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right)
{
	ST s;
	StackInit(&s);
	StackPush(&s, right);
	StackPush(&s, left);

	while (!StackEmpty(&s))
	{
		int begin = StackTop(&s);
		StackPop(&s);
		int end = StackTop(&s);
		StackPop(&s);

		int keyi = PartSort3(a, begin, end);
		if (begin < keyi-1)
		{
			StackPush(&s, keyi - 1);
			StackPush(&s, begin);
		}
		if (keyi+1 < end)
		{
			StackPush(&s, end);
			StackPush(&s, keyi + 1);
		}
	}
	StackDestroy(&s);
}


// �鲢����ݹ�ʵ�� 
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = (begin + end) >> 1;

	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);


	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	for (int i = begin; i <= end; i++)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			// ����
			// [i,i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			
			// �����߽����n�˾�����ѭ��
			//if (begin2 >= n)
			//	break;
			
			if (end1 > n || begin2 > n)
				break;


			// end2���ڱ߽��˾�����һ��
			if (end2 >= n)
				end2 = n - 1;

			// �鲢
			int index = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}

			// �鲢һ�Σ�������ԭ����һ��
			memcpy(a + i, tmp + i, (end2 - i + 1) * sizeof(int));
		}
		gap *= 2;
	}
	free(tmp);
}

// �������� 
void CountSort(int* a, int n)
{
	// ���������С��
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}

	// ��Χ
	int range = max - min + 1;

	// ��ʼ����ô��ķ�Χ�Ŀռ�
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
	{
		perror("malloc fail\n");
		return;
	}

	// ��ʼ��
	memset(count, 0, sizeof(int) * range);

	// ͳ�ƴ���
	for (int i = 0; i < n; i++)
	{
		// �����0��Ԫ�ص�λ����100��
		// ����-min����С��ֵ 100 - 100 ���Ƿŵ���0��λ����
		count[a[i] - min]++;
	}

	int j = 0;
	for (int i = 0; i < range; i++)
	{
		// ÿ��λ���ߵĴ���
		while (count[i]--)
		{
			// ��i��λ�ü���ԭ����ֵ����ԭ����
			a[j++] = i + min;
		}
	}

	free(count);
}