#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <windows.h>
//int main()
//{
//	for (int i = 0; i < 10; i++) {
//		printf("i=%d\n", i);
//		if (1)
//		{
//			auto int j = 0; //自动变量
//			printf("before: j=%d\n", j);
//			j += 1;
//			printf("after : j=%d\n", j);
//		}
//	}
//	system("pause");
//	return 0;
//}

//
//#include <stdio.h>
//#include <windows.h>
//int main()
//{
//	register int a = 0;
//	printf("&a = %p\n", &a);
//	//编译器报错：错误 1 error C2103: 寄存器变量上的“&”
//	//注意，这里不是所有的编译器都报错，目前我们的vs2013是报错的。
//	system("pause");
//	return 0;
//}

//
//#include<stdio.h>
//int main()
//{
//
//	int i = -20;
//	unsigned int j = 10;
//	printf("%u\n", i + j);
//
//	return 0;
//}
//杨氏矩阵

//杨氏矩阵
/*
有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
请编写程序在这样的矩阵中查找某个数字是否存在。
要求：时间复杂度小于O(N);

*/
#include<stdio.h>
int FindNum(int arr[][3], int x, int y, int key)
{
	int i = 0;
	int j = y - 1;
	while (j >= 0 && i < x)
	{
		if (arr[i][j] < key)
		{
			i++;
		}
		else if(arr[i][j] > key)
		{
			j--;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[][3] = { {1,2,3},{2,3,4},{3,4,5} };
	int ret = FindNum(arr, 3, 3, 4);
	printf("%d", ret);
	return 0;
}
