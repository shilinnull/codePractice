#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}

	newnode->val = x;
	newnode->next = NULL;

	if (pq->ptail == NULL)
	{
		pq->ptail = pq->phead = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}

	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	
	assert(pq->phead);

	QNode* del = pq->phead;
	pq->phead = pq->phead->next;
	free(del);
	del = NULL;

	if (pq->phead == NULL)
		pq->ptail = NULL;

	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	
	assert(pq->phead);

	return pq->phead->val;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	
	assert(pq->ptail);

	return pq->ptail->val;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->phead == NULL;
}

int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}