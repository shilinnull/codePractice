#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>
#include<string.h>
//
////strlen��ģ��ʵ��
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


//ʹ��ָ���ӡ��������
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
//	//���ַ�����������ʱ����
//	strcpy(tmp, str1);
//	//���ַ���ƴ�ӵ���ʱ��������
//	strcat(tmp, str1);
//	//��tmp��Ѱ��str2�ַ���
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


