#include <stdio.h>
#include <assert.h>

int main(void)
{
	int i;
	int n1, n2;
	int max;
	int result;
	
	printf("두 수를 입력하세요 : ");
	scanf("%d %d", &n1, &n2);
	
	assert(n1 > 0);
	assert(n2 > 0);
	
	max = (n1 > n2) ? n1 : n2;
	
	for(i = max; ; i++) {
		if (i % n1 == 0 & i % n2 == 0) {
			result = i;
			break;
		}
	}
	
	printf ("%d와 %d의 최소공배수는 %d입니다.\n", n1, n2, result);
}