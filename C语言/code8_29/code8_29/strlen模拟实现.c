#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>
size_t my_strlen(const char* str)
{
	assert(str != NULL);//����
	int count = 0;//������
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
	printf("�ַ���������%d\n", len);
	return 0;
}