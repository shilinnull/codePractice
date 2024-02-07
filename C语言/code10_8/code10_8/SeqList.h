#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//��̬˳���
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;  //˳�������Ч�����ݸ���
	int capacity;  //˳���ǰ�Ŀռ��С
}SL;
//typedef struct SeqList SL;

//��˳�����г�ʼ��
void SLInit(SL* ps);
void SLDestroy(SL* ps);

//ͷ��/β�� ����/ɾ��
void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

void SLPrint(SL* ps);
bool SLIsEmpty(SL* ps);