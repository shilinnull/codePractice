#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int SLNDataType;

typedef struct SListNode
{
	SLNDataType val;
	struct SListNode* next;
}SLNode;

//��ӡ
void SLTPrint(SLNode* phead);

//β��
void SLTPushBack(SLNode** pphead, SLNDataType x);

//ͷ��
void SLTPushFront(SLNode** pphead, SLNDataType x);

//βɾ
void SLTPopBack(SLNode** pphead);

//ͷɾ
void SLTPopFront(SLNode** pphead);

//����
SLNode* SListFind(SLNode** phead, SLNDataType x);

//��ָ��λ��֮ǰ��������
void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x);

//ɾ��pos�ڵ�
void SLTErase(SLNode** pphead, SLNode* pos);

//��ָ��λ��֮���������
void SLTInsertAfter(SLNode* pos, SLNDataType x);

//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLNode* pos);

//��������
void SListDesTroy(SLNode** pphead);