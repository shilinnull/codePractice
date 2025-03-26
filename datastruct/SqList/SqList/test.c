#define _CRT_SECURE_NO_WARNINGS 1

#include "SepList.h"


int main() {
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);/*
	SLPrint(&s1);
	SLPushFront(&s1,10);
	SLPrint(&s1);
	SLPushFront(&s1,20);
	SLPrint(&s1);
	SLPopFront(&s1);
	SLPopFront(&s1);
	SLPopFront(&s1);
	SLPrint(&s1);*/

	SLInsert(&s1, 1, 10);
	SLPrint(&s1);
	SLErase(&s1, 3);
	SLPrint(&s1);


	SLDestory(&s1);
	return 0;
}