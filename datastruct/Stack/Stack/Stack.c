#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"


// 初始化栈
void StackInit(ST* ps) {
	assert(ps);

	ps->capacity = NULL;
	ps->capacity = ps->top = 0;
}
// 入栈
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
// 出栈
void StackPop(ST* ps) {
	assert(ps);
	--ps->top;
}
// 获取栈顶元素
STDataType StackTop(ST* ps) {
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}
// 获取栈中有效元素个数
int StackSize(ST* ps) {
	assert(ps);
	assert(ps->top > 0);

	return ps->top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
bool StackEmpty(ST* ps) {
	assert(ps);
	return ps->top == 0;
}
// 销毁栈
void StackDestroy(ST* ps) {
	assert(ps);
	free(ps->a);
	ps->capacity = ps->top = 0;
}
