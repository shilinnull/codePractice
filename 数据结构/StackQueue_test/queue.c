
#include"queue.h"
// 初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
// 队尾入队列
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail\n");
		return;
	}
	newnode->val = x;
	newnode->next = NULL;
	if (pq->ptail == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}
// 队头出队列
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
// 获取队列头部元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}
// 获取队列队尾元素
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return pq->ptail->val;
}
// 获取队列中有效元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == 0;
}
// 销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = NULL;
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}