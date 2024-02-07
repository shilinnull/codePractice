#include"Sort.h"


// 测试排序的性能对比
void TestOP()
{
	srand((unsigned int)time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand() + i;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	PartSort1(a5, 0, N - 1);
	//_PartSort1(a5, 0, N - 1);
	//QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	int begin7 = clock();
	BubbleSort(a7, N);
	int end7 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	printf("BubbleSort:%d\n", end7 - begin7);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}

void TestInsertSort()
{
	int a[] = { 3,2,6,8,4,6,0,9,5,7,1 };
	int sz = sizeof(a) / sizeof(a[0]);

	printf("插入排序：");
	InsertSort(a, sz);
	Print_a(a, sz);
}

void TestBubbleSort()
{
	int a[] = { 3,2,6,8,4,6,0,9,5,7,1 };
	int sz = sizeof(a) / sizeof(a[0]);

	printf("冒泡排序：");
	BubbleSort(a, sz);
	Print_a(a, sz);
}

void TestShellSort()
{
	int a[] = { 3,2,6,8,4,6,0,9,5,7,1 };
	int sz = sizeof(a) / sizeof(a[0]);

	printf("希尔排序：");
	ShellSort(a, sz);
	Print_a(a, sz);
}


void TestHeapSort()
{
	int a[] = { 3,2,6,8,4,6,0,9,5,7,1 };
	int sz = sizeof(a) / sizeof(a[0]);

	printf("堆排序：  ");
	HeapSort(a, sz);
	Print_a(a, sz);
}

void TestSelectSort()
{
	int a[] = { 13,-1,3,2,6,8,4,6,0,9,5,7,1 };
	int sz = sizeof(a) / sizeof(a[0]);

	printf("选择排序：  ");
	SelectSort(a, sz);
	Print_a(a, sz);
}

void TestQuickSort()
{
	int a[] = { 13,-1,3,2,6,8,4,6,0,9,5,7,1 };
	int sz = sizeof(a) / sizeof(a[0]);

	printf("快速排序：");
	QuickSort(a, 0, sz - 1);
	Print_a(a, sz);
}

void TestQuickSortNonR()
{
	int a[] = { 13,-1,3,2,6,8,4,6,0,9,5,7,1 };
	int sz = sizeof(a) / sizeof(a[0]);

	printf("快速排序 非递归实现排序 ：");
	QuickSortNonR(a, 0, sz - 1);
	Print_a(a, sz);
}

void TestMergeSort()
{
	int a[] = { 13,-1,3,2,6,8,4,6,0,9,5,7,1 };
	int sz = sizeof(a) / sizeof(a[0]);

	printf("归并排序 ：");
	MergeSort(a, sz);
	Print_a(a, sz);
}

void TestMergeSortNonR()
{
	int a[] = { 13,-1,3,2,6,8,4,6,0,9,5,7,1 };
	int sz = sizeof(a) / sizeof(a[0]);

	printf("归并排序非递归实现 ：");
	MergeSortNonR(a, sz);
	Print_a(a, sz);
}

void TestCountSort()
{
	int a[] = { 13,-1,3,2,6,8,4,6,0,9,5,7,1 };
	int sz = sizeof(a) / sizeof(a[0]);

	printf("非比较排序 ：");
	CountSort(a, sz);
	Print_a(a, sz);
}




int main()
{
	//TestInsertSort();
	//TestBubbleSort();
	//TestShellSort();
	//TestHeapSort();
	//TestSelectSort();
	//TestQuickSort();
	//TestQuickSortNonR();
	//TestMergeSort();
	TestMergeSortNonR();
	//TestCountSort();

	//TestOP();
	return 0;
}

// 排序数组

//void Swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//int GetMidIndex(int* a, int left, int right)
//{
//	// 随机取数
//	int mid = left + (rand() % (right - left));
//
//	if (a[left] < a[mid])
//	{
//		if (a[mid] < a[right])
//			return mid;
//		else if (a[left] < a[right])
//			return right;
//		else
//			return left;
//	}
//	else // a[left] > a[mid]
//	{
//		if (a[mid] > a[right])
//			return mid;
//		else if (a[left] > a[right])
//			return right;
//		else
//			return left;
//	}
//}
//
//void QuickSort(int* a, int begin, int end)
//{
//	if (begin >= end)
//		return;
//
//	int left = begin, right = end;
//	int cur = left + 1;
//
//	int midi = GetMidIndex(a, left, right);
//	Swap(&a[left], &a[midi]);
//	int key = a[left];
//
//	// 把小的甩到左边，把大的甩到右边,中间[left,right]就是相等的
//	while (cur <= right)
//	{
//		if (a[cur] < key)
//		{
//			Swap(&a[cur], &a[left]);
//			++cur;
//			++left;
//		}
//		else if (a[cur] > key)
//		{
//			Swap(&a[cur], &a[right]);
//			--right;
//		}
//		else
//		{
//			++cur;
//		}
//	}
//
//	// [begin,left-1] [left,right] [right+1,end]
//	QuickSort(a, begin, left - 1);
//	QuickSort(a, right + 1, end);
//}
//
//
//int* sortArray(int* nums, int numsSize, int* returnSize) {
//	if (nums == NULL || returnSize == NULL || numsSize < 0) {
//		// 处理无效输入
//		return NULL;
//	}
//	srand((unsigned int)time(0));
//
//	QuickSort(nums, 0, numsSize - 1);
//	*returnSize = numsSize;
//
//	return nums;
//}