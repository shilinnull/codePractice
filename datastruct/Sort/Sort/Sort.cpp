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
		if (a[begin1] <= a[begin2])
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
	int* tmp = (int*)malloc(sizeof(int) * n);

	int gap = 1;
	while (gap < n)
	{
		//int j = 0;
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// 修正区间
			//if (begin2 >= n)
			//	break;
			if (end1 >= n || begin2 >= n)
				break;

			if (end2 >= n)
				end2 = n - 1;

			// 尾插到tmp
			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
					tmp[j++] = a[begin1++];
				else
					tmp[j++] = a[begin2++];
			}

			// 到这里把剩下的全部尾插
			while (begin1 <= end1)
				tmp[j++] = a[begin1++];
			while (begin2 <= end2)
				tmp[j++] = a[begin2++];
			
			// 拷贝回a数组
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

	// 统计
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	
	// 放回原数组
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

// 三路划分函数
KeyWayIndex PartSort3Way(int* a, int left, int right) {
	int key = a[left];

	// left和right指向就是跟key相等的区间
	// [开始, left-1][left, right][right+1, 结束]

	int cur = left + 1;
	while (cur <= right) {
		// 1、cur遇到比key小，小的换到左边，同时把key换到中间位置
		// 2、cur遇到比key大，大的换到右边

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

// 创建N个随机数，写到文件中
void CreateNDate()
{
	// 造数据
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

// file1文件的数据和file2文件的数据归并到mfile文件中
void MergeFile(const char* file1, const char* file2, const char* mfile)
{
	FILE* fout1 = fopen(file1, "r");
	if (fout1 == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	FILE* fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	FILE* fin = fopen(mfile, "w");
	if (fin == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	// 这里跟内存中数组归并的思想完全类似，只是数据在硬盘文件中而已
	// 依次读取file1和file2的数据，谁的数据小，谁就往mfile文件中去写
	// file1和file2其中一个文件结束后，再把另一个文件未结束文件数据，
	// 依次写到mfile的后面
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

// 返回读取到的数据个数
int ReadNNumSortToFile(FILE* fout, int* a, int n, const char* file)
{
	int x = 0;
	// 读取n个数据放到file
	int i = 0;
	while (i < n && fscanf(fout, "%d", &x) != EOF)
	{
		a[i++] = x;
	}
	// 一个数据都没有读到，则说明文件已经读到结尾了
	if (i == 0)
		return i;
	// 排序
	HeapSort(a, i);
	FILE* fin = fopen(file, "w");
	if (fout == NULL)
	{
		printf("打开文件%s失败\n", file);
		exit(-1);
	}
	for (int j = 0; j < i; j++)
	{
		fprintf(fin, "%d\n", a[j]);
	}
	fclose(fin);
	return i;
}

// MergeSortFile的第二个是每次取多少个数据到内存中排序，然后写到一个小文件进行归并
// 这个n给多少取决于我们有多少合理的内存可以利用，相对而言n越大，更多数据到内存中排序后，
// 再走文件归并排序，整体程序会越快一些。
void MergeSortFile(const char* file, int n)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		printf("打开文件%s失败\n", file);
		exit(-1);
	}
	int i = 0;
	int x = 0;
	const char* file1 = "file1";
	const char* file2 = "file2";
	const char* mfile = "mfile";
	// 分割成一段一段数据，内存排序后写到，小文件，
	int* a = (int*)malloc(sizeof(int) * n);
	if (a == NULL)
	{
		perror("malloc fail");
		return;
	}
	// 分别读取前n个数据排序后，写到file1和file2文件
	ReadNNumSortToFile(fout, a, n, file1);
	ReadNNumSortToFile(fout, a, n, file2);
	while (1)
	{
		// file1和file2文件归并到mfile文件中
		MergeFile(file1, file2, mfile);
		// 删除file1和file2
		if (remove(file1) != 0 || remove(file2) != 0)
		{
			perror("Error deleting file");
			return;
		}
		// 将mfile重命名为file1
		if (rename(mfile, file1) != 0)
		{
			perror("Error renaming file");
			return;
		}
		// 读取N个数据到file2，继续走归并
		// 如果一个数据都没读到，则归并结束了
		if (ReadNNumSortToFile(fout, a, n, file2) == 0)
		{
			break;
		}
	}
	printf("%s文件成功排序到%s\n", file, file1);
	fclose(fout);
	free(a);
}
