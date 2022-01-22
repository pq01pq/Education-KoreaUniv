#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100 // 문자열 크기

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int isBraceCorrect(char *s)
{
	Stack *a = CreateStack();

	int i = 0;
	while (s[i] != NULL) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			Push(a, s[i]);

		if (s[i] == ')') {
			if (a->count == 0) // 스택이 비었을 경우 닫는 괄호가 먼저 나오면 틀린 문장 (빨리 종결하기 위해 설정)
			{
				DestroyStack(a);
				return 0;
			}
			if (StackTop(a) == '(') // 맞는 경우
				Pop(a);
			else // 짝이 맞는 괄호 외의 괄호가 스택에 있을 경우
			{
				DestroyStack(a);
				return 0;
			}
		}

		if (s[i] == '}') {
			if (a->count == 0)
			{
				DestroyStack(a);
				return 0;
			}
			if (StackTop(a) == '{')
				Pop(a);
			else
			{
				DestroyStack(a);
				return 0;
			}
		}

		if (s[i] == ']')
		{
			if (a->count == 0) {
				DestroyStack(a);
				return 0;
			}
			if (StackTop(a) == '[')
				Pop(a);
			else
			{
				DestroyStack(a);
				return 0;
			}
		}

		i++;
	}

	if (a->count == 0) {
		DestroyStack(a);
		return 1;
	}
	else {
		DestroyStack(a);
		return 0;
	}
}

void main(void)
{
	char s[SIZE];

	printf("This program checks whether formula or scentence has correct brace pairs or not.\n");
	printf("Input formula or sentence : ");
	scanf("%s", s);

	if (isBraceCorrect(s))
		printf("Correct brace pairs.\n");
	else
		printf("Incorrect brace pairs.\n");

	return;
}