#include <stdio.h>
#include <assert.h>

int lcm(int n1, int n2)
{
	int i;
	int max;
	
	max = (n1 > n2) ? n1 : n2;
	
	for(i = max; ; i++) {
		if (i % n1 == 0 & i % n2 == 0) {
			return i;
		}
	}
	
}

int main(void)
{
	int n1, n2;
	int result;
	
	printf("두 수를 입력하세요 : ");
	scanf("%d %d", &n1, &n2);
	
	assert(n1 > 0);
	assert(n2 > 0);
	
	result = lcm(n1, n2);
	
	printf ("%d와 %d의 최소공배수는 %d입니다.\n", n1, n2, result);
}