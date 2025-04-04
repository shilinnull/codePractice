#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"


// ��ʼ��ջ
void StackInit(ST* ps) {
	assert(ps);

	ps->capacity = NULL;
	ps->capacity = ps->top = 0;
}
// ��ջ
void StackPush(ST* ps, STDataType x) {
	assert(ps);
	if (ps->capacity == ps->top) {
		STDataType newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)malloc(sizeof(STDataType) * newcapacity);
		if (tmp == NULL) {
			perror("malloc fail!\n");
			exit(-1);
		}

		ps->a[ps->top++] = x;
		ps->top++;
	}
}
// ��ջ
void StackPop(ST* ps) {
	assert(ps);
	--ps->top;
}
// ��ȡջ��Ԫ��
STDataType StackTop(ST* ps) {
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}
// ��ȡջ����ЧԪ�ظ���
int StackSize(ST* ps) {
	assert(ps);
	assert(ps->top > 0);

	return ps->top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
bool StackEmpty(ST* ps) {
	assert(ps);
	return ps->top == 0;
}
// ����ջ
void StackDestroy(ST* ps) {
	assert(ps);
	free(ps->a);
	ps->capacity = ps->top = 0;
}
