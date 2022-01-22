#pragma once
// Node
typedef struct tStackNode{
	void *data;
	struct  tStackNode *next;
} StackNode;

// Head
typedef struct {
	int count;
	StackNode *top;
} Stack;

Stack *CreateStack(void)
{
	// ������ ũ��� �������� �ƴ�
	Stack *pStack = (Stack *)malloc(sizeof(Stack));
	if (pStack == NULL)
		return NULL;
	
	pStack->count = 0;
	pStack->top = NULL;	// ������ �� �Ʒ� ����� next�� ����Ű�� ���� NULL�� ��

	return pStack;
}

void Push(Stack *pStack, void *item)
{
	StackNode *pNewNode = (StackNode *)malloc(sizeof(StackNode));
	if (pNewNode == NULL)
		return;

	pNewNode->data = item;			// 1. ���ο� ��忡 ������ ����
	pNewNode->next = pStack->top;	// 2. top�� ����Ű�� �ּҸ� �� ����� next�� ����Ŵ (���� �߿�)
	pStack->top = pNewNode;			// 3. top�� ����Ű�� �ּҸ� �� ����� �ּҷ� �ٲ� (���� �߿�)
	pStack->count++;				// 4. ����� ���� ����
	
	return;
}

void *Pop(Stack *pStack)
{
	//������ ������� �˻�
	if (pStack->top == NULL) {
		printf("The stack is empty\n");
		return NULL;
	}
	else {
		void *item = pStack->top->data;		// 1. ���� ����� �����͸� ����
		StackNode *pOldNode = pStack->top;	// 2. ���� top�� ����Ű�� ���� ����� �ּҸ� ���� (���� �߿�)
		pStack->top = pOldNode->next;		// 3. top�� ����Ű�� �ּҸ� ���� ����� next ����� �ּҷ� �ٲ� (���� �߿�);
		free(pOldNode);						// 4. ��带 ����
		pStack->count--;					// 5. ����� ���� ����

		return item;
	}
}

void *StackTop(Stack *pStack)
{
	//������ ������� �˻�
	if (pStack->top == NULL) {
		printf("The stack is empty\n");
		return;
	}
	else
		return pStack->top->data;
}

void DestroyStack(Stack *pStack)
{
	// Pop�� ����� ������ ������ ����
	while (pStack->top != NULL) {
		StackNode *pOldNode = pStack->top;
		pStack->top = pOldNode->next;
		free(pOldNode);
	}
	free(pStack);

	return;
}