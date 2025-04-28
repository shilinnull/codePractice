#include "Sort.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void Print_a(int* a, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j + 1] < a[j])
				Swap(&a[j + 1], &a[j]);
		}
	}
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}


void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else break;
			}
			a[end + gap] = tmp;
		}
	}
}

void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			child++;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
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

void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[mini] > a[i])
				mini = i;
			if (a[maxi] < a[i])
				maxi = i;
		}
		if (maxi == begin)
			maxi = mini;
		Swap(&a[mini], &a[begin]);
		Swap(&a[maxi], &a[end]);
		++begin;
		--end;
	}
}

static int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) >> 1;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
	else
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
}

// hoare
int PartSort1(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);

	int keyi = begin;
	while (begin < end)
	{
		// 右边找小
		while (begin < end && a[keyi] <= a[end])
		{
			--end;
		}
		// 左边找大
		while (begin < end && a[keyi] >= a[begin])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyi]);
	return begin;
}

// 挖坑法
int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);

	int holei = begin;
	int key = a[begin];
	while (begin < end)
	{
		while (begin < end && key <= a[end])
		{
			--end;
		}
		a[holei] = a[end];
		holei = end;

		while (begin < end && key >= a[begin])
		{
			++begin;
		}
		a[holei] = a[begin];
		holei = begin;
	}
	a[holei] = key;
	return holei;
}

int PartSort3(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);

	int cur = begin + 1, prev = begin;
	int keyi = begin;
	
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[cur], &a[prev]);
		cur++;
	}

	Swap(&a[keyi], &a[prev]);
	keyi = prev;
	return keyi;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	int keyi = PartSort1(a, begin, end);
	//int keyi = PartSort2(a, begin, end);
	//int keyi = PartSort3(a, begin, end);

	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

#include <stack>
void QuickSortNonR(int* a, int begin, int end)
{
	std::stack<int> s;
	s.push(end);
	s.push(begin);
	while (!s.empty())
	{
		// 取的时候先左后右
		int left = s.top();
		s.pop();
		int right = s.top();
		s.pop();

		int keyi = PartSort1(a, left, right);

		// 入的时候先右后左
		if (keyi + 1 < end)
		{
			s.push(end);
			s.push(keyi + 1);
		}

		if (left < keyi - 1)
		{
			s.push(keyi - 1);
			s.push(left);
		}
	}
}

static void _MergeSort(int *a, int begin, int end, int* tmp)
{
	//if(begin == end)
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;
	
	// 递归
	// [begin, mid]    [mid+1,end]
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin; // 注意i要从begin开始,不是0
	
	// 谁小谁尾插到tmp
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else 
			tmp[i++] = a[begin2++];
	}

	// 到这里把剩下的全部尾插
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];

	// 拷贝回原数组
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin) + 1);
}


void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

void MergeSortNonR(int* a, int n)
{
}

void CountSort(int* a, int n)
{
}


