/* 2017-10-12 대입연산자 */
#include <stdio.h>
#define PI 3.14

void main() {
	int intval[7];
	float floatval;
	int i;
	intval[0] = 10;
	intval[1] = intval[0];
	floatval = PI;
	intval[2] = intval[0] + 20;
	intval[3] = sizeof(int);
	intval[4] = sizeof(int) * 2 + 7;
	intval[5] = intval[6] = 7;
	for (i = 0; i < 7; i++) {
		printf("intval[%d]의 공간에 들어있는 값은 %d이다.\n",i, intval[i]);

	}
	printf("floatval의 공간에 들어있는 값은 %.2f이다.\n", floatval);
}