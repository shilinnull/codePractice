#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

int main()
{
	Heap hp;
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	HeapInit(&hp);
	int sz = sizeof(a) / sizeof(a[0]);
	
	for (int i = 0; i < sz; i++)
	{
		HeapPush(&hp, a[i]);
	}

	//取前三个
	//int k = 3;
	//while (k--)
	//{
	//	printf("%d ", HeapTop(&hp));
	//	HeapPop(&hp);
	//}

	
	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}


	return 0;
}