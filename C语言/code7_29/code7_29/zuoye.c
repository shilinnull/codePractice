#define _CRT_SECURE_NO_WARNINGS 1

/*
�����ж�����

��ҵ����
ʵ��һ������is_prime���ж�һ�����ǲ���������
��������ʵ�ֵ�is_prime��������ӡ100��200֮���������

*/
//#include <stdio.h>
//
//
//void is_prime()
//{
//	int i = 0;
//	for (i = 100; i < 200; i++)
//	{
//		int j = 0;
//		for ( j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (i == j)
//		{
//			printf("%d\n", i);
//		}
//	}
//}
//
//int main()
//{
//	is_prime();
//	return 0;
//}
//


//ʵ�ֺ����ж�year�ǲ�������
//
//#include<stdio.h>
//int is_year(int n)
//{
//	if ((n % 4 == 0) && (n % 100 != 0) || (n % 400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int n = 0;
//
//	while (scanf("%d", &n) != EOF) 
//	{
//		if (is_year(n) == 1)
//		{
//			printf("������\n");
//		}
//		else
//		{
//			printf("��������\n");
//		}
//
//	}
//	return 0;
//}

/*
����һ���������飬��ɶ�����Ĳ���
ʵ�ֺ���init() ��ʼ������Ϊȫ0
ʵ��print()  ��ӡ�����ÿ��Ԫ��
ʵ��reverse()  �����������Ԫ�ص����á�
Ҫ���Լ�������Ϻ����Ĳ���������ֵ��

*/
//
//
//#include<stdio.h>
//
//void init(int arr[],int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void print(int arr[],int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void reverse(int arr[], int size)
//{
//	int left = 0;
//	int right = size - 1;
//	while (left < right)
//	{
//		int temp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = temp;
//		left++;
//		right--;
//	}
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//init(arr, sz);//��ʼ��
//	print(arr, sz);//����ǰ��
//	reverse(arr, sz);//������
//	return 0;
//}


/*
ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��

�磺����9�����9*9�ھ������12�����12*12�ĳ˷��ھ���

*/
//
//#include<stdio.h>
//
//void mu_table(n)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%-2d*%2d=%-4d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//
//
//}
//
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF) 
//	{
//		mu_table(n);
//	}
//	return 0;
//}


/*


int bin_search(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}


дһ�����ֲ��Һ���

���ܣ���һ�����������в���ָ������ֵ���ҵ��˾ͷ����±꣬�Ҳ����ͷ���-1.

int bin_search(int arr[], int left, int right, int key)
// arr �ǲ��ҵ�����
//left ��������±�
//right ��������±�
//key Ҫ���ҵ�����
*/


#include<stdio.h>


int bin_search(int arr[], int sz,int key)
{
    int left = 0;
    int right = sz-1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] < key)
        {
            left = arr[mid] + 1;
        }
        else
        {
            right = arr[mid] - 1;
        }
    }
    return -1;

}

int main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int n = 0;
    scanf("%d", &n);
    int ret = bin_search(arr, sz, n);
    if (ret != -1)
    {
        printf("�ҵ��ˣ��±���%d", ret);
    }
    else
    {
        printf("�Ҳ�����\n");
    }
    return 0;
}

