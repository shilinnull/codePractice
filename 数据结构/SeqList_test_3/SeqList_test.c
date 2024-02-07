#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

TEST1()
{
	SLNode seqsl;
	SLNodeInit(&seqsl);
	SLNodePushBack(&seqsl, 1);
	SLNodePushBack(&seqsl, 2);
	SLNodePushBack(&seqsl, 3);
	SLNodePushBack(&seqsl, 4);
	SLNodePrint(&seqsl);
}

TEST2()
{
	SLNode seqsl;
	SLNodeInit(&seqsl);
	SLNodePushBack(&seqsl, 1);
	SLNodePushBack(&seqsl, 2);
	SLNodePushBack(&seqsl, 3);
	SLNodePushBack(&seqsl, 4);
	SLNodePrint(&seqsl);

	SLNodeFrond(&seqsl, 10);
	SLNodeFrond(&seqsl, 20);
	SLNodeFrond(&seqsl, 30);
	SLNodePrint(&seqsl);

	SLNodePop(&seqsl);
	SLNodePrint(&seqsl);
	SLNodePop(&seqsl);
	SLNodePrint(&seqsl);
	SLNodePop(&seqsl);
	SLNodePrint(&seqsl);
	SLNodePop(&seqsl);
	SLNodePrint(&seqsl);

	SLNodePop(&seqsl);
	SLNodePrint(&seqsl);

	SLNodePop(&seqsl);
	SLNodePrint(&seqsl);
	SLNodePop(&seqsl);
	SLNodePrint(&seqsl);
	SLNodePop(&seqsl);
	SLNodePrint(&seqsl);

}

TEST3()
{
	SLNode seqsl;
	SLNodeInit(&seqsl);
	SLNodePushBack(&seqsl, 1);
	SLNodePushBack(&seqsl, 2);
	SLNodePushBack(&seqsl, 3);
	SLNodePushBack(&seqsl, 4);
	SLNodePrint(&seqsl);

	SLNodePopFrond(&seqsl);
	SLNodePrint(&seqsl);
	SLNodePopFrond(&seqsl);
	SLNodePrint(&seqsl);
	SLNodePopFrond(&seqsl);
	SLNodePrint(&seqsl);
	SLNodePopFrond(&seqsl);
	SLNodePrint(&seqsl);
	
	SLNodePopFrond(&seqsl);
	SLNodePrint(&seqsl);

}


TEST4()
{
	SLNode seqsl;
	SLNodeInit(&seqsl);
	SLNodePushBack(&seqsl, 1);
	SLNodePushBack(&seqsl, 2);
	SLNodePushBack(&seqsl, 3);
	SLNodePushBack(&seqsl, 4);
	SLNodePrint(&seqsl);

	//SLInsert(&seqsl, 3, 30);
	//SLNodePrint(&seqsl);
	//SLInsert(&seqsl, 3, 30);
	//SLNodePrint(&seqsl);
	SLErase(&seqsl,2);
	SLNodePrint(&seqsl);

}
int main()
{
	TEST4();
	return 0;
}