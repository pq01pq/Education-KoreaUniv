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
			Push(operand, (double) s[i] - '0'); // 문자를 숫자로 바꾸어 스택에 저장

			if (op->top == NULL) // 처음 들어간 숫자는 연산을 실행하지 않음
				;
			else // 곱하기와 나누기 연산 우선 실행
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

			if (op->top == NULL) // 처음부터 괄호로 시작하는 식은 괄호 처리 후 연산을 실행하지 않음
				;
			else //괄호 때문에 처리하지 못한 곱하기와 나누기 연산 실행
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

	// 마지막에 더하기와 빼기 연산 일괄 실행
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

int isGrammarCorrect(char *s)
{
	if (!((s[0] >= '0' && (int)s[0] <= '9') || s[0] == '(')) // 맨 처음이 숫자나 여는 괄호가 아닐 경우
		return 0;

	int i = 1;
	while (s[i] != NULL) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			if (s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/') // 1-1. 연산자 앞에 연산자가 나올 경우
				return 0;
			if (s[i - 1] == '(') // 1-2. 연산자 앞에 여는 괄호가 나올 경우
				return 0;
		}

		if (s[i] == '(')
		{
			if (s[i - 1] == ')') // 2. 괄호들 사이에 연산자가 없을 경우
				return 0;
		}

		if (s[i] == ')')
		{
			if (s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/') // 3-1. 닫는 괄호 앞에 연산자가 나올 경우
				return 0;
			if (s[i - 1] == '(') // 3-2. 괄호 안에 아무것도 없을 경우
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
	if ( !( (s[i - 1] >= '0' && s[i - 1] <= '9') || s[i - 1] == ')') ) // 맨 끝이 숫자나 닫는 괄호가 아닐 경우
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