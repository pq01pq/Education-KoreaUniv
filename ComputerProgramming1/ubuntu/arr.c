#include <stdio.h>
#include <stdlib.h>

#define N 10

float dev(int arr[], int n)
{
	int i;
	int a = 0;
	int *p;
	float aver;
	
	p = arr;
	
	for (i = 0; i < n; i++)
	{
		sum += *p;
	}
	aver = (float) sum / n;
	
	for (i = 0; i < n; i++)
	{
		dev += (arr[i] - aver) * (arr[i] - aver);
	}
	dev /= n;
	
	return dev;
}


void main(void)
{
	int arr[N];
	float result = 0;
	int i;
	
	for(i = 0; i < N; i++)
	{
		arr[i] = rand() % 100 + 1;
		printf("arr[%d] = %d ", i, arr[i]);
	}
	printf("\n");
	
	result = dev(arr, N);
	
	printf("dev = %f\n", result);
}