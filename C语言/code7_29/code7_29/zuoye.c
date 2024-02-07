#define _CRT_SECURE_NO_WARNINGS 1

/*
函数判断素数

作业内容
实现一个函数is_prime，判断一个数是不是素数。
利用上面实现的is_prime函数，打印100到200之间的素数。

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


//实现函数判断year是不是润年
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
//			printf("是闰年\n");
//		}
//		else
//		{
//			printf("不是闰年\n");
//		}
//
//	}
//	return 0;
//}

/*
创建一个整形数组，完成对数组的操作
实现函数init() 初始化数组为全0
实现print()  打印数组的每个元素
实现reverse()  函数完成数组元素的逆置。
要求：自己设计以上函数的参数，返回值。

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
//	//init(arr, sz);//初始化
//	print(arr, sz);//逆序前的
//	reverse(arr, sz);//逆序后的
//	return 0;
//}


/*
实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定

如：输入9，输出9*9口诀表，输出12，输出12*12的乘法口诀表。

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


写一个二分查找函数

功能：在一个升序数组中查找指定的数值，找到了就返回下标，找不到就返回-1.

int bin_search(int arr[], int left, int right, int key)
// arr 是查找的数组
//left 数组的左下标
//right 数组的右下标
//key 要查找的数字
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
        printf("找到了，下标是%d", ret);
    }
    else
    {
        printf("找不到！\n");
    }
    return 0;
}

