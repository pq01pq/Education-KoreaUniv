#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashADT.h"

HASH_BUCKET* bucketCreate(size_t bucketSize)
{
	HASH_BUCKET* bucket = (HASH_BUCKET*)malloc(sizeof(HASH_BUCKET));
	if (!bucket) return NULL;

	bucket->max = bucketSize;
	bucket->size = 0;
	bucket->next = NULL;
	bucket->values = (int*)calloc(bucketSize, sizeof(int));

	return bucket;
}

HASH* hashCreate(size_t hashSize, size_t bucketSize, int(*hashKey)(int))
{
	// Write your code here.
}

void hashInsert(HASH* pHash, int* pList, size_t listSize)
{	
	// Write your code here.
}

void hashDelete(HASH* pHash)
{
	// Write your code here.
}

bool hashSearch(HASH* pHash, const int target)
{
	// Write your code here.
}
