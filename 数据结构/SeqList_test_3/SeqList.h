#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int SLDateType;

typedef struct ListNode
{
	SLDateType* a;
	int size;
	int capacity;
}SLNode;



void SLNodeInit(SLNode* ps);

void SLNodePushBack(SLNode* ps, SLDateType x);

void SLNodePrint(SLNode* ps);

void SLNodeFrond(SLNode* ps, SLDateType x);

void SLNodePop(SLNode* ps);

void SLNodePopFrond(SLNode* ps);

bool SLNodeIsEmpty(SLNode* ps);

void SLInsert(SLNode* ps, int pos, SLDateType x);

void SLErase(SLNode* ps, int pos);

bool SLFind(SLNode* ps, SLDateType x);
