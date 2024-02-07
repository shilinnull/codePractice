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
		// ��¼ÿ��i��λ��
		int end = i;
		// ��i+1��λ�ñ���
		int tmp = a[end + 1];
		// һ������
		while (end >= 0)
		{
			// ������������С��ǰ�����һ���ͽ������󸲸ǣ�
			// Ȼ��end--����������
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				// ������ڻ��ߵ����˾�����
				break;
			}
		}
		// ��Ϊ--end�ˣ����Ծ�Ҫ��end+1��λ�÷Ÿոձ����ֵtmp
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
	
	// gap > 1ʱ��Ԥ����Ŀ�������ӽ�����
	// gap == 1��ֱ�Ӳ�������Ŀ������������
	while (gap > 1)
	{
		// gap = gap / 2; // log 2 N
		gap = gap / 3 + 1; // log 3 N

		// ÿ����gap��
		for (int j = 0; j < n - gap; j++)
		{
			// ��������
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
	// ����
	for (int i = (n - 1 - 1)/2; i >= 0 ; --i)
	{
		AdjustDwon(a, n, i);
	}

	// ����
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}

// ѡ������
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		// ��ͷ��
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			// ���i��λ�ñ�miniС�͸���һ��
			if (a[i] < a[mini])
			{
				mini = i;
			}
			//���i��λ�ñ�maxi��͸���һ��
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		// �ߵ������˵��С��Ҫ����߽���һ��
		Swap(&a[mini], &a[begin]);
		// ע�⣺����begin��ߵĺ�maxi�����Ҫ����һ��maxi
		if (begin == maxi)
		{
			maxi = mini;
		}
		// Ȼ�󽻻�maxi��end
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

// ����ȡ��
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
	// ����ȡ��
	int midi = GetMidi(a, begin, end);
	Swap(&a[midi], &a[begin]);

	// Ҫ������߿�ʼ
	int left = begin, right = end;
	int keyi = begin;

	while (left < right)
	{
		// �ұ���С
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		// ����Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		// �ҵ��ˣ��ͽ���
		Swap(&a[left], &a[right]);
	}

	// ��������ߵĺ�keyi��Ȼ�����һ��keyi
	Swap(&a[left], &a[keyi]);

	return left;
}

// ���������ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	Swap(&a[midi], &a[begin]);

	int key = a[begin];
	int holei = begin;

	while (begin < end)
	{
		// �ұ���С
		while (begin < end && a[end] >= key)
		{
			--end;
		}

		a[holei] = a[end];
		holei = end;

		// ����Ҵ�
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

// ��������ǰ��ָ�뷨 
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

	// С����
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
// �������� �ǵݹ�ʵ�� 
void QuickSortNonR(int* a, int begin, int end)
{
	ST s;
	StackInit(&s);
	// �����Һ�����
	StackPush(&s, end);
	StackPush(&s, begin);

	while (!StackEmpty(&s))
	{
		// �ȳ�������
		int left = StackTop(&s);
		StackPop(&s);
		int right = StackTop(&s);
		StackPop(&s);

		// ����
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

	// �ָ�  // ��������һλ�൱�� /2 
	int mid = (begin + end) >> 1; 
	
	// �ݹ�
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	// [begin mid][mid+1 end]  �鲢
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

	// ������ԭ����

	for (int i = begin; i <= end; ++i)
	{
		a[i] = tmp[i];
	}

	//memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin) + 1);
}

// �鲢����ݹ�ʵ��
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
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// ����ڶ��鲻���ڣ���һ�鲻�ù鲢��
			if (begin2 >= n)
				break;
			//if (end1 >= n || begin2 >= n)
			//	break;

			// ����ڶ�����ұ߽�Խ�磬����һ��
			if (end2 >= n)
				end2 = n - 1;

			//if (end1 >= n)
			//{
			//	end1 = n - 1;

			//	// ����������
			//	begin2 = n;
			//	end2 = n - 1;
			//}
			//else if (begin2 >= n)
			//{
			//	// ����������
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
	//ͳ�ƴ���
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