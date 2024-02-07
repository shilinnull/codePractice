#define _CRT_SECURE_NO_WARNINGS 1

/*
写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 =AABCD和s2 = BCDAA，返回1
给定s1=abcd和s2=ACBD，返回0.
AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA
AABCD右旋一个字符得到DAABC
*/

#include<stdio.h>
#include<string.h>
//使用库方法实现
int find(char* str1, char* str2)
{
	char tmp[256] = { 0 };
	//将字符串拷贝到临时变量
	strcpy(tmp, str1);
	//将字符串拼接到临时变量后面
	strcat(tmp, str1);
	//在tmp里寻找str2字符串
	return strstr(tmp, str2) != NULL;
}

int main()
{
	char arr[] = "AABCD";
	int ret = find(arr, "BCDAA");
	printf("%d", ret);
	return 0;
}

