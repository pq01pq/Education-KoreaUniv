#include <stdio.h>
#include <stdlib.h>
#define	N	10

typedef int element;

void printArr(int arr[], const size_t size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void merge(int arr[], int low, int mid, int high)
{
	if (low < high)
	{
		element *temp = (element *)malloc((high - low + 1) * sizeof(element));
		int i = low, j = mid + 1;	// index in arr[]
		int k = 0;					// index in temp[]

		// compare data in both sorted lists
		while (i<= mid && j <= high)
		{
			if (arr[i] < arr[j])
			{
				temp[k] = arr[i];
				i++;
			}
			else
			{
				temp[k] = arr[j];
				j++;
			}
			k++;
		}

		// sweep all remaining data
		if (i <= mid)
		{
			while (i <= mid)
			{
				temp[k] = arr[i];
				i++;
				k++;
			}
		}
		else // j <= high
		{
			while (j <= high)
			{
				temp[k] = arr[j];
				j++;
				k++;
			}
		}

		// update data
		for (k = 0; k < high - low + 1; k++)
		{
			arr[low + k] = temp[k];
		}

		free(temp);
	}

	return;
}

void mergeSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}

	return;
}

int main()
{
	int values[N] = { 1,0,6,7,3, 9,6,6,2,8 };

	printArr(values, N);

	mergeSort(values, 0, N - 1);

	printArr(values, N);

	return 0;
}
