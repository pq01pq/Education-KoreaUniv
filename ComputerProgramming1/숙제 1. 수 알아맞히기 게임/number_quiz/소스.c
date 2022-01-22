#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(0));             /* 난수 발생기 초기화 */

	int num = rand() % 100 + 1; /* num안에 1~100까지 중의 숫자가 들어감 */
	int i, x;

	printf("1 부터 100 사이의 자연수 중에 컴퓨터가 생각한 수가 어떤 수인지 맞혀보시오.\n");
	printf("총 10번의 기회가 주어집니다.\n\n");
	printf("수를 입력하시오. : ");

	for (i = 0; i < 10; ++i) {

		scanf("%d", &x);
		printf("\n");

		if (x < num) {
			if (i < 9) {
				printf("정답이 아닙니다. %d번의 기회가 남았습니다.\n", 9 - i);
				printf("더 큰 수를 입력하시오. : ");
			}
			else {
				printf("당신의 패배입니다.\n");
				printf("정답은 %d 입니다.\n", num);
				return 0;
			}
		}
		else if (x > num) {
			if (i < 9) {
				printf("정답이 아닙니다. %d번의 기회가 남았습니다.\n", 9 - i);
				printf("더 작은 수를 입력하시오. : ");
			}
			else {
				printf("당신의 패배입니다.\n");
				printf("정답은 %d 입니다.\n", num);
				return 0;
			}
		}
		else {
			printf("당신의 승리입니다.\n");
			printf("정답은 %d 입니다.\n", num);
			return 0;
		}
	}
}