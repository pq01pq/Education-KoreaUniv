
typedef struct {
	void **stack;
	int size;
	int top;
} Stack;

Stack *CreateStack(int size)
{
	Stack *pStack = (Stack *)malloc(sizeof(Stack));
	if (pStack == NULL)
		return NULL;
	
	pStack->stack = (void **)malloc(SIZE * sizeof(void *));
	if (pStack->stack == NULL) {
		free(pStack);
		return NULL;
	}

	pStack->size = size;
	pStack->top = -1;

	return pStack;
}

void Push(Stack *pStack, void *data)
{
	//������ �� á���� �˻�
	if (pStack->top == pStack->size - 1)
		printf("The stack is full\n");
	else
		pStack->stack[++pStack->top] = data;
	
	return;
}

void *Pop(Stack *pStack)
{
	//������ ������� �˻�
	if (pStack->top < 0) {
		printf("The stack is empty\n");
		return;
	}
	else
		return pStack->stack[pStack->top--];
}

void *StackTop(Stack *pStack)
{
	//������ ������� �˻�
	if (pStack->top < 0) {
		printf("The stack is empty\n");
		return;
	}
	else
		return pStack->stack[pStack->top];
}

void DestroyStack(Stack *pStack)
{
	//�޸� ����
	if (pStack->size > 0)
		free(pStack->stack);

	free(pStack);

	return;
}