#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

void main(void)
{
	Queue *q1;
	int c1, c2;
	void *d1, *d2;

	q1 = createQueue();

	enqueue(q1, 10);
	printf("rear : %d\n", (int)q1->rear->data);
	enqueue(q1, 20);
	printf("rear : %d\n", (int)q1->rear->data);
	enqueue(q1, 30);
	printf("rear : %d\n", (int)q1->rear->data);
	
	c1 = queueCount(q1);
	printf("count : %d\n", c1);
	printf("\n");

	d1 = dequeue(q1);
	printf("data : %d\n", (int)d1);
	d2 = queueFront(q1);
	printf("front : %d\n", (int)d2);
	c2 = queueCount(q1);
	printf("count : %d\n", c2);
	printf("\n");

	d1 = dequeue(q1);
	printf("data : %d\n", (int)d1);
	d2 = queueFront(q1);
	printf("front : %d\n", (int)d2);
	c2 = queueCount(q1);
	printf("count : %d\n", c2);
	printf("\n");

	d1 = dequeue(q1);
	printf("data : %d\n", (int)d1);
	d2 = queueFront(q1);
	printf("front : %d\n", (int)d2);
	c2 = queueCount(q1);
	printf("count : %d\n", c2);
	printf("\n");

	destroyQueue(q1);

	return;
}