#define _CRT_SECURE_NO_WARNINGS 1

/*
��д������һ���������������в��Ҿ����ĳ����

Ҫ���ҵ��˾ʹ�ӡ�������ڵ��±꣬�Ҳ�����������Ҳ�����
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
		printf("�ҵ��ˣ��±���%d\n", ret);
	}
	else
	{
		printf("�Ҳ���\n");
	}
	return 0;
}