#include <stdio.h>

void main()
{
	int i, j;
	
	for (j = 1; j <= 9; j++) {
		for (i = 2; i <= 9; i++)
			printf("%d * %d = %d\t", i, j, i * j);
		printf("\n");
	}
}