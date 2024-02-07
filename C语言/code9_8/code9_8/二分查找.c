#define _CRT_SECURE_NO_WARNINGS 1

/*
编写代码在一个整形有序数组中查找具体的某个数

要求：找到了就打印数字所在的下标，找不到则输出：找不到。
*/

#include<stdio.h>

int Find(int arr[], int left, int right,int key)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;

}

int main()
{
	int k = 7;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = Find(arr, 0, sz - 1,k);

	if (ret != -1)
	{
		printf("找到了，下标是%d\n", ret);
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}