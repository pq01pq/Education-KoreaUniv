#include "stackADT.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int priority(char token);
bool isOperator(char token);
double calc(double operand1, int oper, double operand2);

int main(void)
{
	char postfix[80] = { 0 };
	char temp[2] = { 0 };
	char token;
	char* dataPtr;
	STACK* stack;

	stack = createStack();
	printf("Enter an infix formula: ");

	while ((token = getchar()) != '\n')
	{
		if (token == '(')
		{
			dataPtr = (char*)malloc(sizeof(char));
			*dataPtr = token;
			pushStack(stack, dataPtr);
		}
		else if (token == ')')
		{
			dataPtr = (char*)popStack(stack);
			while (*dataPtr != '(') {
				temp[0] = *dataPtr;
				strcat(postfix, temp);
				dataPtr = (char*)popStack(stack);
			}
		}
		else if (isOperator(token))
		{
			dataPtr = (char*)stackTop(stack);
			while (!emptyStack(stack) && priority(token) <= priority(*dataPtr))
			{
				dataPtr = (char*)popStack(stack);
				temp[0] = *dataPtr;
				strcat(postfix, temp);
				dataPtr = (char*)stackTop(stack);
			}
			dataPtr = (char*)malloc(sizeof(char));
			*dataPtr = token;
			pushStack(stack, dataPtr);
		}
		else
		{
			temp[0] = token;
			strcat(postfix, temp);
		}
	}

	while (!emptyStack(stack))
	{
		dataPtr = (char*)popStack(stack);
		temp[0] = *dataPtr;
		strcat(postfix, temp);
	}

	destroyStack(stack);

	double operand1;
	double operand2;
	double value;
	double* dDataPtr;
    char aTok[2] = {0, 0};

	stack = createStack();
	for (int i = 0; i < strlen(postfix); i++)
	{
		token = postfix[i];
		if (!isOperator(token))
		{
			dDataPtr = (double*)malloc(sizeof(double));
            aTok[0] = token;
			*dDataPtr = atof(&aTok);
			pushStack(stack, dDataPtr);
		} else\
		{
			dDataPtr = (double*)popStack(stack);
			operand2 = *dDataPtr;
			dDataPtr = (double*)popStack(stack);
			operand1 = *dDataPtr;
			value = calc(operand1, token, operand2);
			dDataPtr = (double*)malloc(sizeof(double));
			*dDataPtr = value;
			pushStack(stack, dDataPtr);
		}
	}

	dDataPtr = (double*)popStack(stack);
	value = *dDataPtr;
	if (fmod(value, 1) == 0)
	{
		printf("Output: %.0f\n", value);
	} else
	{
		printf("Output: %.2f\n", value);
	}
	return 0;
}

int priority(char token)
{
	if (token == '*' || token == '/')
		return 2;
	if (token == '+' || token == '-')
		return 1;
	return 0;
}

bool isOperator(char token)
{
	if (token == '*' || token == '/' || token == '+' || token == '-')
		return true;
	return false;
}

double calc(double operand1, int oper, double operand2)
{
	double result;

	switch (oper) 
    {
	case '+':
		result = operand1 + operand2;
		break;
	case '-':
		result = operand1 - operand2;
		break;
	case '*':
		result = operand1 * operand2;
		break;
	case '/':
		if (operand2 == 0)
		{
			printf("DIVIDED_BY_ZERO\n");
			return 0;
		}
		result = operand1 / operand2;
		break;
	}

	return result;
}