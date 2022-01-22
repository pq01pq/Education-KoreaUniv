#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N 100 //max string length

int stringLength(char *s, int length)
{
	if (*s == NULL)
		return length;
	else
		return stringLength(s + 1, length + 1);
}

int palindrome(char *s, int length, int index)
{
	if (index >= length / 2) // index가 중간까지 왔으면 palindrome이므로 종료
		return 1;

	if (*(s + index) == *(s + length - 1 - index)) // 좌우 대칭값 비교
		return palindrome(s, length, index + 1);
	else
		return 0;
}

void main(void)
{
	char s[N];

	printf("Input string : ");
	fscanf(stdin, "%s", s);

	int length = 0;
	length = stringLength(s, length);
	printf("String length : %d\n", length);

	int index = 0;
	int isPalindrome = 0;
	isPalindrome = palindrome(s, length, index);

	if (isPalindrome)
		printf("\"%s\" is palindrome.\n", s);
	else
		printf("\"%s\" is not palindrome.\n", s);

	return;
}