#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"


int main()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(&sl);

	//SLPushFront(&sl, 20);
	//SLPrint(&sl);

	//SLPopBack(&sl);
	//SLPrint(&sl);
	//SLPopBack(&sl);
	//SLPrint(&sl);
	//SLPopBack(&sl);
	//SLPrint(&sl);
	//SLPopBack(&sl);
	//SLPrint(&sl);
	//SLPopFront(&sl);
	//SLPrint(&sl);
	//SLPopFront(&sl);
	//SLPrint(&sl);
	//SLPopFront(&sl);
	//SLPrint(&sl);
	//SLPopFront(&sl);
	//SLPrint(&sl);

	//SLInsert(&sl, 2, 20);
	//SLPrint(&sl);
	//SLInsert(&sl, 4, 20);
	//SLPrint(&sl);
	//SLInsert(&sl, 1, 20);
	//SLPrint(&sl);


	//SLErase(&sl, 2);
	//SLPrint(&sl);
	//SLErase(&sl, 2);
	//SLPrint(&sl);
	//SLErase(&sl, 2);
	//SLPrint(&sl);
	//SLErase(&sl, 2);
	//SLPrint(&sl);
	//SLErase(&sl, 2);
	//SLPrint(&sl);



	return 0;
}