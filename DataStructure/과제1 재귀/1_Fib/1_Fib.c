#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void fibLoop(int n, unsigned f1, unsigned f2)
{
	unsigned f3 = 0;

	printf("1 : %u\n", f1);
	printf("2 : %u\n", f2);

	for (int i = 2; i < n; i++) {
		printf("%d : %u\n", i + 1, f3 = f1 + f2);
		f1 = f2;
		f2 = f3;
	}

	return;
}

unsigned fib(int n, unsigned f1, unsigned f2, int print)
{
	int fib_n;

	if (n == 1)
		return f1;
	else if (n == 2) {
		if (print == 1) {
			printf("%d : %u\n", n - 1, f1);
			printf("%d : %u\n", n, f2);
		}
		return f2;
	}
	else
		fib_n = fib(n - 1, f1, f2, print) + fib(n - 2, f1, f2, print * 0);

	if (print == 1)
		printf("%d : %u\n", n, fib_n);

	return fib_n;
}

void main(void)
{
	unsigned f1 = 0, f2 = 1;
	int n;

	printf("알고싶은 피보나치 수열의 항 : ");
	scanf("%d", &n);

	switch (n)
	{
	case (0):
		printf("존재하지 않는 항입니다.\n");
		return;
	case (1):
		printf("1 : %u\n", f1);
		return;
	case (2):
		printf("1 : %u\n", f1);
		printf("2 : %u\n", f2);
		return;
	default:
		break;
	}

	if (n > 2)
	{
		fibLoop(n, f1, f2);

		printf("------------------------------\n");

		int print = 1;
		fib(n, f1, f2, print); //n = 50이면 컴퓨터가 고통을 호소한다.
	}

	return;
}