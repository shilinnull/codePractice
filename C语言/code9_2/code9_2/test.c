#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>
#include<string.h>
//
////strlen的模拟实现
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	int count = 0;
//	while (*str != '\0')
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int ret = my_strlen(arr);
//	printf("%d", ret);
//	return 0;
//}


//使用指针打印数组内容
//
//void print_arr(int* arr,int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print_arr(arr,sz);
//	return 0;
//}
//
//int find(char* str1, char* str2)
//{
//	char tmp[256] = { 0 };
//	//将字符串拷贝到临时变量
//	strcpy(tmp, str1);
//	//将字符串拼接到临时变量后面
//	strcat(tmp, str1);
//	//在tmp里寻找str2字符串
//	return strstr(tmp, str2) != NULL;
//}
//
//int main()
//{
//	char arr[] = "AABCD";
//	int ret = find(arr, "BCDAA");
//	printf("%d", ret);
//	return 0;
//}


