#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heapADT.h"

Heap *heapCreate(int size) // create an empty heap
{
	Heap *heap = (Heap *)malloc(sizeof(Heap));

	if (heap)
	{
		heap->arry = (element *)malloc(size * sizeof(element));
		if (heap->arry)
		{
			int index;
			for (index = 0; index < size; index++)
			{
				heap->arry[index] = (element)NULL;
			}
			heap->size = 0;
		}
		else
		{
			printf("Heap array memory allocation failed.\n");
		}
	}
	else
	{
		printf("Heap memory allocation failed.\n");
	}

	return heap;
}

bool heapInsert(Heap *heap, element data)
{
	if (!heap)
	{
		printf("Heap does not exist\n");
		return false;
	}

	if (heap->size >= SIZE)
	{
		printf("Heap is full\n");
		return false;
	}

	heap->arry[heap->size] = data;
	heap->size++;
	reHeapUp(heap, heap->size - 1);
	return true;
}

void reHeapUp(Heap *heap, int index)
{
	if (index < 0)
		return;

	int parentIndex = (index - 1) / 2;
	element tempData = heap->arry[index];
	while (index > 0 && heap->arry[parentIndex] < tempData)
	{
		heap->arry[index] = heap->arry[parentIndex];
		index = parentIndex;
		parentIndex = (parentIndex - 1) / 2;
	}
	heap->arry[index] = tempData;

	return;
}

bool heapDelete(Heap *heap, element *dataOut) // delete the root of the given heap
{
	if (heap->size < 1)
	{
		printf("Heap is empty\n");
		return false;
	}

	*dataOut = heap->arry[0];
	heap->arry[0] = heap->arry[heap->size - 1];
	heap->arry[heap->size - 1] = (element)NULL;
	heap->size--;
	reHeapDown(heap, 0);
	return true;
}

void reHeapDown(Heap *heap, int index)
{
	if (heap->size < 1 && index < 0)
		return;

	element tempData = heap->arry[index];
	int maxChildIndex;
	bool smallerThanChild = true;

	while (2 * index + 1 < heap->size && smallerThanChild) // 왼쪽 자식이 존재할 경우
	{
		maxChildIndex = 2 * index + 1;
		if (2 * index + 2 < heap->size) // 오른쪽 자식도 존재할 경우
		{
			if (heap->arry[2 * index + 1] < heap->arry[2 * index + 2]) // 왼쪽 자식보다 오른쪽 자식이 더 클 경우
			{
				maxChildIndex++;
			}
		}
		
		if (heap->arry[maxChildIndex] > tempData) // 나(tempData)보다 자식이 더 클 경우
		{
			heap->arry[index] = heap->arry[maxChildIndex]; // 자식을 위로 올려줌
			index = maxChildIndex;
		}
		else // 나보다 자식이 작거나 같을 경우
		{
			smallerThanChild = false;
		}
	}
	heap->arry[index] = tempData;

	return;
}

int heapCount(Heap *heap) // return the number of
{
	if (!heap)
		return 0;

	return heap->size;
}

bool heapFull(Heap *heap) // return true if the heap is full
{
	if (!heap)
		return false;

	return (heap->size == SIZE);
}

bool heapEmpty(Heap *heap) // return true if the heap is empty
{
	if (!heap)
		return true;

	return (heap->size == 0);
}

Heap *heapDestroy(Heap *heap) // delete all elements of the heap and free heap
{
	if (heap)
	{
		int index;
		for (index = heap->size - 1; index >= 0; index--)
		{
			heap->arry[index] = (element)NULL;
			heap->size--;
		}
		free(heap);
	}

	return NULL;
}

void printHeapArray(Heap *heap)
{
	if (!heap)
		return;

	printf("Heap array[] : { ");
	for (int i = 0; i < heap->size; i++)
	{
		printf("%d", heap->arry[i]);
		if (i < heap->size - 1)
			printf(", ");
	}
	printf(" }\n");

	return;
}