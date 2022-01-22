#pragma once
typedef void * element;

// Node
typedef struct tQueueNode {
	element data;
	struct tQueueNode *next;
} QueueNode;

// Front, Rear
typedef struct {
	int count;
	QueueNode *front, *rear;
} Queue;


 Queue *createQueue(void)
{
	Queue *pQueue = (Queue *)malloc(sizeof(Queue));
	if (pQueue == NULL)
		return NULL;

	pQueue->count = 0;
	pQueue->front = pQueue->rear = NULL;

	return pQueue;
}

 void enqueue(Queue *pQueue, element item)
 {
	QueueNode *pNewNode = (QueueNode *)malloc(sizeof(QueueNode));
	if (pNewNode == NULL)
		return;

	pNewNode->data = item;
	pNewNode->next = NULL;
	if (pQueue->count < 1) // ù ���
	{
		pQueue->front = pQueue->rear = pNewNode; // front�� rear ��� ù ����� �ּ� ���� 
	}
	else
	{
		pQueue->rear->next = pNewNode;
		pQueue->rear = pNewNode;
	}
	pQueue->count++;

	return;
 }

 element dequeue(Queue *pQueue)
 {
	if (pQueue->count == 0) {
		printf("The queue is empty\n");
		return NULL;
	}
	else {
		element item = pQueue->front->data;
		QueueNode *pOldNode = pQueue->front;
		pQueue->front = pOldNode->next;
		if (pQueue->count == 1) // ������ ���� ���
			pQueue->rear = pQueue->front; // free �ϱ����� rear���� NULL�ּ� ����
		free(pOldNode);
		pQueue->count--;

		return item;
	}
 }

 element queueFront(Queue *pQueue)
 {
	if (pQueue->count == 0) {
		printf("The queue is empty\n");
		return NULL;
	}
	else
		return pQueue->front->data;
 }

 int queueCount(Queue *pQueue)
 {
	return pQueue->count;
 }

 void destroyQueue(Queue *pQueue)
 {
	if (pQueue->rear != NULL) // ��尡 �Ѱ� �̻� ���� ��
	{
		while (pQueue->front->next != NULL) {
			QueueNode *pOldNode = pQueue->front;
			pQueue->front = pOldNode->next;
			free(pOldNode);
			pQueue->count--;
		}
		QueueNode *pOldNode = pQueue->front;
		pQueue->rear = pQueue->front = NULL;
		free(pOldNode);
		pQueue->count--;
	}
	free(pQueue);

	return;
 }