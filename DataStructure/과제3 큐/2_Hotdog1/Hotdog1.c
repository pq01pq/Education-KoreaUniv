#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

void main(void)
{
	Queue *row = createQueue();
	int customer, patience, hotdog;

	printf("Number of customer : ");
	scanf("%d", &customer);
	printf("\n");

	int i;
	for (i = 0; i < customer; i++)
	{
		printf("Patience of customer : ");
		scanf("%d", &patience);
		enqueue(row, patience);
	}
	printf("\n");

	hotdog = 0;
	i = 0;
	while (i < customer)
	{
		patience = (int) row->front->data - hotdog; // 핫도그를 판 횟수만큼 인내심 감소
		if (patience < 0)
		{
			printf("A C 안먹어 ㅡㅡ\n");
			dequeue(row);
		}
		else
		{
			printf("잘먹겠습니다 ㅎㅎ\n");
			dequeue(row);
			hotdog++;
		}

		i++;
	}
	printf("\n");

	printf("I sell %d hotdogs.\n", hotdog);

	destroyQueue(row);

	return;
}