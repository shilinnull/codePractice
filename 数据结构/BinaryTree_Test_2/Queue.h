#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef struct BinaryTreeNode* QDataType;
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;
// ��ʼ������
void QueueInit(Queue* pq);
// ���ٶ���
void QueueDestroy(Queue* pq);
// ��β�����
void QueuePush(Queue* pq, QDataType x);
// ��ͷ������
void QueuePop(Queue* pq);
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pq);
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* pq);
// �������Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);
//��ȡ����Ԫ�ظ���
int QueueSize(Queue* pq);