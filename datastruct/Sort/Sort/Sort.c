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

int PartSort1(int* a, int begin, int end)
{
	int left = begin, right = end;
	int keyi = begin;

	while (left < right)
	{
		// ×ó±ßÕÒ´ó
		while (left < right && a[left] <= a[keyi])
			++left;
		// ÓÒ±ßÕÒÐ¡
		while (left < right && a[right] >= a[keyi])
			--right;
		
		// ½»»»
		if(left < right)
			Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}

int PartSort2(int* a, int begin, int end)
{
	int key = a[begin];
	int holei = begin;

	while (begin < end)
	{
		// ÓÒ±ßÕÒÐ¡
		while (begin < end && a[end] >= key)
		{
			--end;
		}

		a[holei] = a[end];
		holei = end;

		// ×ó±ßÕÒ´ó
		while (begin < end && a[begin] <= key)
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
	int cur = begin + 1, prev = begin;
	int keyi = begin;
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur) 
			Swap(&a[cur], &a[prev]);
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int keyi = PartSort2(a, begin, end);

	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

void QuickSortNonR(int* a, int begin, int end)
{
}

void MergeSort(int* a, int n)
{
}

void MergeSortNonR(int* a, int n)
{
}

void CountSort(int* a, int n)
{
}


