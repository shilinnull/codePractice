#define _CRT_SECURE_NO_WARNINGS 1

#include"SLTist.h"




test1()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

}



test2()
{
	SListNode* plist = NULL;
	//SListPushBack(&plist, 1);
	//SListPushBack(&plist, 2);
	//SListPushBack(&plist, 3);
	//SListPushBack(&plist, 4);
	//SListPushBack(&plist, 5);
	SListPrint(plist);

	SListPushFront(&plist, 20);
	SListPushFront(&plist, 30);
	SListPrint(plist);

}

test3()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

}


test4()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);

}

test5()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	SListNode* pos = SListFind(plist,1);

	SListInsertAfter(&plist,pos,20);
	SListPrint(plist);

}



int main() 
{
	test5();
	return 0;
}


