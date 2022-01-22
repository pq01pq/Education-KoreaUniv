#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	void* dataPtr;
	struct node* next;
} QUEUE_NODE;

typedef struct QUEUE
{
	QUEUE_NODE* front;
	QUEUE_NODE* rear;
	int count;
} QUEUE;

QUEUE* createQueue();
void destroyQueue(QUEUE* queue);

bool dequeue(QUEUE* queue);
bool enqueue(QUEUE* queue, void* dataPtr);
bool queueFront(QUEUE* queue, void** dataPtr);
bool queueRear(QUEUE* queue, void** dataPtr);
int queueCount(QUEUE* queue);

bool isEmpty(QUEUE* queue);

