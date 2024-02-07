#define _CRT_SECURE_NO_WARNINGS 1

/*
写一个二分查找函数
功能：在一个升序数组中查找指定的数值，找到了就返回下标，找不到就返回-1.
int bin_search(int arr[], int left, int right, int key)
// arr 是查找的数组
//left 数组的左下标
//right 数组的右下标
//key 要查找的数字
*/
#include<stdio.h>
int bin_search(int arr[], int left, int right, int key)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] == key)
		{
			return mid + 1;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int key = 0;
	scanf("%d", &key);
	int ret = bin_search(arr,0,sz,key);
	if (ret != -1)
	{
		printf("找到了，是%d \n", ret);
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}
