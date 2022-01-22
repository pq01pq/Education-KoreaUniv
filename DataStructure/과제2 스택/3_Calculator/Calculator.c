#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100 //maximum string size
#define DEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include "stackADTdouble.h"

double StackCalculator(char *s)
{
	Stack *operand = CreateStack(); // operands
	Stack *op = CreateStack(); // operators
	double a, b; // temporary operands

	int i = 0;
	while (s[i] != NULL)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			Push(operand, (double) s[i] - '0'); // ���ڸ� ���ڷ� �ٲپ� ���ÿ� ����

			if (op->top == NULL) // ó�� �� ���ڴ� ������ �������� ����
				;
			else // ���ϱ�� ������ ���� �켱 ����
			{
				if ( (int)op->top->data == '*') {
				b = Pop(operand);
				Pop(op);
				a = Pop(operand);
				Push(operand, a * b);
				}
				if ((int)op->top->data == '/') {
					b = Pop(operand);
					if (b == 0.0) {
						printf("Divided by zero\n");
						return;
					}
					Pop(op);
					a = Pop(operand);
					Push(operand, a / b);
				}
			}
		}

		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || (s[i] == '('))
		{
			Push(op, s[i]);
		}

		if (s[i] == ')')
		{
			while ( (int)op->top->data != '(')
			{
				if ( (int)op->top->data == '+')
				{
					b = Pop(operand);
					Pop(op);
					a = Pop(operand);
					Push(operand, a + b);
				}
				else if ( (int)op->top->data == '-')
				{
					b = Pop(operand);
					Pop(op);
					a = Pop(operand);
					Push(operand, a - b);
				}
			}
			Pop(op); // Pop '('

			if (op->top == NULL) // ó������ ��ȣ�� �����ϴ� ���� ��ȣ ó�� �� ������ �������� ����
				;
			else //��ȣ ������ ó������ ���� ���ϱ�� ������ ���� ����
			{
				if ((int)op->top->data == '*') {
					b = Pop(operand);
					Pop(op);
					a = Pop(operand);
					Push(operand, a * b);
				}
				else if ((int)op->top->data == '/') {
					b = Pop(operand);
					if (b == 0.0) {
						printf("Divided by zero\n");
						return;
					}
					Pop(op);
					a = Pop(operand);
					Push(operand, a / b);
				}
			}
		}

		i++;
	}

	// �������� ���ϱ�� ���� ���� �ϰ� ����
	while (op->count > 0)
	{
		if ( (int)op->top->data == '+')
		{
			b = Pop(operand);
			Pop(op);
			a = Pop(operand);
			Push(operand, a + b);
		}
		else if ( (int)op->top->data == '-')
		{
			b = Pop(operand);
			Pop(op);
			a = Pop(operand);
			Push(operand, a - b);
		}
	}

	double Answer = operand->top->data;
	
	DestroyStack(operand);
	DestroyStack(op);

	return Answer;
}

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

int isGrammarCorrect(char *s)
{
	if (!((s[0] >= '0' && (int)s[0] <= '9') || s[0] == '(')) // �� ó���� ���ڳ� ���� ��ȣ�� �ƴ� ���
		return 0;

	int i = 1;
	while (s[i] != NULL) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			if (s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/') // 1-1. ������ �տ� �����ڰ� ���� ���
				return 0;
			if (s[i - 1] == '(') // 1-2. ������ �տ� ���� ��ȣ�� ���� ���
				return 0;
		}

		if (s[i] == '(')
		{
			if (s[i - 1] == ')') // 2. ��ȣ�� ���̿� �����ڰ� ���� ���
				return 0;
		}

		if (s[i] == ')')
		{
			if (s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/') // 3-1. �ݴ� ��ȣ �տ� �����ڰ� ���� ���
				return 0;
			if (s[i - 1] == '(') // 3-2. ��ȣ �ȿ� �ƹ��͵� ���� ���
				return 0;
		}

		if (s[i] >= '0' && s[i] <= '9')
		{
			if (s[i - 1] >= '0' && s[i - 1] <= '9')
				return 0;
			if (s[i - 1] == ')')
				return 0;
		}

		i++;
	}
	if ( !( (s[i - 1] >= '0' && s[i - 1] <= '9') || s[i - 1] == ')') ) // �� ���� ���ڳ� �ݴ� ��ȣ�� �ƴ� ���
		return 0;

	return 1;
}

void main(void)
{
	char s[SIZE];

	printf("Input formula : ");
	scanf("%s", s);

	int isBraceOK = isBraceCorrect(s);
	int isGrammarOK = isGrammarCorrect(s);
#if DEBUG
	printf("is Brace Correct? %d\n", isBraceOK);
	printf("is Grammar Correct? %d\n", isGrammarOK);
#endif
	if (isBraceOK && isGrammarOK)
		printf("Answer = %f\n", StackCalculator(s));
	else
		printf("Invalid formula\n");

	return;
}