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
	// 스택의 크기는 고려대상이 아님
	Stack *pStack = (Stack *)malloc(sizeof(Stack));
	if (pStack == NULL)
		return NULL;
	
	pStack->count = 0;
	pStack->top = NULL;	// 스택의 맨 아래 노드의 next가 가리키는 값도 NULL이 됨

	return pStack;
}

void Push(Stack *pStack, void *item)
{
	StackNode *pNewNode = (StackNode *)malloc(sizeof(StackNode));
	if (pNewNode == NULL)
		return;

	pNewNode->data = item;			// 1. 새로운 노드에 데이터 저장
	pNewNode->next = pStack->top;	// 2. top이 가리키는 주소를 새 노드의 next도 가리킴 (순서 중요)
	pStack->top = pNewNode;			// 3. top이 가리키는 주소를 새 노드의 주소로 바꿈 (순서 중요)
	pStack->count++;				// 4. 노드의 갯수 증가
	
	return;
}

void *Pop(Stack *pStack)
{
	//스택이 비었는지 검사
	if (pStack->top == NULL) {
		printf("The stack is empty\n");
		return NULL;
	}
	else {
		void *item = pStack->top->data;		// 1. 없앨 노드의 데이터를 저장
		StackNode *pOldNode = pStack->top;	// 2. 원래 top이 가리키던 없앨 노드의 주소를 저장 (순서 중요)
		pStack->top = pOldNode->next;		// 3. top이 가리키는 주소를 없앨 노드의 next 노드의 주소로 바꿈 (순서 중요);
		free(pOldNode);						// 4. 노드를 삭제
		pStack->count--;					// 5. 노드의 갯수 감소

		return item;
	}
}

void *StackTop(Stack *pStack)
{
	//스택이 비었는지 검사
	if (pStack->top == NULL) {
		printf("The stack is empty\n");
		return;
	}
	else
		return pStack->top->data;
}

void DestroyStack(Stack *pStack)
{
	// Pop과 비슷한 과정을 여러번 실행
	while (pStack->top != NULL) {
		StackNode *pOldNode = pStack->top;
		pStack->top = pOldNode->next;
		free(pOldNode);
	}
	free(pStack);

	return;
}