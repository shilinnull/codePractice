#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

int main1()
{
	ST st;
	StackInit(&st);
	StackPush(&st,1);
	StackPush(&st,2);
	StackPush(&st,3);
	StackPush(&st,4);
	printf("%d ", StackTop(&st));
	StackPop(&st);

	StackPush(&st, 5);
	printf("%d ", StackTop(&st));
	StackPop(&st);


	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	return 0;
}
