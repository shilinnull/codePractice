typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
void QueueDestroy(Queue* pq)//����
{
	assert(pq);
	while (pq->head !=NULL)
	{
		QueueNode* tmp = pq->head;
		pq->head = pq->head->next;
		free(tmp);
	}
	pq->head = pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType x)//���
{
	assert(pq);
	QueueNode* NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	NewNode->data = x;
	NewNode->next = NULL;
	if (pq->head ==NULL)
		pq->head = pq->tail=NewNode;
	else
	{
		pq->tail->next = NewNode;
		pq->tail = NewNode;
	}
}
void QueuePop(Queue* pq)//ɾ��
{
	assert(pq);
	assert(pq->head);
	if (pq->head == pq->tail)
		pq->tail = NULL;
	QueueNode* tmp = pq->head->next;
	free(pq->head);
	pq->head = tmp;
	
}
QDataType QueueFront(Queue* pq)//ͷ��
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
QDataType QueueBack(Queue* pq)//β��
{
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}
int QueueSize(Queue* pq)//����
{
	assert(pq);
	int count = 0;
	QueueNode* tmp = pq->head;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return count;
}
bool QueueEmpty(Queue* pq)//�ж��Ƿ�Ϊ��
{
	if (QueueSize(pq) == 0)
		return true;
	else
		return false;
}
typedef struct {
    Queue q1;
    Queue q2;
} MyStack;


MyStack* myStackCreate() {
    MyStack *obj=(MyStack*)malloc(sizeof(MyStack));
    QueueInit(&obj->q1);
    QueueInit(&obj->q2);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    Queue*cur=&obj->q1;//ѡ���������ݵĶ���
    if(!QueueEmpty(&obj->q2))
        cur=&obj->q2;
    QueuePush(cur,x);
}

int myStackPop(MyStack* obj) {
    Queue*cur1=&obj->q1;//������
    Queue*cur2=&obj->q2;//������
    if(!QueueEmpty(&obj->q2))
    {
        cur1=&obj->q2;
        cur2=&obj->q1;
    }
    while(cur1->head!=cur1->tail)
    {
        QueuePush(cur2,QueueFront(cur1));
        QueuePop(cur1);
    }
    int top=QueueFront(cur1);
    QueuePop(cur1);
    return top;
}

int myStackTop(MyStack* obj) {
        Queue*cur=&obj->q1;
    if(!QueueEmpty(&obj->q2))
        cur=&obj->q2;
    return QueueBack(cur);
}

bool myStackEmpty(MyStack* obj) {
    return (QueueEmpty(&obj->q1)&&QueueEmpty(&obj->q2));
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}