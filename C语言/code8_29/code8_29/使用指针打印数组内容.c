#define _CRT_SECURE_NO_WARNINGS 1

/*
дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣

arr��һ������һά���顣
*/

#include<stdio.h>
void print_arr(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", *(arr + i));
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, sz);
	return 0;
}

