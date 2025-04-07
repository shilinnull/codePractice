#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

// 堆的构建
void HeapInit(Heap* hp) {
	assert(hp);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}
void Swap(int* p1, int* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdJustUp(HPDataType* a,int child) {
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x) {
	assert(hp);
	if (hp->capacity == hp->size) {
		int newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL) {
			perror("realloc fail!\n");
			exit(-1);
		}
		hp->a = tmp;
		hp->capacity = newcapacity;
	}
	hp->a[hp->size++] = x;
	AdJustUp(hp->a, hp->size-1);
}
void AdJustDown(HPDataType* a,int parent,int n) {
	int child = parent * 2 + 1;
	while(child < n)
	{
		if (child + 1 < n && a[child] > a[child + 1]) {
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}
// 堆的删除
void HeapPop(Heap* hp) {
	assert(hp);
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdJustDown(hp->a,0,hp->size);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp) {
	assert(hp);
	if (HeapEmpty(hp)) 
		return -1;
	return hp->a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp) {
	assert(hp);
	return hp->size;
}
// 堆的判空
bool HeapEmpty(Heap* hp) {
	assert(hp);
	return hp->size == 0;
}
// 堆的销毁
void HeapDestory(Heap* hp) {
	assert(hp);
	if(hp->a) 
		free(hp->a);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}
