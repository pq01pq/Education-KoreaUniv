#include <stdio.h>

int my_strlen(char *s);
void print_str(char *s);
void print_rstr(char *s);
int count_char(char *s, char c);

int main(void)
{
	char s[1000];	// 1000자 미만의 문자열의 배열
	int n;			// 문자열의 크기
	char c;			// 문자열 내에서 갯수를 알고싶은 문자
	int cnt;		// 문자열 내에서 알고싶은 문자의 갯수

	// 1. 문자열 입력
	printf("\n");
	printf("문자열을 입력하세요 : ");
	scanf("%s", s);		// 문자열 입력란
	printf("\n");
	
	// 2. 문자열 크기 출력
	n = my_strlen(s);													
	printf("문자열 %s의 크기는 %d입니다.\n\n", s, n);

	// 3. 문자열 세로로 출력
	printf("문자열 %s를 출력하면 다음과 같습니다.\n\n", s);
	print_str(s);
	printf("\n");

	// 4.  문자열 세로로 역순 출력
	printf("문자열 %s를 역순으로 출력하면 다음과 같습니다.\n\n", s);
	print_rstr(s);
	printf("\n");

	// 5. 문자열 내의 해당 문자의 갯수
	printf("문자열 내에서 갯수를 알고싶은 문자를 입력하세요 : ");
	scanf("%s", &c);	// 문자 입력란
	printf("\n");

	cnt = count_char(s, c);

	printf("문자열 %s안에는 %d개의 '%c'가 있습니다.\n\n", s, cnt, c);

	return 0;
}

int my_strlen(char *s)
{
	int cnt = 0;

	while (*s != '\0')
	{
		cnt++;
		s++;
	}

	return cnt;
}

void print_str(char *s)
{
	while (*s != '\0')
		printf("%c\n", *s++);
}

void print_rstr(char *s)
{
	int n = 0;
	int i = 0;

	while (*s != '\0')
	{
		n++;
		s++;					// *s = s[n] = '\0'
	}

	while (i < n)
	{
		printf("%c\n", *--s);	// *s = s[n - 1] 부터 출력
		i++;
	}
}

int count_char(char *s, char c)
{
	int m = 0;

	while (*s != '\0')
	{
		if (*s == c)
			m++;
		s++;
	}

	return m;
}