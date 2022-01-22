#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

void main(void)
{
	Queue *row = createQueue();
	int customer, patience1, patience2, hotdog, sell;

	printf("Number of customer : ");
	scanf("%d", &customer);
	printf("\n");

	int i;
	for (i = 0; i < customer; i++)
	{
		printf("Patience of customer : ");
		scanf("%d", &patience1);
		enqueue(row, patience1);
	}
	printf("\n");

	hotdog = 0;
	sell = 0;
	i = 0;
	while (i < customer)
	{
		if (row->count > 1) // 맨앞에 두명을 고려할 수 있을 때
		{
			patience1 = (int)row->front->data - sell; // 맨앞 두사람중 앞사람의 남은 인내심
			patience2 = (int)row->front->next->data - sell; // 맨앞 두사람중 뒷사람의 남은 인내심

			if (patience1 < 0) // 앞사람이 배고픔을 참지 못했을 때
			{
				printf("A C 안먹어 ㅡㅡ\n");
				dequeue(row);
				i++;
				if (patience2 < 0) // 뒷사람도 배고픔을 참지 못했을 때
				{
					printf("A C 안먹어 ㅡㅡ\n");
					dequeue(row);
					i++;
				} // 뒷사람은 아직 배고픔을 참을만 할 때 차례를 뒤로 넘김
			}
			else // 앞사람이 아직 배고픔을 참을만 할 때
			{
				if (patience2 < 0) // 뒷사람은 배고픔을 참지 못했을 때
				{
					printf("잘먹겠습니다 ㅎㅎ\n");
					dequeue(row);
					i++;
					hotdog++;

					do {
						printf("A C 안먹어 ㅡㅡ\n");
						dequeue(row);
						i++;

						if (row->front != NULL)
							patience2 = (int)row->front->data - sell;
					}
					while (patience2 < 0 && row->count > 0); // 뒷쪽에서 아직 배고픔을 참고 있는 사람을 찾음

					if (row->count > 0) // 배고픔을 참고 있는 사람을 찾았을 때
					{
						printf("잘먹겠습니다 ㅎㅎ\n");
						dequeue(row);
						i++;
						hotdog++;
					} // 모두 배고픔을 참지 못하고 떠났으면 앞사람에게만 판매

					sell++;
				}
				else // 뒷사람도 아직 배고픔을 참을만 할 때
				{
					printf("잘먹겠습니다 ㅎㅎ\n");
					dequeue(row);
					i++;
					hotdog++;

					printf("잘먹겠습니다 ㅎㅎ\n");
					dequeue(row);
					i++;
					hotdog++;

					sell++;
				}
			}
		}
		else if (row->count == 1) // 한명만 남았을 때
		{
			patience1 = (int)row->front->data - sell;
			if (patience1 < 0)
			{
				printf("A C 안먹어 ㅡㅡ\n");
				dequeue(row);
				i++;
			}
			else
			{
				printf("잘먹겠습니다 ㅎㅎ\n");
				dequeue(row);
				i++;
				hotdog++;

				sell++;
			}
		}
	}
	printf("\n");

	printf("I sell %d hotdogs.\n", hotdog);

	destroyQueue(row);

	return;
}