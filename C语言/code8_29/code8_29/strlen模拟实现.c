#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>
size_t my_strlen(const char* str)
{
	assert(str != NULL);//断言
	int count = 0;//计数器
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return count;
}


int main()
{
	char arr[] = "abcdef";
	size_t len = my_strlen(arr);
	printf("字符串长度是%d\n", len);
	return 0;
}