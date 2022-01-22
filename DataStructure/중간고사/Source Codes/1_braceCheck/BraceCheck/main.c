#define _CRT_SECURE_NO_WARNINGS

#include "stackADT.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define STR_MAX 256

bool braceCheck(const char* str)
{
	STACK* stack = createStack();
	int n = strlen(str);
	int i = 0;
	char c;

	while (i < n)
	{
		switch (str[i])
		{
		case '(':
		case '{':
		case '[':
			pushStack(stack, str[i]);
			break;
		case ')':
			if (*(char *)stackTop(stack) == '(')
				popStack(stack);
			break;
		case '}':
			if (*(char *)stackTop(stack) == '{')
				popStack(stack);
			break;
		case ']':
			if (*(char *)stackTop(stack) == '[')
				popStack(stack);
			break;
		case '/':
			if (stackTop(stack) == '*')
			{
				popStack(stack);
				if (stackTop(stack) == '*')
				{
					popStack(stack);
					if (stackTop(stack) == '/')
					{
						popStack(stack);
					}
					else
						return false;
				}
				else
					return false;
			}
			else
			{
				pushStack(stack, &str[i]);
			}
			break;
		case '*':
			if (stackTop(stack) == '/' || stackTop(stack) == '*')
			{
				pushStack(stack, &str[i]);
			}
			else
				return false;
			break;
		}

		printf("%c\n", *(char *)stackTop(stack));
		i++;
	}

	if (isEmpty(stack))
	{
		stack = destroyStack(stack);
		return true;
	}
	else
	{
		stack = destroyStack(stack);
		return false;
	}
}

int main(void)
{
	char str[STR_MAX];
	printf("Enter a string: \n");

	while (true)
	{
		scanf("%s", str);
		if (strcmp(str, "exit") == 0)
		{
			break;
		}

		if (braceCheck(str))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}

	}

	return 0;
}