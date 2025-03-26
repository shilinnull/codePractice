#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int SLDataType;

typedef struct Seqlist {
	SLDataType* arr;
	int size;
	int capacity;
}SL;

// ��ʼ��������
void SLInit(SL* ps);
void SLDestory(SL* ps);

// ��ӡ
void SLPrint(SL* ps);


// �������
void SLCheckCapacity(SL* ps);
// β��
void SLPushBack(SL* ps,SLDataType x);
// βɾ
void SLPopBack(SL* ps);
// ͷ��
void SLPushFront(SL* ps,SLDataType x);
// ͷɾ
void SLPopFront(SL* ps);
// ָ��λ�ò�������
void SLInsert(SL* ps, int pos, SLDataType x);

// ָ��λ��ɾ������
void SLErase(SL* ps, int pos);

// ����
bool SLFind(SL* ps, SLDataType x);

