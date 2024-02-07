#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int QDataType;

//初始化队列
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType val;
}QNode;

//队列的结构

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	QDataType size;
}Queue;

//队列的初始化
void QueueInit(Queue* pq);

//队尾入队列
void QueuePush(Queue* pq, QDataType x);
//队头出队列
void QueuePop(Queue* pq);