#include"SeqList.h"

void SLInit(SL* ps) {
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SLDestroy(SL* ps) {
	if (ps->a)
		free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SLCheckCapacity(SL* ps) {
	if (ps->size == ps->capacity) {
		//空间不足以再额外插入一个数据
		//扩容
		int newCapcity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapcity * sizeof(SLDataType));
		if (tmp == NULL) {
			perror("realloc fail!\n");
			return 1;
		}
		ps->a = tmp;
		ps->capacity = newCapcity;
	}
}

//尾插
void SLPushBack(SL* ps, SLDataType x) {
	//assert(ps != NULL);
	//暴力的方式
	assert(ps);
	//柔和方式
	//if (ps == NULL) {
	//	return;
	//}

	//1)空间足够，直接尾插
	//2）空间不够，扩容
	SLCheckCapacity(ps);
	//直接插入数据
	ps->a[ps->size++] = x;
}
//头插
void SLPushFront(SL* ps, SLDataType x) {
	assert(ps);
	//判断空间是否足够,不够则扩容
	SLCheckCapacity(ps);
	//空间足够，历史数据后移一位
	for (size_t i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}
//尾插
void SLPopBack(SL* ps) {
	//判断顺序表是否为空
	assert(ps);
	assert(!SLIsEmpty(ps));
	//ps->a[ps->size - 1] = 0;
	ps->size--;
}
void SLPopFront(SL* ps) {
	assert(ps);
	assert(!SLIsEmpty(ps));
	//让后面的数据往左移动一位
	for (size_t i = 0; i < ps->size - 1; i++)
	{
		//最后一次进来的i的值为ps->size-1
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void SLPrint(SL* ps) {
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
bool SLIsEmpty(SL* ps) {
	assert(ps);
	//这样子是不对的，这里只能判断空间是否足够
	//return ps->size == ps->capacity;
	return ps->size == 0;
}