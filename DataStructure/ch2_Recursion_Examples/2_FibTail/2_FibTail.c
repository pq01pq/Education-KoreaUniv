#include <stdio.h>

unsigned long long fib(int num, unsigned long long f1, unsigned long long f2);

int main(void)
{
    for(int i = 1; i < 60; i++)
    {
        printf("%d : %llu\n", i , fib(i, 1, 1));
    }
    return 0;
}

unsigned long long fib(int num, unsigned long long f1, unsigned long long f2)
{
    if(num <= 1)
        return f1;
    else if(num == 2)
        return f2;
    else
        return fib(num - 1, f2, f1 + f2);
}