#include <iostream>
#include <chrono>

using namespace std;

#define N 10000
#define MAX_VALUE 1000

void runSearch(void* pList, const size_t size, const int target, int* pLoc, bool(*searchFunc)(void*, const size_t, const int, int*))
{
	chrono::system_clock::time_point beginTime = chrono::system_clock::now();
	bool result = searchFunc(pList, size, target, pLoc);
	chrono::system_clock::time_point endTime = chrono::system_clock::now();

	chrono::duration<double> duringTime = endTime - beginTime;

	printf("Execution time: %.10f ms\n", duringTime.count() * 10e3);
	if (result)
		printf("Found %d at %d\n", target, *pLoc);
	else
		printf("Cannot found %d\n", target);
}

bool seqSearch(void* pList, const size_t size, const int target, int* pLoc)
{
	unsigned int i = 0;
	int* arr = (int*)pList;
	while (i < size && arr[i] != target)
	{
		i++;
	}
	*pLoc = i;

	return (arr[i] == target);
}

#define NUM_BUCKETS 100
#define UNIT_BUCKET 100

int hashKey(int value)
{
	return value % NUM_BUCKETS;
}

typedef struct hashBucket
{
	int* values;	// Values
	int* locs;		// Original indies
	int max;		// Max bucket size
	int size;		// Current # of elements
	hashBucket* next;
}HASH_BUCKET;

HASH_BUCKET* buildBucket()
{
	HASH_BUCKET* bucket = (HASH_BUCKET*)malloc(sizeof(HASH_BUCKET));
	bucket->values = (int*)malloc(sizeof(int) * UNIT_BUCKET);
	bucket->locs = (int*)malloc(sizeof(int) * UNIT_BUCKET);
	bucket->max = UNIT_BUCKET;
	bucket->size = 0;
	bucket->next = NULL;

	return bucket;
}

void buildHash(void* pList, size_t listSize, void* pHash, size_t* hashSize)
{
	HASH_BUCKET**buckets = (HASH_BUCKET**)pHash;

	for (unsigned int i = 0; i < listSize; i++)
	{
		int key = hashKey(((int*)pList)[i]);
		HASH_BUCKET* bucket = buckets[key];
		if (bucket == NULL)
		{
			bucket = buckets[key] = buildBucket();
		}

		while (bucket->size == bucket->max)
		{
			if (bucket->next == NULL)
			{
				bucket->next = buildBucket();
			}
			bucket = bucket->next;
		}

		bucket->values[bucket->size] = ((int*)pList)[i];
		bucket->locs[bucket->size++] = i;
	}
}

bool hashSearch(void* pHash, const size_t size, const int target, int* pLoc)
{
	int key = hashKey(target);
	HASH_BUCKET* bucket = ((HASH_BUCKET**)pHash)[key];

	while(bucket != NULL)
	{
		for (int i = 0; i < bucket->size; i++)
		{
			if (bucket->values[i] == target)
			{
				*pLoc = bucket->locs[i];
				return true;
			}
		}

		bucket = bucket->next;
	} 
	
	return false;
}

void deleteBucket(HASH_BUCKET* bucket)
{
	if (bucket->next)
	{
		deleteBucket(bucket->next);
	}
	free(bucket->values);
	free(bucket->locs);
	free(bucket);
}

void deleteHash(void* pHash, const size_t size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		HASH_BUCKET* bucket = ((HASH_BUCKET**)pHash)[i];
		if (bucket != NULL)
		{
			deleteBucket(bucket);
		}
	}
}

int getRand()
{
	return rand() % MAX_VALUE;
}

int main()
{
	static int arr[N] = { 0 };

	srand(2019);
	for (int i = 0; i < N; i++)
	{
		arr[i] = getRand();
	}

	int target = getRand();
	int loc = -1;

	size_t hashSize = 0;
	HASH_BUCKET* pHash[NUM_BUCKETS] = { 0, };
	buildHash(arr, N, (void*)pHash, &hashSize);

	runSearch(arr, N, target, &loc, seqSearch);

	runSearch(pHash, hashSize, target, &loc, hashSearch);

	deleteHash(pHash, hashSize);

	return 0;
}