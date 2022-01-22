#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "heapADT.h"

HEAP* heapCreate()
{
	HEAP* heap = (HEAP*)malloc(sizeof(HEAP));
	if (!heap) return NULL;

	heap->size = 0;
	heap->last = -1;
	heap->max = HEAP_ARR_SIZE;
	heap->heapArr = (int*)malloc(HEAP_ARR_SIZE * sizeof(int));

	return heap;
}

void heapDestroy(HEAP* heap)
{
	free(heap->heapArr);
	free(heap);
}

void heapSort(int* input, int* output, size_t size)
{
	// Write your code here.
}

bool heapInsert(HEAP* heap, int input)
{
	// Write your code here.
}

int heapDelete(HEAP* heap)
{
	// Write your code here.
}

void _reheapUp(HEAP* heap, int pos)
{
	// Write your code here.
}

void _reheapDown(HEAP* heap, int pos)
{
	// Write your code here.
}

int heapCount(HEAP* heap)
{
	return heap->size;
}

bool heapFull(HEAP* heap)
{
	return heap->size >= heap->max;
}

bool heapEmpty(HEAP* heap)
{
	return heap->size == 0;
}
