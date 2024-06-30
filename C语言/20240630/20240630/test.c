#include <stdio.h>
#include <stddef.h>
// 大小为12
struct S
{
	char c1;
	int i;
	char c2;
};

#define OFFSETOF(type,mem) (size_t)&(((type*)0)->mem)

int main()
{
	printf("c1为%d\n", OFFSETOF(struct S, c1));
	printf("i为%d\n", OFFSETOF(struct S, i));
	printf("c2为%d\n", OFFSETOF(struct S, c2));
	//printf("c1为%d\n", offsetof(struct S, c1));
	//printf("i为%d\n", offsetof(struct S, i));
	//printf("c2为%d\n", offsetof(struct S, c2));

	printf("S结构体大小为%d\n", sizeof(struct S));

	return 0;
}