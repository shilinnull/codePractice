#include"Sort.h"


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

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		// 记录每次i的位置
		int end = i;
		// 将i+1的位置保存
		int tmp = a[end + 1];
		// 一次排序
		while (end >= 0)
		{
			// 如果后面的数字小于前面的那一个就进行往后覆盖，
			// 然后end--，继续排序
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				// 如果大于或者等于了就跳出
				break;
			}
		}
		// 因为--end了，所以就要在end+1的位置放刚刚保存的值tmp
		a[end + 1] = tmp;
	}
}

void BubbleSort(int* a,int n)
{
	for (int i = 0; i < n-1; i++)
	{
		bool exchange = false;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);

				exchange = true;
			}
		}
		if (exchange == false)
			break;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	
	// gap > 1时是预排序，目的让他接近有序
	// gap == 1是直接插入排序，目的是让他有序
	while (gap > 1)
	{
		// gap = gap / 2; // log 2 N
		gap = gap / 3 + 1; // log 3 N

		// 每次排gap次
		for (int j = 0; j < n - gap; j++)
		{
			// 插入排序
			int end = j;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}


	/*int gap = 3;
	for (int i = 0; i < gap; i++)
	{
		for (int j = 0; j < n - gap; j += gap)
		{
			int end = j;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}*/
}

// 堆排序
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
	// 建堆
	for (int i = (n - 1 - 1)/2; i >= 0 ; --i)
	{
		AdjustDwon(a, n, i);
	}

	// 排序
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}

// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		// 两头找
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			// 如果i的位置比mini小就更新一下
			if (a[i] < a[mini])
			{
				mini = i;
			}
			//如果i的位置比maxi大就更新一下
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		// 走到这里就说明小的要和左边交换一下
		Swap(&a[mini], &a[begin]);
		// 注意：这里begin左边的和maxi相等了要更新一下maxi
		if (begin == maxi)
		{
			maxi = mini;
		}
		// 然后交换maxi和end
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

// 三数取中
int GetMidi(int* a, int left, int right)
{
	//int midi = (begin + end) / 2;
	int mid = (left + right) >> 1;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
}

int PartSort1(int* a, int begin, int end)
{
	// 三数取中
	int midi = GetMidi(a, begin, end);
	Swap(&a[midi], &a[begin]);

	// 要在最左边开始
	int left = begin, right = end;
	int keyi = begin;

	while (left < right)
	{
		// 右边找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		// 左边找大
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		// 找到了，就交换
		Swap(&a[left], &a[right]);
	}

	// 交换的左边的和keyi，然后更新一下keyi
	Swap(&a[left], &a[keyi]);

	return left;
}

// 快速排序挖坑法
int PartSort2(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	Swap(&a[midi], &a[begin]);

	int key = a[begin];
	int holei = begin;

	while (begin < end)
	{
		// 右边找小
		while (begin < end && a[end] >= key)
		{
			--end;
		}

		a[holei] = a[end];
		holei = end;

		// 左边找大
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

// 快速排序前后指针法 
int PartSort3(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	Swap(&a[begin], &a[midi]);

	int prev = begin;
	int cur = prev + 1;
	int keyi = begin;
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[prev], &a[cur]);

		++cur;
	}

	Swap(&a[keyi], &a[prev]);
	keyi = prev;
	return prev;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	// 小区间
	if (end - begin + 1 < 10)
	{
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		int keyi = PartSort3(a, begin, end);

		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
}


#include"Stack.h"
// 快速排序 非递归实现 
void QuickSortNonR(int* a, int begin, int end)
{
	ST s;
	StackInit(&s);
	// 先入右后入左
	StackPush(&s, end);
	StackPush(&s, begin);

	while (!StackEmpty(&s))
	{
		// 先出左后出右
		int left = StackTop(&s);
		StackPop(&s);
		int right = StackTop(&s);
		StackPop(&s);

		// 排序
		int keyi = PartSort3(a, left, right);
		// [left keyi-1] keyi [keyi+1 right]
		if (left < keyi - 1)
		{
			StackPush(&s, keyi - 1);
			StackPush(&s, left);
		}
		if (keyi + 1 < right)
		{
			StackPush(&s, right);
			StackPush(&s, keyi + 1);
		}
	}

	StackDestroy(&s);
}



void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	// 分割  // 这里右移一位相当于 /2 
	int mid = (begin + end) >> 1; 
	
	// 递归
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	// [begin mid][mid+1 end]  归并
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

	// 拷贝回原数组

	for (int i = begin; i <= end; ++i)
	{
		a[i] = tmp[i];
	}

	//memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin) + 1);
}

// 归并排序递归实现
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail!\n");
		return;
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

// 归并排序非递归实现
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
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// 如果第二组不存在，这一组不用归并了
			if (begin2 >= n)
				break;
			//if (end1 >= n || begin2 >= n)
			//	break;

			// 如果第二组的右边界越界，修正一下
			if (end2 >= n)
				end2 = n - 1;

			//if (end1 >= n)
			//{
			//	end1 = n - 1;

			//	// 不存在区间
			//	begin2 = n;
			//	end2 = n - 1;
			//}
			//else if (begin2 >= n)
			//{
			//	// 不存在区间
			//	begin2 = n;
			//	end2 = n - 1;
			//}
			//else if (end2 >= n)
			//{
			//	end2 = n - 1;
			//}

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

			memcpy(a + i, tmp + i, (end2 - i + 1) * sizeof(int));
		}
		gap *= 2;
	}

	free(tmp);
}

void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;

	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
	{
		perror("malloc fail!\n");
		return;
	}

	memset(count, 0, sizeof(int) * range);
	//统计次数
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	int i = 0;
	for (int j = 0; j < range; j++)
	{
		while (count[j]--)
		{
			a[i++] = j + min;
		}
	}

	free(count);
}