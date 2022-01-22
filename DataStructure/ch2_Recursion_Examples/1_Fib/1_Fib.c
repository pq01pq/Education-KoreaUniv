#include <stdio.h>

int fibLoop(int n);
int fib(int n);

int main()
{
    int n = 10;

    printf("Loop :\n");
    printf("------------------------------\n");
    for (int i = 1; i < n; i++) 
    {
        printf("%d : %d\n", i, fib(i));
    }

    printf("Recursion:\n");
    printf("------------------------------\n");
    for (int i = 1; i < n; i++) 
    {
        printf("%d : %d\n", i, fib(i));
    }

    return 0;
}

int fibLoop(int n) 
{
    int first = 1, second = 1, next;

    for (int i = 1; i < n; i++)
    {
        if (i <= 1)
            next = first;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
    }

    return next;
}

int fib(int n) 
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}