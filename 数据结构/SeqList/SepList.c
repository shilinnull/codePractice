#include"SepList.h"

//初始化顺序表
void SLInit(SL* ps)
{
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//销毁顺序表
void SLDestroy(SL* ps)
{
	if(ps->a)
		free(ps->a);
	ps->capacity = ps->size = 0;
}

//检查容量
void SLCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity) {
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//空间不够，需要扩容
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL) {
			perror("realloc fail!");
			return;
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}

//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//判断空间够不够？
	SLCheckCapacity(ps);
	//直接插入数据
	ps->a[ps->size++] = x;
}

//头插
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	//判断空间是否足够，不够则扩容
	SLCheckCapacity(ps);
	//空间足够，历史数据后移一位
	// 挪动数据
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}

//尾删
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(!SLIsEmpty(ps));
	ps->size--;
}

//头删
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(!SLIsEmpty(ps));
	//让后面的数据往前挪动一位
	for (size_t i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//打印顺序表
void SLPrint(SL* ps)
{
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//判断空间是否为空
bool SLIsEmpty(SL* ps)
{
	assert(ps);
	return ps->size == 0;
}


//在任意位置之前插入
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	//需要限制范围
	assert(pos >= 0 && pos <= ps->size);
	//检查容量
	SLCheckCapacity(ps);
	
	for (size_t i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}

//在任意位置之前删除
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(!SLIsEmpty(ps));
	//assert(ps->size > 0);//也可以这样写

	assert(pos >= 0 && pos <= ps->size);//限制pos

	for (size_t i = pos; i < ps->size-1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//查找顺序表
bool SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x) 
			return true;
	}
	return false;
}


