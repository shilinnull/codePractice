#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int LTDataType;

typedef struct ListNode {
	LTDataType val;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//��ʼ���ڱ�λ
LTNode* LTInit();
//�����ڵ�
LTNode* LTcreate(LTDataType x);
//����
void LTDestroy(LTNode* phead);
//��ӡ
void LTPrint(LTNode* phead);
//�ж��Ƿ�Ϊ��
bool LTEmpty(LTNode* phead);
//β��
void LTPushBack(LTNode* phead, LTDataType x);
//βɾ
void LTPopBack(LTNode* phead);
//ͷ��
void LTPushFront(LTNode* phead, LTDataType x);
//ͷɾ
void LTPopFront(LTNode* phead);
//ָ��λ�ò���
void LTInsert(LTNode* pos, LTDataType x);
//ָ��λ��ɾ��
LTNode* LTErase(LTNode* pos);
//����
LTNode* LTFind(LTNode* phead, LTDataType x);
