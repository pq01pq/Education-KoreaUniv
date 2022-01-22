#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

long long fibTail(int n, long long f1, long long f2, int max)
{
	long long f3 = 0;

	if (n > 2)
	{
		printf("%d : %I64d\n", max - n + 1, f1);
		f3 = f2 + f1;
		return fibTail(n - 1, f2, f3, max);
	}
	else if (n == 2) {
		printf("%d : %I64d\n", max - n + 1, f1);
		printf("%d : %I64d\n", max - n + 2, f2);
		return f2;
	}
	else if (n == 1) {
		printf("1 : %I64d\n", f1);
		return f1;
	}
}

void main(void)
{
	long long f1 = 0, f2 = 1;
	int n;

	printf("알고싶은 피보나치 수열의 항 : ");
	scanf("%d", &n);

	int max = n;
	fibTail(n, f1, f2, max);
}