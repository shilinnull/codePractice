#define _CRT_SECURE_NO_WARNINGS 1


#include"SepList.h"


sltest1()
{
	//初始化和尾插测试
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 1);

	SLPrint(&sl);
}

sltest2()
{
	//初始化和尾插测试
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 1);
	
	SLPushFront(&sl, 20);

	SLPrint(&sl);
}
sltest3()
{
	//初始化和头删测试
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 1);
	SLPrint(&sl);

	SLPopFront(&sl);

	SLPrint(&sl);
}
sltest4()
{
	//在任意位置之前插入
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 1);
	SLPrint(&sl);

	SLInsert(&sl,2,30);

	SLPrint(&sl);
}


sltest5()
{
	//在任意位置之前删除
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 1);
	SLPrint(&sl);

	SLErase(&sl, 3);

	SLPrint(&sl);
}
sltest6()
{
	//在任意位置之前删除
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 1);
	SLPrint(&sl);

	if (SLFind(&sl, 5))
		printf("找到了");
	else
		printf("找不到");


}


int main()
{
	sltest4();
	return 0;
}




