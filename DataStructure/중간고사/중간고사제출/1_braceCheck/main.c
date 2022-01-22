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

	while (*str != NULL)
	{
		switch (*str)
		{
		case '(':
		case '{':
		case '[':
		case'*':
		case '/':
			pushStack(stack, *str);
			break;
		case ')':
			if ((char)popStack(stack) != '(')
				return false;
		case '}':
			if ((char)popStack(stack) != '{')
				return false;
		case ']':
			if ((char)popStack(stack) != '[')
				return false;
		default :
			break;
		}

		str++;
	}
	if (!isEmpty(stack))
		return false;
	else return true;
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