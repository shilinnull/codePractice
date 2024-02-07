#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

//队列的初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
//队尾入队列
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail!\n");
		return;
	}
	
	newnode->val = x;
	newnode->next = NULL;
	
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	
}