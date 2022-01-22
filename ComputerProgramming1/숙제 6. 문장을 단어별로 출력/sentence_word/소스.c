#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define N 10

void main(void)
{
	char s[N + 2];  // buffer : s[N] = '\n', s[N + 1] = '\0'
	
	printf("이 프로그램은 문장을 단어별로 출력함.\n");
	printf("%d글자 이하의 문장을 입력하시오 : ", N);
	fgets(s, sizeof(s), stdin);
	int n = strlen(s);

	int i = 0;
	while ((s[i] == ' ') || (s[i] == '\t'))  // 문장의 시작에서부터 공백이 아닌 문자가 나올 때까지 포인터 증가
		i++;

	for ( ; i < n - 1; i++)  // i : ~ (n - 2) ('\n' 전까지 출력)
	{
		if ((s[i] != ' ') && (s[i] != '\t'))              // 1. 현재 포인터의 문자가 공백이 아닐 때
			printf("%c", s[i]);
		else                                              // 2. 현재 포인터의 문자가 공백일 때
		{
			if ((s[i + 1] != ' ') && (s[i + 1] != '\t'))  // 2-1. 공백 다음의 문자가 공백이 아닐 때 (문장이 공백으로 끝날 때에도 '\n' 출력)
				printf("\n");
			else                                          // 2-2. 공백 다음의 문자가 공백일 때
			{
				if (i < N - 1)                            // 2-2-1. 다음 공백이 메모리를 넘지 않았을 때
					;
				else                                      // 2-2-2. 다음 공백이 메모리를 넘었을 때
					printf("\n");
			}
		}
	}

	if ((s[i - 1] != ' ') && (s[i - 1] != '\t'))  // 문장이 공백으로 끝나지 않을 때 '\n' 출력
		printf("\n");

	if (s[N] == '\n')                               // s[N] = '\n', s[N + 1] = '\0'
		printf("메모리 한계입니다.\n");
	else if ((s[N] != '\0') && (s[N + 1] == '\0'))  // s[N] = char, s[N + 1] = '\0'
		printf("메모리 한계를 넘었습니다.\n");

	return;
}