#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(0));             /* ���� �߻��� �ʱ�ȭ */

	int num = rand() % 100 + 1; /* num�ȿ� 1~100���� ���� ���ڰ� �� */
	int i, x;

	printf("1 ���� 100 ������ �ڿ��� �߿� ��ǻ�Ͱ� ������ ���� � ������ �������ÿ�.\n");
	printf("�� 10���� ��ȸ�� �־����ϴ�.\n\n");
	printf("���� �Է��Ͻÿ�. : ");

	for (i = 0; i < 10; ++i) {

		scanf("%d", &x);
		printf("\n");

		if (x < num) {
			if (i < 9) {
				printf("������ �ƴմϴ�. %d���� ��ȸ�� ���ҽ��ϴ�.\n", 9 - i);
				printf("�� ū ���� �Է��Ͻÿ�. : ");
			}
			else {
				printf("����� �й��Դϴ�.\n");
				printf("������ %d �Դϴ�.\n", num);
				return 0;
			}
		}
		else if (x > num) {
			if (i < 9) {
				printf("������ �ƴմϴ�. %d���� ��ȸ�� ���ҽ��ϴ�.\n", 9 - i);
				printf("�� ���� ���� �Է��Ͻÿ�. : ");
			}
			else {
				printf("����� �й��Դϴ�.\n");
				printf("������ %d �Դϴ�.\n", num);
				return 0;
			}
		}
		else {
			printf("����� �¸��Դϴ�.\n");
			printf("������ %d �Դϴ�.\n", num);
			return 0;
		}
	}
}