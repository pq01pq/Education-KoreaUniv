#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QUEUE
{
	void** nodes; // void* *nodes
	int front;
	int rear;
	int count;
	int queueSize;
} QUEUE;

QUEUE* createQueue(int queueSize)
{
	QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));

	if (queue == NULL) return NULL;

	queue->front = 0;
	queue->rear = -1;
	queue->count = 0;
	queue->queueSize = queueSize;
	queue->nodes = (void**)malloc(sizeof(void*) * queueSize);

	return queue;
}

void destroyQueue(QUEUE* queue)
{
	char* del;
	while (queue->front != queue->queueSize - 1)
	{
		del = queue->nodes[queue->front++];
		free(del);
		queue->queueSize--;
	}
	free(queue);
}

bool enqueue(QUEUE* queue, void* dataPtr)
{
	if (queue->count < queue->queueSize) {
		char* s = (char *)dataPtr;

		strcpy(queue->nodes[queue->rear], s);
		queue->rear++;

		queue->count++;
		return true;
	}
	else return false;
}

bool dequeue(QUEUE* queue)
{
	if (queue->count > 0)
	{
		free(queue->nodes[queue->front++]);
		queue->count--;
		return true;
	}
	else return false;
}

bool isFull(QUEUE* queue)
{
	return (queue->count == queue->queueSize);
}

bool queueFront(QUEUE* queue, void** dataPtr)
{
	if (isEmpty(queue))
	{
		dataPtr = NULL;
		return false;
	}

	*dataPtr = queue->nodes[queue->front];
	return true;
}

bool queueRear(QUEUE* queue, void** dataPtr)
{
	if (isEmpty(queue))
	{
		dataPtr = NULL;
		return false;
	}

	*dataPtr = queue->nodes[queue->rear];
	return true;
}

int queueCount(QUEUE* queue)
{
	return queue->count;
}

bool isEmpty(QUEUE* queue)
{
	if (queue->count == 0)
		return true;
	else return false;
}

int getNextIndex(QUEUE* queue, int cur)
{
	return ++cur % queue->queueSize;
}

int getPrevIndex(QUEUE* queue, int cur)
{
	return (--cur + queue->queueSize) % queue->queueSize;
}

void printQueueStatus(QUEUE* queue)
{
	char* str = NULL;
	printf("##############################\n# Queue Status\n");
	printf("- Queue size: %d\n", queue->queueSize);
	printf("- Num of elements: %d\n", queue->count);
	if (queueFront(queue, (void**)&str))
	{
		printf("- Queue front(%d): %s\n", queue->front, str);
	}
	if (queueRear(queue, (void**)&str))
	{
		printf("- Queue rear(%d): %s\n", queue->rear, str);
	}
	printf("\n");
}