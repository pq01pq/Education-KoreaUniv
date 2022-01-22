#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int intcmp(const void *x, const void *y)
{
	int *n1 = (int *)x;
	int *n2 = (int *)y;
	
	return (*n1 - *n2);
	//return (*n2 - *n1);
}

void print_array(int arr[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);

	printf("\n");
	
	return;
}

void main(void)
{
	int i;
	int arr[SIZE];

	srand(time(NULL));

	for (i = 0; i < SIZE; i++)
		arr[i] = rand() % 500 + 1;
	
	print_array(arr, i);
	
	qsort(arr, SIZE, sizeof(int), intcmp);
	
	print_array(arr, i);

	return;
}