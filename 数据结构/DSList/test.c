#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"


test1()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
}


//test2()
//{
//	ListNode* plist = ListInit();
//	ListPushBack(plist, 1);
//	ListPushBack(plist, 2);
//	ListPushBack(plist, 3);
//	ListPushBack(plist, 4);
//	ListPrint(plist);
//
//	ListPopBack(plist);
//	ListPrint(plist);
//
//	ListPopBack(plist);
//	ListPrint(plist);
//
//}


test3()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListPushFront(plist,10);
	ListPrint(plist);

	ListPushFront(plist,20);
	ListPrint(plist);

}
test4()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListPopFront(plist);
	ListPrint(plist);

	ListPopFront(plist);
	ListPrint(plist);

}

test5()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListNode* find = ListFind(plist,2);
	if (find)
	{
		find->_val *= 10;
		printf("找到了,并修改\n");
		ListPrint(plist);
	}
	else
	{
		printf("找不到\n");
	}
	ListInsert(find, 300);
	ListPrint(plist);
	ListNode* find1 = ListFind(plist, 300);

	ListErase(find1);
	ListPrint(plist);	
	ListDestory(plist);

}

int main()
{
	test3();
	return 0;
}