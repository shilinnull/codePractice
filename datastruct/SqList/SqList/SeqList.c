#include "SepList.h"

void SLInit(SL* ps) {
	assert(ps); // assert为真通过，为假报错
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}
void SLDestory(SL* ps) {
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

void SLPrint(SL* ps) {
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}


void SLCheckCapacity(SL* ps) {
	assert(ps);
	if (ps->capacity == ps->size) {
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newcapacity * sizeof(SLDataType));
		if (!tmp) {
			perror("realloc fail!\n");
			exit(-1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
}

void SLPushBack(SL* ps, SLDataType x) {
	assert(ps);
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}

void SLPopBack(SL* ps) {
	assert(ps && ps->size > 0);
	ps->size--;
}

void SLPushFront(SL* ps, SLDataType x) {
	assert(ps);
	SLCheckCapacity(ps);
	// 挪动数据
	for (size_t i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	// 插入数据
	ps->arr[0] = x;
	ps->size++;
}

void SLPopFront(SL* ps) {
	assert(ps && ps->size > 0);
	// 直接挪动数据
	for (size_t i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

void SLInsert(SL* ps, int pos, SLDataType x) {
	assert(ps && pos <= ps->size && pos >= 0);
	for (size_t i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}

void SLErase(SL* ps, int pos) {
	assert(ps && pos >= 0 && pos < ps->size);
	// 直接挪动元素
	for (size_t i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
bool SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
			return true;
	}
	return false;
}


