#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef _MSC_VER
// Windows
#include <Windows.h>
#else
// Linux
#include <time.h>
#endif

#define N 1000000
#define MAX_VALUE 10000

void runSearch(void* pList, const size_t size, const int target, int* pLoc, bool (*searchFunc)(void*, const size_t, const int, int*))
{
	LARGE_INTEGER freq;
	LARGE_INTEGER beginTime;
	LARGE_INTEGER endTime;

	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&beginTime);
	bool result = searchFunc(pList, size, target, pLoc);
	QueryPerformanceCounter(&endTime);

	double duringTime = (double)(endTime.QuadPart - beginTime.QuadPart) / (double)freq.QuadPart;

	printf("Execution time: %.10lf ms\n", duringTime * 10e3);
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

int getRand()
{
	return rand() % MAX_VALUE;
}

void buildHash(void* pList, size_t listSize, void* pHash, size_t* hashSize)
{
	// buildHash body
}

bool hashSearch(void* pHash, const size_t size, const int target, int* pLoc)
{
	// hashSearch body
}

void deleteHash(void* pHash, const size_t size)
{
	// deleteHash body
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
	// Make pHash
	buildHash(arr, N, (void*)pHash, &hashSize);

	runSearch(arr, N, target, &loc, seqSearch);

	runSearch(pHash, hashSize, target, &loc, hashSearch);

	deleteHash(pHash, hashSize);

	return 0;
}