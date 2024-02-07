
#include"queue.h"
// ��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
// ��β�����
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
// ��ͷ������
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
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return pq->ptail->val;
}
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == 0;
}
// ���ٶ���
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