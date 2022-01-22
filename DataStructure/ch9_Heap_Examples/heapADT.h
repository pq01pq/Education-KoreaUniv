#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define HEAP_UNIT 100

typedef struct heap {
	int* data;
	int size;
	int capacity;
} HEAP;

HEAP* heapCreate();
bool heapInsert(HEAP* heap, int val);
int heapDelete(HEAP* heap);
int heapCount(HEAP* heap);
bool heapFull(HEAP* heap);
bool heapEmpty(HEAP* heap);
void heapDestroy(HEAP* heap);

void heapTraverse(HEAP* heap);
void swap(int* posA, int* posB);
void reheapUp(HEAP* heap, int pos);
void reheapDown(HEAP* heap, int pos);