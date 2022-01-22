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
	HEAP *heap = heapCreate();
	unsigned int i;
	for (i = 0; i < size; i++)
	{
		heapInsert(heap, input[i]);
	}
	for (i = 0; i < size; i++)
	{
		output[i] = heapDelete(heap);
	}

	return;
}

bool heapInsert(HEAP* heap, int input)
{
	if (heap)
	{
		if (heap->size < heap->max)
		{
			heap->heapArr[heap->size] = input;
			heap->size++;
			heap->last++;
			_reheapUp(heap, heap->last);
			return true;
		}
	}
	return false;
}

int heapDelete(HEAP* heap)
{
	if (heap)
	{
		if (heap->size > 0)
		{
			int data = heap->heapArr[0];
			heap->heapArr[0] = heap->heapArr[heap->size - 1];
			heap->size--;
			heap->last--;
			_reheapDown(heap, 0);
			return data;
		}
	}

	return 0;
}

void _reheapUp(HEAP* heap, int pos)
{
	int parent = (pos - 1) / 2;
	int temp = heap->heapArr[pos];
	while (pos > 0 && temp < heap->heapArr[parent])
	{
		heap->heapArr[pos] = heap->heapArr[parent];
		pos = parent;
		parent = (parent - 1) / 2;
	}
	heap->heapArr[pos] = temp;
}

void _reheapDown(HEAP* heap, int pos)
{
	int minChild;
	bool largerThanChild = true;
	int temp = heap->heapArr[pos];
	while (pos * 2 + 1 < heap->size && largerThanChild)
	{
		minChild = 2 * pos + 1;
		if (pos * 2 + 2 < heap->size && heap->heapArr[2 * pos + 1] > heap->heapArr[2 * pos + 2])
		{
			minChild++;
		}

		if (heap->heapArr[minChild] < temp)
		{
			heap->heapArr[pos] = heap->heapArr[minChild];
			pos = minChild;
		}
		else
		{
			largerThanChild = false;
		}
	}
	heap->heapArr[pos] = temp;
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
