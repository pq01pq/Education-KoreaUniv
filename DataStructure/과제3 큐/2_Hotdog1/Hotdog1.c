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
		patience = (int) row->front->data - hotdog; // �ֵ��׸� �� Ƚ����ŭ �γ��� ����
		if (patience < 0)
		{
			printf("A C �ȸԾ� �Ѥ�\n");
			dequeue(row);
		}
		else
		{
			printf("�߸԰ڽ��ϴ� ����\n");
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