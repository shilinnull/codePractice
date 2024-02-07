#define _CRT_SECURE_NO_WARNINGS 1

/*
��������ʹ����ȫ����λ��ż��ǰ�档
��Ŀ��
����һ���������飬ʵ��һ��������
�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
����ż��λ������ĺ�벿�֡�
*/

#include<stdio.h>
void func(int* arr, int left,int right)
{
	while (left < right)
	{
		//������������
		while (left < right && arr[left] % 2 != 0)
		{
			left++;
		}
		//��������ż��
		while (left < right && arr[right] % 2 == 0)
		{
			right--;
		}
		//����
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