#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

float max_point(float p[]), min_point(float p[]), total_point(float p[]), ave_point(float p[]);

void main(void)
{
	float p[10];
	char c[10];
	int i;

	printf("�л� 10���� ������ �Է��Ͻÿ�.\n\n");

	for (i = 0; i < 10; i++)
	{
		printf("[%d]��° �л��� ���� : ", i + 1);
		scanf("%f", &p[i]);
	}

	printf("\n");
	printf("�л� 10���� ������ ���� ");
	printf("�ִ��� %.2f�̰�, ", max_point(p));
	printf("�ּڰ��� %.2f�̰�, ", min_point(p));
	printf("������ %.2f�̰�, ", total_point(p));
	printf("����� %.2f�Դϴ�.\n", ave_point(p));
	printf("\n");

	for (i = 0; i < 10; i++)
	{
		if (p[i] >= 90.0)
			c[i] = 'A';
		else if (p[i] >= 80.0)
			c[i] = 'B';
		else if (p[i] >= 70.0)
			c[i] = 'C';
		else if (p[i] >= 60.0)
			c[i] = 'D';
		else c[i] = 'F';

		printf("[%d]��° �л��� ������ %c�Դϴ�.\n", i + 1, c[i]);
	}

	return;
}

float max_point(float p[])
{
	float max = p[0];
	int i;

	for (i = 0; i < 9; i++)
	{
		if (p[i] < p[i + 1])
			max = p[i + 1];
	}

	return max;
}

float min_point(float p[])
{
	float min = p[0];
	int i;

	for (i = 0; i < 9; i++)
	{
		if (p[i] > p[i + 1])
			min = p[i + 1];
	}

	return min;
}

float total_point(float p[])
{
	float sum = 0;
	int i;

	for (i = 0; i < 10; i++)
		sum += p[i];

	return sum;
}

float ave_point(float p[])
{
	float sum = 0, ave = 0;
	int i;

	for (i = 0; i < 10; i++)
		sum += p[i];

	ave = sum / i;

	return ave;
}