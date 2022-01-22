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

#define DEBUG 0

#define N 10000
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
	int *arr = (int *)pList;
	while (i < size && arr[i] != target)
	{
		i++;
	}
	*pLoc = i;

	return (arr[i] == target);
}

int getRand()
{
	return rand() % MAX_VALUE;	// 0 ~ 9999 까지 랜덤 리턴
}

static void buildHash(void* pList, size_t listSize, void* pHash, size_t* hashSize)
{
	int *arry = (int *)pList;
	int *hash = (int *)pHash;
	
	// hash 주소를 기준으로 hash + arry[i]의 주소에 arry[i] 값을 저장
	// arry[i]값 자체를 상대지정주소 index로 사용
	// direct mapping
	for (unsigned int i = 0; i < listSize; i++)
	{
		if (hash[arry[i]] != arry[i])
		{
			hash[arry[i]] = arry[i];
		}
	}
	*hashSize = MAX_VALUE;
}

bool hashSearch(void* pHash, const size_t size, const int target, int* pLoc)
{
	int *hash = (int *)pHash;
	if (hash[target] == target)
	{
		*pLoc = target;
		return true;
	}
	else
	{
		*pLoc = size;
		return false;
	}
}

void deleteHash(void* pHash, const size_t size)
{
	int *hash = (int *)pHash;
	for (unsigned int i = 0; i < size; i++)
	{
		if (hash[i] == i)
		{
			hash[i] = -1;
		}
	}
}

void printHash(void *pHash, const size_t size)
{
	int *hash = (int *)pHash;
	for (unsigned int i = 0; i < size; i++)
	{
		if (hash[i] == i)
		{
			printf("%6d ", hash[i]);
		}
		else
		{
			printf("  ---- ");
		}

		if (i % 10 == 9)
		{
			printf("\n");
		}
	}
}

int main()
{
	static int arr[N] = { 0 };
	srand(2019);
	for (int i = 0; i < N; i++)
	{
		arr[i] = getRand();
	}

	//int target = arr[0];
	int target = getRand();	// 검색할 수
	int loc = -1;

	int pHash[MAX_VALUE];
	for (int i = 0; i < MAX_VALUE; i++)
	{
		pHash[i] = -1;
	}
	size_t hashSize = 0;
	// Make pHash
	buildHash(arr, N, (void*)pHash, &hashSize);

	printHash(pHash, hashSize);

	runSearch(arr, N, target, &loc, seqSearch);				// 배열에서 검색

	runSearch(pHash, hashSize, target, &loc, hashSearch);	// 해시에서 검색

	deleteHash(pHash, hashSize);
#if DEBUG
	printHash(pHash, hashSize);
#endif
	return 0;
}