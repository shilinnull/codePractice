#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"


int main1()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	//while (!StackEmpty(&st))
	//{
	//	int i = StackTop(&st);
	//	printf("%d ", i);
	//	StackPop(&st);
	//}
	printf("\n");
	printf("%d",StackSize(&st));
	StackDestroy(&st);
	return 0;
}