#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int i, j;
	
	for(j = 2; j <= 1000; j++) {
		for(i = 2; i <= sqrt(j); i++) {
			if(j % i == 0)
				break;
		}
		if (i > sqrt(j))
			printf("%d는 소수입니다.\n", j);
	}
}