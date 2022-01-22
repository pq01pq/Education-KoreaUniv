#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queueADT.h"

QUEUE* createQueue(void)
{
	QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));

	if (queue == NULL) return NULL;

	queue->front = NULL;
	queue->rear = NULL;
	queue->count = 0;

	return queue;
}

void destroyQueue(QUEUE* queue)
{
	QUEUE_NODE* delPtr;

	if (queue)
	{
		while (queue->front != NULL)
		{
			free(queue->front->dataPtr);
			delPtr = queue->front;
			queue->front = queue->front->next;
			free(delPtr);
		}
		free(queue);
	}
}

bool enqueue(QUEUE* queue, void* dataPtr)
{
	QUEUE_NODE* nextPtr = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));

	if (nextPtr == NULL)
		return false;

	nextPtr->dataPtr = dataPtr;
	nextPtr->next = NULL;

	if (queue->count <= 0)
		queue->front = nextPtr;
	else
		queue->rear->next = nextPtr;

	(queue->count)++;
	queue->rear = nextPtr;

	return true;
}

bool dequeue(QUEUE* queue)
{
	QUEUE_NODE* delPtr = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));

	if (!queue->count)
		return false;

	delPtr = queue->front;

	if (queue->count == 1)
		queue->rear = NULL;
	else
		queue->front = queue->front->next;

	(queue->count)--;
	free(delPtr->dataPtr);
	free(delPtr);

	return true;
}

bool queueFront(QUEUE* queue, void** dataPtr)
{
	if (!queue->count)
		return false;

	*dataPtr = queue->front->dataPtr;
	return true;
}

bool queueRear(QUEUE* queue, void** dataPtr)
{
	if (!queue->count)
		return true;

	*dataPtr = queue->rear->dataPtr;
	return false;
}


int queueCount(QUEUE* queue)
{
	return queue->count;
}

bool isEmpty(QUEUE* queue)
{
	return (queue->count == 0);
}
