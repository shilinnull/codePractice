#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}

	
	printf("%d ", QueueBack(&q));
	printf("%d ", QueueSize(&q));

	QueueDestroy(&q);
	return 0;
}