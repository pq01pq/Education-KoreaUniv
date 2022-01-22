#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "heapADT.h"

HEAP* heapCreate() 
{
	HEAP* heap = (HEAP*)malloc(sizeof(HEAP));

	if (!heap) return NULL;

	heap->size = 0;
	heap->capacity = HEAP_UNIT;
	heap->data = (int*)malloc(HEAP_UNIT * sizeof(int));

	return heap;
}

bool heapInsert(HEAP* heap, int val) 
{
	if (heapFull(heap))
	{
		int* oData = heap->data;
		int* nData = (int*)realloc(heap->data, sizeof(int) * (heap->capacity + HEAP_UNIT));

		if (!nData)
		{
			heap->data = oData;
			return false;
		}
	}

	heap->data[(heap->size)] = val;
	reheapUp(heap, (heap->size)++);

	return true;
}

int heapDelete(HEAP* heap) 
{
	if (heapEmpty(heap)) 
		return NULL;

	int root = heap->data[0];

	heap->data[0] = heap->data[--(heap->size)];
	reheapDown(heap, 0);

	return root;
}

int heapCount(HEAP* heap) 
{
	return heap->size;
}

bool heapFull(HEAP* heap) 
{
	return heap->size >= heap->capacity;
}

bool heapEmpty(HEAP* heap) 
{
	return heap->size == 0;
}

void heapDestroy(HEAP* heap) 
{
	free(heap->data);
	free(heap);
}

//additional functions

void heapTraverse(HEAP* heap) 
{
	for (int i = 0; i < heap->size; i++) 
	{
		printf("%d ", heap->data[i]);
	}
	printf("\n");
}

void swap(int* left, int* right) 
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

void reheapUp(HEAP* heap, int pos) 
{
	if (pos == 0) return;

	if (heap->data[(pos - 1) / 2] < heap->data[pos]) 
	{
		swap(&heap->data[(pos - 1) / 2], &heap->data[pos]);
		reheapUp(heap, (pos - 1) / 2);
	}
}

void reheapDown(HEAP* heap, int pos) 
{
	static short left = 0, right = 1;
	bool hasChild[2] = { false, false };

	if (pos * 2 + 1 < heap->size && heap->data[pos * 2 + 1] > heap->data[pos])
	{
		hasChild[left] = true;
	}
		
	if (pos * 2 + 2 < heap->size && heap->data[pos * 2 + 2] > heap->data[pos])
	{
		hasChild[right] = true;
	}

	if (hasChild[left] && hasChild[right]) 
	{
		if (heap->data[pos * 2 + 1] > heap->data[pos * 2 + 2])
			hasChild[right] = false;
		else
			hasChild[left] = false;
	}

	if (hasChild[left]) 
	{
		swap(&heap->data[pos * 2 + 1], &heap->data[pos]);
		reheapDown(heap, pos * 2 + 1);
	}
	else if (hasChild[right]) 
	{
		swap(&heap->data[pos * 2 + 2], &heap->data[pos]);
		reheapDown(heap, pos * 2 + 2);
	}
}
