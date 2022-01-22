#include <stdio.h>
#include "heapADT.h"



void main(void)
{
	Heap *heap = heapCreate(SIZE);

	int insertData[] = { 10, 50, 30, 80, 50, 20, 70, 40, 90, 60, 40 };

	for (int i = 0; i < sizeof(insertData) / sizeof(int); i++)
	{
		if (!heapFull(heap))
		{
			if (heapInsert(heap, insertData[i]))
			{
				printf("Insertion succeed. Input data : %d,  ", insertData[i]);
			}
			else
			{
				printf("Insertion failed.  Input data : %d,  ", insertData[i]);
			}
		}
		else
		{
			printf("Heap is full. Data : %d, ", insertData[i]);
		}
		printf("heap size : %d\n", heapCount(heap));
		printHeapArray(heap);
	}
	printf("\n");
	
	int dataOut;
	for (int i = 0; i < sizeof(insertData) / sizeof(int) / 2; i++)
	{
		if(!heapEmpty(heap))
		{
			if (heapDelete(heap, &dataOut))
			{
				printf("Deletion succeed.  Output data : %d, ", dataOut);
			}
			else
			{
				printf("Deletion failed.   Output data : %d, ", dataOut);
			}
			printf("heap size : %d\n", heapCount(heap));
			printHeapArray(heap);
		}
	}
	printf("\n");

	heap = heapDestroy(heap);

	return;
}