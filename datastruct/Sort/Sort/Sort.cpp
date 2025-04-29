#define _CRT_SECURE_NO_WARNINGS 1
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
		// �ұ���С
		while (begin < end && a[keyi] <= a[end])
		{
			--end;
		}
		// ����Ҵ�
		while (begin < end && a[keyi] >= a[begin])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyi]);
	return begin;
}

// �ڿӷ�
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
		// ȡ��ʱ���������
		int left = s.top();
		s.pop();
		int right = s.top();
		s.pop();

		int keyi = PartSort1(a, left, right);

		// ���ʱ�����Һ���
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
	
	// �ݹ�
	// [begin, mid]    [mid+1,end]
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin; // ע��iҪ��begin��ʼ,����0
	
	// ˭С˭β�嵽tmp
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			tmp[i++] = a[begin1++];
		else 
			tmp[i++] = a[begin2++];
	}

	// �������ʣ�µ�ȫ��β��
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];

	// ������ԭ����
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
	int* tmp = (int*)malloc(sizeof(int) * n);

	int gap = 1;
	while (gap < n)
	{
		//int j = 0;
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// ��������
			//if (begin2 >= n)
			//	break;
			if (end1 >= n || begin2 >= n)
				break;

			if (end2 >= n)
				end2 = n - 1;

			// β�嵽tmp
			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
					tmp[j++] = a[begin1++];
				else
					tmp[j++] = a[begin2++];
			}

			// �������ʣ�µ�ȫ��β��
			while (begin1 <= end1)
				tmp[j++] = a[begin1++];
			while (begin2 <= end2)
				tmp[j++] = a[begin2++];
			
			// ������a����
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}// for (int i = 0; i < n; i *= 2)

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
	int *count = (int*)calloc(range, sizeof(int));

	// ͳ��
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	
	// �Ż�ԭ����
	int k = 0;
	for (int j = 0; j < range; j++)
	{
		while (count[j]--)
		{
			a[k++] = j + min;
		}
	}

	free(count);
}

// ��·���ֺ���
KeyWayIndex PartSort3Way(int* a, int left, int right) {
	int key = a[left];

	// left��rightָ����Ǹ�key��ȵ�����
	// [��ʼ, left-1][left, right][right+1, ����]

	int cur = left + 1;
	while (cur <= right) {
		// 1��cur������keyС��С�Ļ�����ߣ�ͬʱ��key�����м�λ��
		// 2��cur������key�󣬴�Ļ����ұ�

		if (a[cur] < key) {
			Swap(&a[left], &a[cur]);
			++cur;
			++left;
		}
		else if (a[cur] > key) {
			Swap(&a[right], &a[cur]);
			--right;
		}
		else {
			++cur;
		}
	}

	KeyWayIndex kwi;
	kwi.leftKeyi = left;
	kwi.rightKeyi = right;
	return kwi;
}

// ����N���������д���ļ���
void CreateNDate()
{
	// ������
	int n = 100000;
	srand((unsigned int)time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		int x = rand() + i;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

// file1�ļ������ݺ�file2�ļ������ݹ鲢��mfile�ļ���
void MergeFile(const char* file1, const char* file2, const char* mfile)
{
	FILE* fout1 = fopen(file1, "r");
	if (fout1 == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}
	FILE* fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}
	FILE* fin = fopen(mfile, "w");
	if (fin == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}
	// ������ڴ�������鲢��˼����ȫ���ƣ�ֻ��������Ӳ���ļ��ж���
	// ���ζ�ȡfile1��file2�����ݣ�˭������С��˭����mfile�ļ���ȥд
	// file1��file2����һ���ļ��������ٰ���һ���ļ�δ�����ļ����ݣ�
	// ����д��mfile�ĺ���
	int num1, num2;
	int ret1 = fscanf(fout1, "%d\n", &num1);
	int ret2 = fscanf(fout2, "%d\n", &num2);
	while (ret1 != EOF && ret2 != EOF)
	{
		if (num1 < num2)
		{
			fprintf(fin, "%d\n", num1);
			ret1 = fscanf(fout1, "%d\n", &num1);
		}
		else
		{
			fprintf(fin, "%d\n", num2);
			ret2 = fscanf(fout2, "%d\n", &num2);
		}
	}
	while (ret1 != EOF)
	{
		fprintf(fin, "%d\n", num1);
		ret1 = fscanf(fout1, "%d\n", &num1);
	}
	while (ret2 != EOF)
	{
		fprintf(fin, "%d\n", num2);
		ret2 = fscanf(fout2, "%d\n", &num2);
	}
	fclose(fout1);
	fclose(fout2);
	fclose(fin);
}

// ���ض�ȡ�������ݸ���
int ReadNNumSortToFile(FILE* fout, int* a, int n, const char* file)
{
	int x = 0;
	// ��ȡn�����ݷŵ�file
	int i = 0;
	while (i < n && fscanf(fout, "%d", &x) != EOF)
	{
		a[i++] = x;
	}
	// һ�����ݶ�û�ж�������˵���ļ��Ѿ�������β��
	if (i == 0)
		return i;
	// ����
	HeapSort(a, i);
	FILE* fin = fopen(file, "w");
	if (fout == NULL)
	{
		printf("���ļ�%sʧ��\n", file);
		exit(-1);
	}
	for (int j = 0; j < i; j++)
	{
		fprintf(fin, "%d\n", a[j]);
	}
	fclose(fin);
	return i;
}

// MergeSortFile�ĵڶ�����ÿ��ȡ���ٸ����ݵ��ڴ�������Ȼ��д��һ��С�ļ����й鲢
// ���n������ȡ���������ж��ٺ�����ڴ�������ã���Զ���nԽ�󣬸������ݵ��ڴ��������
// �����ļ��鲢������������Խ��һЩ��
void MergeSortFile(const char* file, int n)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		printf("���ļ�%sʧ��\n", file);
		exit(-1);
	}
	int i = 0;
	int x = 0;
	const char* file1 = "file1";
	const char* file2 = "file2";
	const char* mfile = "mfile";
	// �ָ��һ��һ�����ݣ��ڴ������д����С�ļ���
	int* a = (int*)malloc(sizeof(int) * n);
	if (a == NULL)
	{
		perror("malloc fail");
		return;
	}
	// �ֱ��ȡǰn�����������д��file1��file2�ļ�
	ReadNNumSortToFile(fout, a, n, file1);
	ReadNNumSortToFile(fout, a, n, file2);
	while (1)
	{
		// file1��file2�ļ��鲢��mfile�ļ���
		MergeFile(file1, file2, mfile);
		// ɾ��file1��file2
		if (remove(file1) != 0 || remove(file2) != 0)
		{
			perror("Error deleting file");
			return;
		}
		// ��mfile������Ϊfile1
		if (rename(mfile, file1) != 0)
		{
			perror("Error renaming file");
			return;
		}
		// ��ȡN�����ݵ�file2�������߹鲢
		// ���һ�����ݶ�û��������鲢������
		if (ReadNNumSortToFile(fout, a, n, file2) == 0)
		{
			break;
		}
	}
	printf("%s�ļ��ɹ�����%s\n", file, file1);
	fclose(fout);
	free(a);
}
