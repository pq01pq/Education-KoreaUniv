#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void)
{
	srand(time(0));
	
	int rand();
	int s[100];
	int i;
	int sum = 0;
	long double ave, dev = 0, var, sd;

	for (i = 0; i < 100; i++)
	{
		s[i] = rand();
		printf("s[%d] = %d ", i, s[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\n");

	for (i = 0; i < 100; i++)
		sum = sum + s[i];
	printf("sum = %d\n", sum);

	ave = sum / 100;
	printf("average = %Lf\n", ave);

	for (i = 0; i < 100; i++)
		dev = dev + pow(s[i] - ave, 2);
	var = dev / 100;
	printf("variance = %Lf\n", var);

	printf("standard deviation = %Lf\n", var / 100);

	return 0;
}