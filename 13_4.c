/* 2017-10-12 실습에제 1 화씨 섭씨 */
#include <stdio.h>

void main() {
	int F;
	int C = 0;

	for (F = 212; F >= 32; F--) {
		printf("%d F일때 %.2fC이다.\t", F, (5.0 / 9.0)*(F - 32));
		if (C <= 100) {
			printf("%d C일때 %.2f F이다.\n", C, (9.0 / 5.0)*C + 32);
		}
		else
			printf("\n");
		C++;
	}
}