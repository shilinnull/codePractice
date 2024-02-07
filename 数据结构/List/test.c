#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

int main()
{
	LTNode* sl = LTInit();
	LTPushBack(sl, 1);
	LTPushBack(sl, 2);
	LTPushBack(sl, 3);
	LTPushBack(sl, 4);
	LTPrint(sl);

	//LTPushFront(sl, 10);
	//LTPushFront(sl, 20);
	//LTPushFront(sl, 30);
	//LTPrint(sl);

	//LTNode* find = LTFind(sl, 3);
	//LTInsert(find, 20);
	//LTPrint(sl);


	LTNode* find = LTFind(sl, 3);
	LTErase(find);
	LTPrint(sl);

	return 0;
}