#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
void bubble_sort(int arr[],int sz)
{
	int i = 0;
	//ȷ��ð�����������
	for (i = 0; i < sz - 1; i++)
	{
		//���������������
		int flag = 1;
		//һ��ð�ݽ��ж��ٶԱȽ�
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//����
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		// ��һ��û������˵���Ѿ����򣬺�������������
		if (flag == 1) 
		{
			break;
		}
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
	bubble_sort(arr, sz);
	print_arr(arr, sz);
}