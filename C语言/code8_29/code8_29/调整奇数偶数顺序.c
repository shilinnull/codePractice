#define _CRT_SECURE_NO_WARNINGS 1

/*
调整数组使奇数全部都位于偶数前面。
题目：
输入一个整数数组，实现一个函数，
来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
所有偶数位于数组的后半部分。
*/

#include<stdio.h>
void func(int* arr, int left,int right)
{
	while (left < right)
	{
		//遇到的是奇数
		while (left < right && arr[left] % 2 != 0)
		{
			left++;
		}
		//遇到的是偶数
		while (left < right && arr[right] % 2 == 0)
		{
			right--;
		}
		//交换
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
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
	func(arr, 0, sz - 1);
	print_arr(arr, sz);
	return 0;
}