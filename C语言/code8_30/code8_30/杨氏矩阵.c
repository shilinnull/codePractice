#define _CRT_SECURE_NO_WARNINGS 1

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
		else if (arr[i][j] > key)
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
	int arr[][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int ret = FindNum(arr, 3, 3, 4);
	printf("%d\n", ret);
	return 0;
}


