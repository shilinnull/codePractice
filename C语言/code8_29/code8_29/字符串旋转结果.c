#define _CRT_SECURE_NO_WARNINGS 1

/*
дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
���磺����s1 =AABCD��s2 = BCDAA������1
����s1=abcd��s2=ACBD������0.
AABCD����һ���ַ��õ�ABCDA
AABCD���������ַ��õ�BCDAA
AABCD����һ���ַ��õ�DAABC
*/

#include<stdio.h>
#include<string.h>
//ʹ�ÿⷽ��ʵ��
int find(char* str1, char* str2)
{
	char tmp[256] = { 0 };
	//���ַ�����������ʱ����
	strcpy(tmp, str1);
	//���ַ���ƴ�ӵ���ʱ��������
	strcat(tmp, str1);
	//��tmp��Ѱ��str2�ַ���
	return strstr(tmp, str2) != NULL;
}

int main()
{
	char arr[] = "AABCD";
	int ret = find(arr, "BCDAA");
	printf("%d", ret);
	return 0;
}

