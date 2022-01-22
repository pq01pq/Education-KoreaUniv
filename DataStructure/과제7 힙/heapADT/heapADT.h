#pragma once

#include <stdbool.h>

#define SIZE 255

typedef int element;

typedef struct {
	element *arry;
	int size;
} Heap;

Heap *heapCreate(int size); // create an empty heap

bool heapInsert(Heap *heap, element data);
void reHeapUp(Heap *heap, int index);

bool heapDelete(Heap *heap, element *dataOut); // delete the root of the given heap
void reHeapDown(Heap *heap, int index);

int heapCount(Heap *heap); // return the number of
bool heapFull(Heap *heap); // return true if the heap is full
bool heapEmpty(Heap *heap); // return true if the heap is empty
Heap *heapDestroy(Heap *heap); // delete all elements of the heap and free heap

void printHeapArray(Heap *heap);