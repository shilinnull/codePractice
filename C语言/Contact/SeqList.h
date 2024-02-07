#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
#include"Contact.h"

//����������
//�������͸ĳ�ͨѶ¼������
typedef struct ContactInfo SLDataType;

//typedef struct CInfo SLDataType;
//typedef CInfo SLDataType;

//�ṹ��Ķ���
typedef struct SeqList
{
	SLDataType* a;
	int size;//��¼���ٸ���Ч����
	int capacity;//�ռ�����
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
//bool SLFind(SL* ps, SLDataType x);
