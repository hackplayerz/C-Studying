/* 2017-10-12 �ǽ����� 1 ȭ�� ���� */
#include <stdio.h>

void main() {
	int F;
	int C = 0;

	for (F = 212; F >= 32; F--) {
		printf("%d F�϶� %.2fC�̴�.\t", F, (5.0 / 9.0)*(F - 32));
		if (C <= 100) {
			printf("%d C�϶� %.2f F�̴�.\n", C, (9.0 / 5.0)*C + 32);
		}
		else
			printf("\n");
		C++;
	}
}