#include <stdio.h>

char *my_strchr(char *s, char c);
void my_strcpy(char *s1, char *s2);
int my_strcmp(char *s1, char *s2);
void my_to_lower(char *s1, char *s2);
void my_to_upper(char *s1, char *s2);

void main(void)
{
	// 1번에 쓰이는 변수
	char s[100];
	char c;
	char *addr;
	int p;
	// 2번에 쓰이는 변수
	char s1[100], s2[100];
	// 3번에 쓰이는 변수
	char t1[100], t2[100];
	int cmp;
	// 4번에 쓰이는 변수
	char u1[100], u2[100];
	// 5번에 쓰이는 변수
	char v1[100], v2[100];
	
	// 1. 문자열 내의 원하는 문자의 첫번째 위치
	printf("1. 문자열 내의 원하는 문자의 첫번째 위치\n");
	printf("문자열을 입력하시오 : ");
	scanf("%s", s);
	// 배열 s 저장 상태 확인 //printf("%s\n", s);

	printf("문자열 내에서 첫번째 위치를 알고싶은 문자를 입력하시오 : ");
	scanf("%s", &c);
	// 배열 s 저장 상태 확인 //printf("%s\n", s);
	
	addr = my_strchr(s, c); // 문자의 첫번째 위치의 주소
	p = addr - s;           // (문자의 포인터) = (문자의 주소) - (배열의 첫번째 주소)
	if (addr == NULL)
		printf("문자열 내에 해당 문자가 없습니다.\n");
	else
		printf("문자열 내에서 문자의 첫번째 위치는 \'s[%d]\'입니다.\n", p);
	printf("\n");

	// 2. 문자열 s2를 문자열 s1에 복사
	printf("2. 문자열 s2를 문자열 s1에 복사\n");
	printf("복사할 문자열을 입력하시오 : ");
	scanf("%s", s2);

	my_strcpy(s1, s2);
	printf("\"%s\" 복사가 완료되었습니다.\n", s1);
	printf("\n");

	// 3. 두 문자열을 사전적 순서에 따라 비교
	printf("3. 두 문자열을 사전적 순서에 따라 비교\n");
	printf("문자열 비교를 시작합니다.\n");
	printf("한 문자열을 입력하시오   : ");
	scanf("%s", t1);
	printf("다른 문자열을 입력하시오 : ");
	scanf("%s", t2);

	cmp = my_strcmp(t1, t2);
	if (cmp == 1)
		printf("\"%s\"이 \"%s\"보다 사전적으로 앞에 있습니다.\n", t2, t1);
	else if (cmp == -1)
		printf("\"%s\"이 \"%s\"보다 사전적으로 앞에 있습니다.\n", t1, t2);
	else  // cmp == 0
		printf("\"%s\"와 \"%s\"는 같은 문자열입니다.\n", t1, t2);
	printf("\n");

	// 4. 문자열의 문자들을 모두 소문자로 변환
	printf("4. 문자열의 문자들을 모두 소문자로 변환\n");
	printf("문자를 모두 소문자로 바꿀 문자열을 입력하시오 : ");
	scanf("%s", u2);

	my_to_lower(u1, u2);
	printf("문자열의 대문자가 모두 소문자로 변경되었습니다 : \"%s\"\n", u1);
	printf("\n");

	// 5. 문자열의 문자들을 모두 대문자로 변환
	printf("5. 문자열의 문자들을 모두 대문자로 변환\n");
	printf("문자를 모두 대문자로 바꿀 문자열을 입력하시오 : ");
	scanf("%s", v2);

	my_to_upper(v1, v2);
	printf("문자열의 소문자가 모두 대문자로 변경되었습니다 : \"%s\"\n", v1);
	printf("\n");

	return;
}

char *my_strchr(char *s, char c)
{
	char *p = s;
	
	while ((*s != c) && (*s != '\0'))
		s++;

	if (*s == c)
		return (char *)s;
	else
		return NULL;
}

void my_strcpy(char *s1, char *s2)
{
	while (*s2 != '\0')
		*s1++ = *s2++;
	*s1 = '\0';
}

int my_strcmp(char *s1, char *s2)
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

void my_to_lower(char *s1, char *s2)
{
	while (*s2 != '\0')
	{
		if ((*s2 >= 'A') && (*s2 <= 'Z'))
			*s1 = *s2 - ('A' - 'a');
		else
			*s1 = *s2;

		s1++;
		s2++;
	}

	*s1 = '\0';
}

void my_to_upper(char *s1, char *s2)
{
	while (*s2 != '\0')
	{
		if ((*s2 >= 'a') && (*s2 <= 'z'))
			*s1 = *s2 + ('A' - 'a');
		else
			*s1 = *s2;

		s1++;
		s2++;
	}

	*s1 = '\0';
}