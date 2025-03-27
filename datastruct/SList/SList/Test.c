#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

int main() {
	SLTNode* list = NULL;
	SLTPushBack(&list, 1);
	SLTPushBack(&list, 2);
	SLTPushBack(&list, 3);
	SLTPushBack(&list, 4);
	//SLTPrint(list);
	//SLTPushFront(&list, 10);
	//SLTPrint(list);
	//SLTPopBack(&list);
	//SLTPrint(list);
	//SLTPopFront(&list);
	//SLTPrint(list);
	//SLTNode* find = SLTFind(list, 1);
	//if (find) {
	//	printf("找到了\n");
	//}
	//else {
	//	printf("没找到\n");
	//}
	//SLTNode* find = SLTFind(list,1);
	//SLTInsert(&list, find, 30);
	//SLTInsert(&list, find, 40);
	//SLTPrint(list);
	SLTPrint(list);
	SLTNode* find = SLTFind(list, 3);

	// SLTInsertAfter(find, 10);
	//SLTErase(&list, find);
	SLTEraseAfter(find);
	SLTPrint(list);
	SListDestroy(&list);
	SLTPrint(list);

	return 0;
}