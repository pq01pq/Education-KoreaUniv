#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int my_strlen(char *s);
void print_str(char *s);
void print_rstr(char *s);
int count_char(char *s, char c);

int main(void)
{
	char s[1000];	// 1000�� �̸��� ���ڿ��� �迭
	int n;			// ���ڿ��� ũ��
	char c;			// ���ڿ� ������ ������ �˰���� ����
	int cnt;		// ���ڿ� ������ �˰���� ������ ����

	// 1. ���ڿ� �Է�
	printf("\n");
	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", s);		// ���ڿ� �Է¶�
	printf("\n");
	
	// 2. ���ڿ� ũ�� ���
	n = my_strlen(s);													
	printf("���ڿ� %s�� ũ��� %d�Դϴ�.\n\n", s, n);

	// 3. ���ڿ� ���η� ���
	printf("���ڿ� %s�� ����ϸ� ������ �����ϴ�.\n\n", s);
	print_str(s);
	printf("\n");

	// 4.  ���ڿ� ���η� ���� ���
	printf("���ڿ� %s�� �������� ����ϸ� ������ �����ϴ�.\n\n", s);
	print_rstr(s);
	printf("\n");

	// 5. ���ڿ� ���� �ش� ������ ����
	printf("���ڿ� ������ ������ �˰���� ���ڸ� �Է��ϼ��� : ");
	scanf("%s", &c);	// ���� �Է¶�
	printf("\n");

	cnt = count_char(s, c);

	printf("���ڿ� %s�ȿ��� %d���� '%c'�� �ֽ��ϴ�.\n\n", s, cnt, c);

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
		printf("%c\n", *--s);	// *s = s[n - 1] ���� ���
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