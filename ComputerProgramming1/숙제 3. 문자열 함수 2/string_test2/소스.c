#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char *my_strchr(char *s, char c);
void my_strcpy(char *s1, char *s2);
int my_strcmp(char *s1, char *s2);
void my_to_lower(char *s1, char *s2);
void my_to_upper(char *s1, char *s2);

void main(void)
{
	// 1���� ���̴� ����
	char s[100];
	char c;
	char *addr;
	int p;
	// 2���� ���̴� ����
	char s1[100], s2[100];
	// 3���� ���̴� ����
	char t1[100], t2[100];
	int cmp;
	// 4���� ���̴� ����
	char u1[100], u2[100];
	// 5���� ���̴� ����
	char v1[100], v2[100];

	// 1. ���ڿ� ���� ���ϴ� ������ ù��° ��ġ
	printf("1. ���ڿ� ���� ���ϴ� ������ ù��° ��ġ\n");
	printf("���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", s);
	// �迭 s ���� ���� Ȯ�� //printf("%s\n", s);

	printf("���ڿ� ������ ù��° ��ġ�� �˰���� ���ڸ� �Է��Ͻÿ� : ");
	scanf("%s", &c);
	// �迭 s ���� ���� Ȯ�� //printf("%s\n", s);

	addr = my_strchr(s, c); // ������ ù��° ��ġ�� �ּ�
	p = addr - s;           // (������ ������) = (������ �ּ�) - (�迭�� ù��° �ּ�)
	if (addr == NULL)
		printf("���ڿ� ���� �ش� ���ڰ� �����ϴ�.\n");
	else
		printf("���ڿ� ������ ������ ù��° ��ġ�� \'s[%d]\'�Դϴ�.\n", p);
	printf("\n");

	// 2. ���ڿ� s2�� ���ڿ� s1�� ����
	printf("2. ���ڿ� s2�� ���ڿ� s1�� ����\n");
	printf("������ ���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", s2);

	my_strcpy(s1, s2);
	printf("\"%s\" ���簡 �Ϸ�Ǿ����ϴ�.\n", s1);
	printf("\n");

	// 3. �� ���ڿ��� ������ ������ ���� ��
	printf("3. �� ���ڿ��� ������ ������ ���� ��\n");
	printf("���ڿ� �񱳸� �����մϴ�.\n");
	printf("�� ���ڿ��� �Է��Ͻÿ�   : ");
	scanf("%s", t1);
	printf("�ٸ� ���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", t2);

	cmp = my_strcmp(t1, t2);
	if (cmp == 1)
		printf("\"%s\"�� \"%s\"���� ���������� �տ� �ֽ��ϴ�.\n", t2, t1);
	else if (cmp == -1)
		printf("\"%s\"�� \"%s\"���� ���������� �տ� �ֽ��ϴ�.\n", t1, t2);
	else  // cmp == 0
		printf("\"%s\"�� \"%s\"�� ���� ���ڿ��Դϴ�.\n", t1, t2);
	printf("\n");

	// 4. ���ڿ��� ���ڵ��� ��� �ҹ��ڷ� ��ȯ
	printf("4. ���ڿ��� ���ڵ��� ��� �ҹ��ڷ� ��ȯ\n");
	printf("���ڸ� ��� �ҹ��ڷ� �ٲ� ���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", u2);

	my_to_lower(u1, u2);
	printf("���ڿ��� �빮�ڰ� ��� �ҹ��ڷ� ����Ǿ����ϴ� : \"%s\"\n", u1);
	printf("\n");

	// 5. ���ڿ��� ���ڵ��� ��� �빮�ڷ� ��ȯ
	printf("5. ���ڿ��� ���ڵ��� ��� �빮�ڷ� ��ȯ\n");
	printf("���ڸ� ��� �빮�ڷ� �ٲ� ���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", v2);

	my_to_upper(v1, v2);
	printf("���ڿ��� �ҹ��ڰ� ��� �빮�ڷ� ����Ǿ����ϴ� : \"%s\"\n", v1);
	printf("\n");

	return;
}

char *my_strchr(char *s, char c)
{
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