/* 2017-10-12 ���Կ����� */
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
		printf("intval[%d]�� ������ ����ִ� ���� %d�̴�.\n",i, intval[i]);

	}
	printf("floatval�� ������ ����ִ� ���� %.2f�̴�.\n", floatval);
}