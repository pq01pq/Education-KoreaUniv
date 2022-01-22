#include <stdio.h>
#include "heapADT.h"

int main()
{
	HEAP* heap = heapCreate();
	int val[] = { 100, 55, 234, 452, 10 };

	for (int i = 0; i < sizeof(val) / sizeof(int); i++)
	{
		if (!heapInsert(heap, val[i]))
		{
			printf("Error while inserting %d\n", val[i]);
		}

		heapTraverse(heap);
	}

	for (int i = 0; i < sizeof(val) / sizeof(int); i++)
	{
		heapDelete(heap);
		heapTraverse(heap);
	}

	heapDestroy(heap);

	return 0;

}