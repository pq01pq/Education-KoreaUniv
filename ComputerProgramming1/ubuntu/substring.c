#include <stdio.h>

void print_nchar(char *str, int n);

void main(void)
{
	char s[100];
	int n = 0;
	int i = 0;

	printf("이 프로그램은 문자열의 모든 부분문자열을 출력함.\n");
	printf("문자열을 입력하시오 : ");
	scanf("%s", s);

	while (s[i] != '\0')
	{
		n++;
		i++;
	}

	print_nchar(s, n);

	return;
}

void print_nchar(char *s, int n)
{
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			for (k = i; k < j + 1; k++)
			{
				printf("%c", s[k]);
			}
			printf("\n");
		}
	}

	for (i = 0; i < n; i++)
		printf("=");
	printf("\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			for (k = j; k < (j + i) + 1; k++)
			{
				printf("%c", s[k]);
			}
			printf("\n");
		}
	}

	return;
}