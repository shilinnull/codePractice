#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

test1()
{
	SLNode* sl;
	
	//²âÊÔ´òÓ¡
	SLNode* node1 = (SLNode*)malloc(sizeof(SLNode));
	node1->val = 1;
	SLNode* node2 = (SLNode*)malloc(sizeof(SLNode));
	node2->val = 2;
	SLNode* node3 = (SLNode*)malloc(sizeof(SLNode));
	node3->val = 3;
	SLNode* node4 = (SLNode*)malloc(sizeof(SLNode));
	node4->val = 4;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	SLNode* plist = node1;
	SLTPrint(plist);
}
test2()
{
	SLNode* sl = NULL;
	SLTPushBack(&sl,1);
	SLTPushBack(&sl,2);
	SLTPushBack(&sl,3);
	SLTPushBack(&sl,4);
	SLTPrint(sl);

	SLTPushFront(&sl, 10);
	SLTPushFront(&sl, 20);
	SLTPushFront(&sl, 30);
	SLTPrint(sl);

	SLTPopBack(&sl);
	SLTPrint(sl);

	SLTPopFront(&sl);
	SLTPrint(sl);

}


test3()
{

	SLNode* sl = NULL;
	SLTPushBack(&sl, 1);
	SLTPushBack(&sl, 2);
	SLTPushBack(&sl, 3);
	SLTPushBack(&sl, 4);
	SLTPrint(sl);

	SLNode* find = SListFind(&sl, 2);
	//SLTInsert(&sl, find, 10);
	//SLTPrint(sl);
	//SLTErase(&sl, find);
	//SLTPrint(sl);


	//SLTInsertAfter(find, 300);
	//SLTPrint(sl);
	SLTEraseAfter(find);
	SLTPrint(sl);
	SListDesTroy(&sl);
}



test4()
{

	SLNode* sl = NULL;
	SLTPushBack(&sl, 1);
	SLTPushBack(&sl, 2);
	SLTPushBack(&sl, 3);
	SLTPushBack(&sl, 4);
	SLTPrint(sl);

	SLNode* find = SListFind(&sl, 2);
	SLTInsert(&sl, find, 10);
	SLTPrint(sl);

}

int main()
{
	test3();
	return 0;
}