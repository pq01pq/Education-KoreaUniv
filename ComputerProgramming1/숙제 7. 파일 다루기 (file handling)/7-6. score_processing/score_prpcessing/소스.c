#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N 40

typedef struct {
	int id;        // �й�
	char name[30]; // �̸�
	int kor;       // ����
	int eng;       // ����
	int math;      // ����
	int total;     // ����
	float avr;     // ���
} student;

void main(void)
{
	student s[N];

	FILE *fp;
	fp = fopen("data.txt", "r");

	int i = 0;
	int num = 0;
	while (i < N)
	{
		if (fscanf(fp, "%d %s %d %d %d", &s[i].id, s[i].name, &s[i].kor, &s[i].eng, &s[i].math) != EOF) // ������ ���پ� ����
			num++; // �л��� ��

		i++;
	}

	i = 0;
	while (i < num)
	{
		s[i].total = s[i].kor + s[i].eng + s[i].math;
		s[i].avr = s[i].total / 3;
		i++;
	}
	// ������ �迭 NULL
	s[num].id = '\0';
	*s[num].name = '\0';
	s[num].kor = '\0';
	s[num].eng = '\0';
	s[num].math = '\0';
	s[num].total = '\0';
	s[num].avr = '\0';

	printf("      [�й�]    [�̸�]    [����] [����] [����] [����] [���]\n");
	i = 0;
	while (i < num)
	{
		printf("[%02d] %d  %-8s   %3d    %3d    %3d     %3d   %5.2f\n", i + 1, s[i].id, s[i].name, s[i].kor, s[i].eng, s[i].math, s[i].total, s[i].avr);
		i++;
	}

	fclose(fp);

	return;
}