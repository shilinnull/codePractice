#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main() {
//
//	int a = 10;
//	int* pa = &a;
//	int** ppa = &pa;
//
//
//
//	return 0;
//}

//int main() {
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	int d = 4;
//	int e = 5;
//	int* parr[5] = { &a,&b,&c,&d,&e };
//
//	int i = 0;
//	for (i = 0; i < 5; i++) {
//		printf("%d ", *(parr[i]));
//	}
//	return 0;
//}

#include <stdio.h>
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };
	//数组名是数组首元素的地址，类型是int*的，就可以存放在parr数组中
	int* parr[3] = { arr1, arr2, arr3 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", parr[i][j]);
		}
		printf("\n");
	}
	return 0;
}