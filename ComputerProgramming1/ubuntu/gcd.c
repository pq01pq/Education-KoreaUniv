#include <stdio.h>
#include <assert.h>

int main(void)
{
	int i;
	int n1, n2;
	int min;
	int result;
	
	printf("두 수를 입력하세요 : ");
	scanf("%d %d", &n1, &n2);
	
	assert(n1 > 0);
	assert(n2 > 0);
	
	min = (n1 < n2) ? n1 : n2;
	
	for(i = min; i >= 1; i--) {
		if (n1 % i == 0 & n2 % i == 0) {
			result = i;
			break;
		}
	}
	
	printf ("%d와 %d의 최대공약수는 %d입니다.\n", n1, n2, result);
}