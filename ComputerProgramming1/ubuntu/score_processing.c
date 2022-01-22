#include <stdio.h>
#include <stdlib.h>

#define N 40

typedef struct {
	int id;        // 학번
	char name[30]; // 이름
	int kor;       // 국어
	int eng;       // 영어
	int math;      // 수학
	int total;     // 총점
	float avr;     // 평균
} student;

void id_sort(student arr[], int n);
void name_sort(student arr[], int n);
int my_strcmp(char *s1, char *s2);
void score_sort(student arr[], int n);

void main(int argc, char *argv[])
{
	student s[N];

	FILE *fp;
	if (argc == 2) // 옵션 입력하지 않을 때
		fp = fopen(argv[1], "r");
	if (argc == 3) // 옵션 입력할 때
		fp = fopen(argv[2], "r");

	int i = 0;
	int num = 0;
	while (i < N)
	{
		if (fscanf(fp, "%d %s %d %d %d", &s[i].id, s[i].name, &s[i].kor, &s[i].eng, &s[i].math) != EOF) // 파일을 한줄씩 읽음
			num++; // 학생의 수

		i++;
	}

	i = 0;
	while (i < num)
	{
		s[i].total = s[i].kor + s[i].eng + s[i].math;
		s[i].avr = s[i].total / 3;
		i++;
	}
	// 마지막 배열 NULL
	s[num].id = '\0';
	*s[num].name = '\0';
	s[num].kor = '\0';
	s[num].eng = '\0';
	s[num].math = '\0';
	s[num].total = '\0';
	s[num].avr = '\0';

	if (argc == 3)
		if (argv[1][0] == '-')
			if (argv[1][1] == 'i')      // 옵션 '-i' : 학번의 오름차순으로 정렬
				id_sort(s, num);
			else if (argv[1][1] == 'n') // 옵션 '-n' : 이름의 오름차순으로 정렬
				name_sort(s, num);
			else if (argv[1][1] == 's') // 옵션 '-s' : 점수의 내림차순으로 정렬
				score_sort(s, num);

	printf("      [학번]    [이름]  [국어] [영어] [수학]  [총점] [평균]\n");
	i = 0;
	while (i < num)
	{
		printf("[%02d] %d  %-8s   %3d    %3d    %3d     %3d   %5.2f\n", i + 1, s[i].id, s[i].name, s[i].kor, s[i].eng, s[i].math, s[i].total, s[i].avr);
		i++;
	}

	fclose(fp);

	return;
}

void id_sort(student s[], int n) // 오름차순
{
	student temp;
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (s[i].id > s[j].id)
			{
				temp = s[j];
				s[j] = s[i];
				s[i] = temp;
			}
		}
	}
	return;
}

void name_sort(student s[], int n) // 오름차순
{
	student temp;
	int i, j;
	int cmp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (my_strcmp(s[i].name, s[j].name) > 0)
			{
				temp = s[j];
				s[j] = s[i];
				s[i] = temp;
			}
		}
	}
	return;
}

int my_strcmp(char *s1, char *s2) // 숙제 3. 복사 ㅎㅎ
{
	while ((*s1 != '\0') && (*s2 != '\0'))
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else if (*s1 > *s2)
			return 1;
		else if (*s1 < *s2)
			return -1;
	}

	if ((*s1 != '\0') && (*s2 == '\0'))
		return 1;
	else if ((*s1 == '\0') && (*s2 != '\0'))
		return -1;
	else  // (*s1 == '\0') && (*s2 == '\0')
		return 0;
}

void score_sort(student s[], int n) // 내림차순
{
	student temp;
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (s[i].total < s[j].total)
			{
				temp = s[j];
				s[j] = s[i];
				s[i] = temp;
			}
		}
	}
	return;
}