#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//
//void menu()
//{
//	printf("\n");
//	printf("***********************\n");
//	printf("****1.add******2.sub***\n");
//	printf("****3.mul******4.div***\n");
//	printf("****0.exit*************\n");
//	printf("***********************\n");
//}
//
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//
//int main()
//{
//	int y = 0;
//	int x = 0;
//	int input = 0;
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		int (*pfArr[])(int, int) = { NULL,Add,Sub,Mul,Div };
//		if (input == 0)
//		{
//			printf("退出计算器！\n");
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("选择两个操作数！\n");
//			scanf("%d %d", &x, &y);
//			int ret = pfArr[input](x, y);
//			printf("%d", ret);
//		}
//		else
//		{
//			printf("选择错误，请重新选择!\n");
//		}
//
//	}while (input);
//	return 0;
////}
//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5 };
//    short* p = (short*)arr;
//    int i = 0;
//    for (i = 0; i < 4; i++)
//    {
//        *(p + i) = 0;
//    }
//
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//int main()
//{
//	unsigned long pulArray[] = { 6,7,8,9,10 };
//	unsigned long* pulPtr;
//	pulPtr = pulArray;
//	*(pulPtr + 3) += 3;
//	printf("%d,%d\n", *pulPtr, *(pulPtr + 3));
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//    int a = 0x11223344;//0x 00 33 22 11
//    char* pc = (char*)&a;
//    *pc = 0;
//    printf("%x\n", a);
//    return 0;
//}
//
//void print_arr(int* p, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print_arr(arr, sz);
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//void revers(int arr[], int left, int right)
//{
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right++;
//	}
//}
//
//int main()
//{
//	int  arr[1000] = { 0 };
//	while (gets(arr))
//	{
//		int len = strlen(arr);
//		revers(arr, 0, len - 1);
//		printf("%s", arr);
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int* p ;
//	printf("%p", p);
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//    int a = 0x11223344;
//    char* pc = (char*)&a;
//    *pc = 0;
//    printf("%#x\n", a);
//    return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//    int line = 0;
//    while (scanf("%d", &line) != EOF)
//    {
//
//        int i = 0;
//        for (i = 0; i < line; i++)
//        {
//            //打印
//            int j = 0;
//            for (j = 0; j < line - 1 - i; j++)
//            {
//                printf(" ");
//            }
//            for (j = 0; j < 2 * i + 1; j++)
//            {
//                printf("*");
//            }
//            printf("\n");
//        }
//
//
//        for (i = 0; i < line - 1; i++)
//        {
//            //打印
//            int j = 0;
//            for (j = 0; j <= i; j++)
//            {
//                printf(" ");
//            }
//            j = 0;
//            for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
//            {
//                printf("*");
//            }
//            printf("\n");
//        }
//    }
//
//    return 0;
//}
//
//
//
//

/*
求出0～100000之间的所有“水仙花数”并输出。

“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，
如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数”。
*/
//
//#include<math.h>
//int main()
//{
//	for (int i = 0; i <= 100000; i++)
//	{
//		int n = 1;
//		int tmp = i;
//		while (tmp /= 10)
//		{
//			n++;
//		}
//		tmp = i;
//		int sum = 0;
//		while (tmp)
//		{
//			sum+=pow(tmp % 10, n);
//			tmp /= 10;
//		}
//		if (tmp == i)
//		{
//			printf("%d ", i);
//		}
//		
//	}
//
//
//	return 0;
//}

//
//int main()
//{
//
//	int n = 0;
//	int a = 0;
//	scanf("%d %d", &a, &n);
//	int i = 0;
//	int sum = 0;
//	int k = 0;
//	for (i = 0; i < n; i++)
//	{
//		k = k * 10 + a;
//		sum += k;
//	}
//	printf("%d", sum);
//	return 0;
//}
//#include < stdio.h >
//struct S
//{
//	int a; 
//	int b;
//};
//int main()
//{
//	struct S a, * p = &a;
//	a.a = 99;
//	printf("%d\n", __________);
//	return 0;
//}
//
//struct stu
//{
//	int num;
//	char name[10];
//	int age;
//};
//
//void fun(struct stu* p)
//{
//	printf("%s\n", (*p).name);
//	return;
//}
//
//int main()
//{
//	struct stu students[3] = { {9801,"zhang",20},
//							 {9802,"wang",19},
//					{9803,"zhao",18} };
//	fun(students + 1);
//	return 0;
//}


//
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 999999; i++)
//	{
//		int count = 1;
//		int tmp = i;
//		int sum = 0;
//		while (tmp / 10)
//		{
//			count++;
//			tmp = tmp / 10;
//		}
//
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, count);
//			tmp = tmp / 10;
//		}
//		if (sum == i)
//			printf("%d ", i);
//	}
//	return 0;
//}
//
//#include<stdio.h>
////喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水（编程实现）。
//int main()
//{
//	size_t bottle = 20;
//	size_t money = 0;
//	while (scanf("%d", &money) != EOF)
//	{
//		if (money > 0)
//		{
//			size_t empty_bottle = money;
//			while (empty_bottle >= 2)
//			{
//				bottle += empty_bottle / 2;
//				empty_bottle = empty_bottle / 2 + empty_bottle % 2;
//			}
//			printf("%u\n", bottle);
//		}
//		else
//		{
//			printf("%u\n", money);
//		}
//	}
//	return 0;
//}

//
//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}
//
//#include<stdio.h>
//
//void swap_arr(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		while ((left < right) && (arr[left] % 2 == 1)) //奇数
//		{
//			left++;
//		}
//		while ((left < right) && (arr[left] % 2 == 0)) //偶数
//		{
//			right--;
//		}
//		if (left < right)//交换
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//			left++;
//			right--;
//		}
//	}
//
//
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	swap_arr(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}
// 
// 
//模拟实现库函数strcpy
//#include<stdio.h>
//
//char* my_strcpy(char* dest, const char* src)
//{
//	char* cp = dest;
//	while (*cp++ = *src++);
//	return(dest);
//}
//
//int main()
//{
//	char arr1[10] = "abcdef";
//	char arr2[10] = { 0 };
//	my_strcpy(arr2, arr1);
//	printf("%s", arr2);
//
//	return 0;
//}

//模拟实现库函数strlen
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//
//size_t my_strlen(const char* src)
//{
//	assert(src != NULL);
//	const char* p = src;
//	while (*p++);
//	return (p-src-1);
//}
//int main()
//{
//	char arr[] = "abcdef";
//	size_t len = my_strlen(arr);
//	printf("%d", len);
//	return 0;
//}

//int main()
//{
//	unsigned char a = 200;//
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d %d", a + b, c);
//	return 0;
//}
//
//int main()
//{
//    char a[1000] = { 0 };
//    int i = 0;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}

//int main()
//{
//	int killer = 0;
//	for ((killer != 'a'); (killer <= 'd'); killer++)
//	{
//		if ((('a' != killer) + (killer == 'c') + (killer == 'd') + (killer != 'd')) == 3)
//		{
//			printf("%c",killer);
//		}
//	}
//	return 0;
//}

















