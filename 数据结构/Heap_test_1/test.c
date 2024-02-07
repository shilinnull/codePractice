#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"


int main()
{
	Heap hp;
	HeapCreate(&hp);

	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	
	for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		HeapPush(&hp, arr[i]);
	}

	//int top = 3;
	//while (top--)
	//{
	//	printf("%d ", HeapTop(&hp));
	//	HeapPop(&hp);
	//}

	int size = HeapSize(&hp);
	printf("%d", size);

	HeapDestory(&hp);

	return 0;
}