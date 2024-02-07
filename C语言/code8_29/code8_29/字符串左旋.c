#define _CRT_SECURE_NO_WARNINGS 1
/*
实现一个函数，可以左旋字符串中的k个字符。
例如：
ABCD左旋一个字符得到BCDA

ABCD左旋两个字符得到CDAB
*/

#include<stdio.h>
#include<string.h>
//方法一：
/* 
void LeftRound(char* src, int k)
{
	int len = strlen(src);
	int count = k % len;
	//要移动的次数
	for (int i = 0; i < count; i++)
	{
		//将数组的第一个字符存储到临时tmp变量中
		char tmp = src[0];
		int j = 0;
		//将数组中的字符向进行覆盖前面
		for (j = 0; j < len - 1; j++)
		{
			src[j] = src[j + 1];
		}
		//最后将临时变量赋值给原数组中，完成移动
		src[j] = tmp;
	}
}
*/
//方法二：
/*

	char tmp[256] = { 0 };
	//将要左旋的字符拷贝到临时变量tmp中
	strcpy(tmp, src + count);
	//拼接到指定位置tmp,从src开始拼接3个
	strncat(tmp, src, k);
	//将tmp的字符拷贝到src
	strcpy(src, tmp);
}
*/
//方法三：
#include<assert.h>
//逆序字符串
void Reverse(char* str, int right, int left)
{
	assert(str != NULL);
	while (left < right)
	{
		char tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		right++;
		left--;
	}
}

void LeftRound(char* src, int k)
{
	int len = strlen(src);
	int count = k % len;
	//调用逆序字符串,从0到逆序的几个字符-1进行逆序
	Reverse(src, 0, k - 1);
	//调用逆序字符串,从k到总长度-1进行逆序
	Reverse(src, k, len - 1);
	//调用逆序字符串,从0到总长度-1进行逆序
	Reverse(src, 0, len - 1);
}
int main()
{
	char arr[] = "abcd";
	int n = 0;
	printf("请输入要逆序几次:>");
	scanf("%d", &n);
	//调用函数进行实现
	LeftRound(arr, n);
	printf("%s", arr);
	return 0;
}