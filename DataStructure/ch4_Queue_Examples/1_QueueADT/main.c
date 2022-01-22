#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

int main(void)
{
	QUEUE* Q1 = createQueue();

	int* dataPtr;
	dataPtr = (int*)malloc(sizeof(int));
	*dataPtr = 10;
	enqueue(Q1, (void*)dataPtr);

	dataPtr = (int*)malloc(sizeof(int));
	*dataPtr = 20;
	enqueue(Q1, (void*)dataPtr);

	dataPtr = (int*)malloc(sizeof(int));
	*dataPtr = 30;
	enqueue(Q1, (void*)dataPtr);

	int c1 = queueCount(Q1);
	printf("%d\n", c1);

	dequeue(Q1);

	int c2 = queueCount(Q1);
	printf("%d\n", c2);

	destroyQueue(Q1);

	return 0;
}
