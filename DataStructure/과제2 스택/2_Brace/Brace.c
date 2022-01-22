#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100 // ���ڿ� ũ��

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
			if (a->count == 0) // ������ ����� ��� �ݴ� ��ȣ�� ���� ������ Ʋ�� ���� (���� �����ϱ� ���� ����)
			{
				DestroyStack(a);
				return 0;
			}
			if (StackTop(a) == '(') // �´� ���
				Pop(a);
			else // ¦�� �´� ��ȣ ���� ��ȣ�� ���ÿ� ���� ���
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