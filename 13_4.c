/* 2017-10-12 ½Ç½À¿¡Á¦ 1 È­¾¾ ¼·¾¾ */
#include <stdio.h>

void main() {
	int F = 0;
	float C = 100.0;
	int i;
	for (i = 100; i >= 0; i--) {
		F = (9.0 / 5.0)*C + 32;
		printf("%-3d¨¬F ÀÏ¶§ %-3.2f¨¬CÀÌ´Ù.\n", F, C);
		--C;
	}
}