#include"Sort.h"


int main()
{
	int a[] = { -1,4,2,8,5,6,6,6,6,10,4,10,7,3,0,1,9 };
	int sz = sizeof(a) / sizeof(a[0]);

	//SelectSort(a, sz);
	//HeapSort(a, sz);

	//BubbleSort(a,sz);

	//QuickSort(a, 0, sz - 1);
	//QuickSortNonR(a, 0, sz - 1);

	//MergeSort(a, sz);
	MergeSortNonR(a, sz);
	
	//CountSort(a, sz);


	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}