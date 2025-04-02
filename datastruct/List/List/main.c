#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"


int main() {

	ListNode* list = ListInit();
	ListPushBack(list,1);
	ListPushBack(list,2);
	ListPushBack(list,3);
	ListPushBack(list,4);
	ListPopBack(list);
	ListPushFront(list, 10);
	ListPushFront(list, 20);
	ListPushFront(list, 30);
	ListPopFront(list);
	ListNode* find = ListFind(list, 2);
	//if (find != NULL)
	//	printf("找到了%d\n", find->_val);
	//else
	//	printf("没有找到\n");

	//ListInsert(find, 50);
	ListErase(find);



	ListPrint(list);
	ListDestory(list);
	list = NULL;
	return 0;
}