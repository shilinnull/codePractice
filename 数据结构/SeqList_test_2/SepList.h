#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;


//��ʼ��˳���
void SLInit(SL* ps);

//����˳���
void SLDestroy(SL* ps);

//β��
void SLPushBack(SL* ps, SLDataType x);

//ͷ��
void SLPushFront(SL* ps, SLDataType x);

//βɾ
void SLPopBack(SL* ps);

//ͷɾ
void SLPopFront(SL* ps);

//��ӡ˳���
void SLPrint(SL* ps);

//�ж��Ƿ�Ϊ��
bool SLIsEmpty(SL* ps);

//������λ��֮ǰ����
void SLInsert(SL* ps, int pos, SLDataType x);

//������λ��֮ǰɾ��
void SLErase(SL* ps, int pos);

//����˳���
bool SLFind(SL* ps, SLDataType x);



