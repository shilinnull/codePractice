#define _CRT_SECURE_NO_WARNINGS 1

#include"SepList.h"


void SLTest1()
{
	SL sl;
	SLInit(&sl);

	SLDestroy(&sl);
}

void SLTest2()
{
	SL sl;	
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	
	SLDestroy(&sl);
}


void SLTest3()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 6);
	SLPushFront(&sl, 7);

	SLDestroy(&sl);
}

void SLTest4()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 6);
	SLPushFront(&sl, 7);
	SLPrint(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);

	SLDestroy(&sl);
}


void SLTest5()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	//头删
	SLPrint(&sl); //1  2  3  4 
	SLPopFront(&sl); 
	SLPrint(&sl);// 2  3  4
	SLPopFront(&sl);
	SLPrint(&sl);// 3  4
	SLPopFront(&sl);
	SLPrint(&sl); // 4
	SLPopFront(&sl);
	SLPrint(&sl); //没有了

	SLPopFront(&sl);
	SLPrint(&sl);

	SLDestroy(&sl);
}

void SLTest6()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);

	SLPrint(&sl);//1  2  3  4

	SLInsert(&sl, 4, 11);
	SLPrint(&sl);//1 11  2  3  4

	SLDestroy(&sl);
}
void SLTest7()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);

	SLPrint(&sl);//1  2  3  4

	SLErase(&sl, 0);
	SLPrint(&sl);//1  3  4

	SLDestroy(&sl);
}

void SLTest8()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);

	bool findret = SLFind(&sl, 3);
	if (findret)
		printf("找到了\n");
	else
		printf("找不到\n");

	SLDestroy(&sl);
}

int main()
{
	SLTest8();

	return 0;
}

