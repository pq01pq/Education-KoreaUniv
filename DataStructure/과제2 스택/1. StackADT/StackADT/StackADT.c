#define _CRT_SECURE_NO_WARNINGS
#define DEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

// Stack 구조체 선언과 스택 연산 함수 원형은 stack.h 헤더파일에 선언되어있음.

Stack *CatStack(Stack *a, Stack *b)
{
	Stack *temp = CreateStack();

	while (b->count > 0) {
		Push(temp, Pop(b));
#if DEBUG
		if (b->count > 0)
			printf("b[%d] %d\n", b->count, b->top->data);
		printf("temp[%d] %d\n", temp->count, temp->top->data);
		printf("\n");
#endif
	}

	while (temp->count > 0) {
		Push(a, Pop(temp));
#if DEBUG
		if (temp->count > 0)
			printf("temp[%d] %d\n", temp->count, temp->top->data);
		printf("a[%d] %d\n", a->count, a->top->data);
		printf("\n");
#endif
	}

	DestroyStack(b);

	return a;
}

void main(void)
{
	Stack *a = CreateStack();
	Stack *b = CreateStack();

#if !DEBUG
	Push(a, 1);
	Push(a, 2);
	Push(a, 3);
	Push(b, 4);
	Push(b, 5);
#endif

#if DEBUG
	Push(a, 1);
	printf("a[%d] %d\n", a->count, a->top->data);
	Push(a, 2);
	printf("a[%d] %d\n", a->count, a->top->data);
	Push(a, 3);
	printf("a[%d] %d\n", a->count, a->top->data);
	Push(b, 4);
	printf("b[%d] %d\n", b->count, b->top->data);
	Push(b, 5);
	printf("b[%d] %d\n", b->count, b->top->data);
	printf("\n");
#endif

	a = CatStack(a, b);
	
#if DEBUG
	while (a->count > 0) {
		printf("a[%d] %d\n", a->count, a->top->data);
		Pop(a);
	}
#endif

	return;
}