#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
void bubble_sort(int arr[],int sz)
{
	int i = 0;
	//确定冒泡排序的趟数
	for (i = 0; i < sz - 1; i++)
	{
		//假设数组是有序的
		int flag = 1;
		//一趟冒泡进行多少对比较
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//交换
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		// 这一趟没交换就说明已经有序，后续无序排序了
		if (flag == 1) 
		{
			break;
		}
	}
}

void print_arr(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	print_arr(arr, sz);
}