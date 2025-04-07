#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

int main() {
	Heap hp;
	HeapInit(&hp);
	HeapPush(&hp, 1);
	HeapPush(&hp, 2);
	HeapPush(&hp, 3);
	HeapPush(&hp, 4);
	HeapPop(&hp);
	HeapPop(&hp);

	HeapDestory(&hp);
	return 0;
}