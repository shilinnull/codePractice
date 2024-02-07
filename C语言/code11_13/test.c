#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


int main()
{
	int a = 10;
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof a);
	printf("%d\n", sizeof int);

	return 0;
}