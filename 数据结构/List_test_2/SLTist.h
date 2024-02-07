#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);
// �������ӡ
void SListPrint(SListNode* pphead);
// ������β��
void SListPushBack(SListNode** pphead, SLTDateType x);
// �������ͷ��
void SListPushFront(SListNode** pphead, SLTDateType x);
// �������βɾ
void SListPopBack(SListNode** pphead);
// ������ͷɾ
void SListPopFront(SListNode** pphead);
// ���������
SListNode* SListFind(SListNode* pphead, SLTDateType x);
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode** pphead, SListNode* pos, SLTDateType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);

// ��pos��ǰ�����
void SLTInsert(SListNode** pphead, SListNode* pos, SLTDateType x);
// ɾ��posλ��
void SLTErase(SListNode** pphead, SListNode* pos);
void SLTDestroy(SListNode** pphead);

