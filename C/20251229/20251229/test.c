#include <stdio.h>


int QuickSort(int* arr, int begin, int end) {
	int privot = arr[begin];
	int holei = begin;
	while (begin < end) {
		while (begin < end && arr[end] >= privot)  end--;
		arr[holei] = arr[end];
		holei = end;
		while (begin < end && arr[begin] <= privot) begin++;
		arr[holei] = arr[begin];
		holei = begin;
	}
	arr[holei] = privot;
	return holei;
}


void Sort(int* arr, int begin, int end) {
	if(begin >= end) {
		return;
	}

	int pivot = QuickSort(arr, begin, end);
	Sort(arr, begin, pivot - 1);
	Sort(arr, pivot + 1, end);
}


#include <string.h>
int tmp[10000];

void mergeSort(int *a, int begin, int end)
{
	if (begin >= end) return;

	int mid = (begin + end) >> 1;
	mergeSort(a, begin, mid);
	mergeSort(a, mid + 1, end);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;

	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] < a[begin2]) tmp[i++] = a[begin1++];
		else tmp[i++] = a[begin2++];
	}
	while (begin1 <= end1) tmp[i++] = a[begin1++];
	while (begin2 <= end2) tmp[i++] = a[begin2++];

	for (int i = begin; i <= end; i++) {
		a[i] = tmp[i];
	}
}

int main()
{
	int arr[] = { 3, 5, 1, 4, 2 };
	//Sort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	mergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
