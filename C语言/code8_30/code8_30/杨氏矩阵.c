#define _CRT_SECURE_NO_WARNINGS 1

//���Ͼ���
/*
��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ�
���д�����������ľ����в���ĳ�������Ƿ���ڡ�
Ҫ��ʱ�临�Ӷ�С��O(N);

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


