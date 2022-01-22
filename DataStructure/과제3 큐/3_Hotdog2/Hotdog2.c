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
		if (row->count > 1) // �Ǿտ� �θ��� ����� �� ���� ��
		{
			patience1 = (int)row->front->data - sell; // �Ǿ� �λ���� �ջ���� ���� �γ���
			patience2 = (int)row->front->next->data - sell; // �Ǿ� �λ���� �޻���� ���� �γ���

			if (patience1 < 0) // �ջ���� ������� ���� ������ ��
			{
				printf("A C �ȸԾ� �Ѥ�\n");
				dequeue(row);
				i++;
				if (patience2 < 0) // �޻���� ������� ���� ������ ��
				{
					printf("A C �ȸԾ� �Ѥ�\n");
					dequeue(row);
					i++;
				} // �޻���� ���� ������� ������ �� �� ���ʸ� �ڷ� �ѱ�
			}
			else // �ջ���� ���� ������� ������ �� ��
			{
				if (patience2 < 0) // �޻���� ������� ���� ������ ��
				{
					printf("�߸԰ڽ��ϴ� ����\n");
					dequeue(row);
					i++;
					hotdog++;

					do {
						printf("A C �ȸԾ� �Ѥ�\n");
						dequeue(row);
						i++;

						if (row->front != NULL)
							patience2 = (int)row->front->data - sell;
					}
					while (patience2 < 0 && row->count > 0); // ���ʿ��� ���� ������� ���� �ִ� ����� ã��

					if (row->count > 0) // ������� ���� �ִ� ����� ã���� ��
					{
						printf("�߸԰ڽ��ϴ� ����\n");
						dequeue(row);
						i++;
						hotdog++;
					} // ��� ������� ���� ���ϰ� �������� �ջ�����Ը� �Ǹ�

					sell++;
				}
				else // �޻���� ���� ������� ������ �� ��
				{
					printf("�߸԰ڽ��ϴ� ����\n");
					dequeue(row);
					i++;
					hotdog++;

					printf("�߸԰ڽ��ϴ� ����\n");
					dequeue(row);
					i++;
					hotdog++;

					sell++;
				}
			}
		}
		else if (row->count == 1) // �Ѹ� ������ ��
		{
			patience1 = (int)row->front->data - sell;
			if (patience1 < 0)
			{
				printf("A C �ȸԾ� �Ѥ�\n");
				dequeue(row);
				i++;
			}
			else
			{
				printf("�߸԰ڽ��ϴ� ����\n");
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