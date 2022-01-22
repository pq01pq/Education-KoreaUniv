#include <stdio.h>
#include <stdbool.h>

#define STR_LENGTH 100

int stringLength(char* a);
bool palindrome(char a[], int x, int y);

int main()
{
    char str[STR_LENGTH];
    int length, result;

    gets(str);
    if (palindrome(str, 0, stringLength(str) - 1))
        printf("The string is palindrome.\n");
    else
        printf("The string is not palindrome.\n");
	
	return 0;
}

int stringLength(char* a)
{
	if (*a == '\0')
		return 0;
	else
		return 1 + stringLength(a + 1);
}

bool palindrome(char a[], int x, int y)
{
	if (x >= y)
		return true;
	else if (a[x] == a[y] && palindrome(a, x + 1, y - 1))
		return true;
	else
		return false;
}