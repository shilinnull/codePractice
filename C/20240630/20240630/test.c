#include <stdio.h>
#include <stddef.h>
// ��СΪ12
struct S
{
	char c1;
	int i;
	char c2;
};

#define OFFSETOF(type,mem) (size_t)&(((type*)0)->mem)

int main()
{
	printf("c1Ϊ%d\n", OFFSETOF(struct S, c1));
	printf("iΪ%d\n", OFFSETOF(struct S, i));
	printf("c2Ϊ%d\n", OFFSETOF(struct S, c2));
	//printf("c1Ϊ%d\n", offsetof(struct S, c1));
	//printf("iΪ%d\n", offsetof(struct S, i));
	//printf("c2Ϊ%d\n", offsetof(struct S, c2));

	printf("S�ṹ���СΪ%d\n", sizeof(struct S));

	return 0;
}