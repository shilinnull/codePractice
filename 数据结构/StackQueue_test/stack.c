#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		STDataType newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail!\n");
			return;
		}
		ps->capacity = newcapacity;
		ps->a = tmp;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

// ��ջ
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
// ��ȡջ��Ԫ��
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];

}
// ��ȡջ����ЧԪ�ظ���
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
// ����ջ
void StackDestroy(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}