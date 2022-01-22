#include <stdio.h>
#include <stdlib.h>
#define	N	10

void printArr(int arr[], const size_t size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void merge(int arr[], int low, int mid, int high)
{
	// merge body
}

void mergeSort(int arr[], int low, int high)
{
	// merge sort body
}

int main()
{
	int values[N] = { 1,0,6,7,3, 9,6,6,2,8 };

	printArr(values, N);

	mergeSort(values, 0, N - 1);

	printArr(values, N);

	return 0;
}
