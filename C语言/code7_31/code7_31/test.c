#define _CRT_SECURE_NO_WARNINGS 1

/*
дһ�����ֲ��Һ���
���ܣ���һ�����������в���ָ������ֵ���ҵ��˾ͷ����±꣬�Ҳ����ͷ���-1.
int bin_search(int arr[], int left, int right, int key)
// arr �ǲ��ҵ�����
//left ��������±�
//right ��������±�
//key Ҫ���ҵ�����
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
		printf("�ҵ��ˣ���%d \n", ret);
	}
	else
	{
		printf("�Ҳ���\n");
	}
	return 0;
}
