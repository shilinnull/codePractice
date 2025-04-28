#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

int main() {
	int a[] = { 5, 3, 9, 1 ,6, 2, 4, 7, 8 };
	//int a[] = { 8,8,7,1,8};
	size_t n = sizeof(a) / sizeof(a[0]);
	

	//////////////////////////
	//BubbleSort(a, n);
	//InsertSort(a, n);
	//ShellSort(a, n);
	//SelectSort(a, n);
	//HeapSort(a, n);
	//QuickSort(a, 0, n - 1);
	//QuickSortNonR(a, 0, n - 1);
	MergeSort(a, n);
	/////////////////////////
	Print_a(a, n);

	return 0;
}
