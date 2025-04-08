#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

int main() {
	Heap hp;
	HeapInit(&hp);
	HeapPush(&hp, 6);
	HeapPush(&hp, 10);
	HeapPush(&hp, 2);
	HeapPush(&hp, 8);
	HeapPush(&hp, 4);
	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}

	HeapDestory(&hp);
	return 0;
}