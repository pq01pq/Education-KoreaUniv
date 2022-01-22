#include"stackADT.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	STACK* stack = createStack();
	char token;
	char* dataPtr;
	bool err = false;

	stack = createStack();
	printf("Enter a string: ");

	while (err == false && (token = getchar()) != '\n')
	{
		switch (token)
		{
		case '(':
		case '{':
		case '[':
			dataPtr = (char*)malloc(sizeof(char));
			*dataPtr = token;
			pushStack(stack, dataPtr);
			break;
		case ')':
			if (*(char*)popStack(stack) != '(')
				err = true;
			break;
		case '}':
			if (*(char*)popStack(stack) != '{')
				err = true;
			break;
		case ']':
			if (*(char*)popStack(stack) != '[')
				err = true;
			break;
		}
	}

	if (emptyStack(stack))
		printf("Yes\n");
	else
		printf("No\n");
	destroyStack(stack);

	return 0;
}