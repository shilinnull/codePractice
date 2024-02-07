#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int QDataType;

//��ʼ������
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType val;
}QNode;

//���еĽṹ

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	QDataType size;
}Queue;

//���еĳ�ʼ��
void QueueInit(Queue* pq);

//��β�����
void QueuePush(Queue* pq, QDataType x);
//��ͷ������
void QueuePop(Queue* pq);