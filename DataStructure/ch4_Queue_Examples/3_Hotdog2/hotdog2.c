#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int hotdogsSold(QUEUE* queue)
{
	int hotdogs = 0;
	int time = 0;
	int count = 0;
	int* patience = NULL;
	while (!isEmpty(queue))
	{
		queueFront(queue, (void**)&patience);
		if (*patience >= time)
		{
			hotdogs++;
			if (count == 1)
			{
				time++;
				count = 0;
			}
			else
			{
				count++;
			}
		}
		dequeue(queue);
	}
	return hotdogs;
}

int main()
{
	int numCustomers;
	QUEUE* hotdogline = createQueue();

	printf("Number of customers : ");
	scanf_s("%d", &numCustomers);
	for (int i = 0; i < numCustomers; i++)
	{
		int* patience = (int*)malloc(sizeof(int));

		printf("Patience of customer %d (1~9): ", i + 1);
		scanf_s("%d", patience);
		enqueue(hotdogline, patience);
	}

	int hotdog = hotdogsSold(hotdogline);
	printf("I sold %d hotdogs\n", hotdog);

	return 0;
}