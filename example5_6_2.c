/* �ǽ�5.6-2 1800����� 2012����� ������	���Ͽ� ��� */
#include <stdio.h>						// Standard Input Output Header
#define FIRST_YEAR 1800					// ������ ����
#define LAST_YEAR 2012					// ������ ��

void main() {
	int i, j = 0, num = 0;
	int year[LAST_YEAR - FIRST_YEAR];	// ������ ����

	printf("%d����� %d����� ���� ����Ʈ\n", FIRST_YEAR, LAST_YEAR);
	for (i = FIRST_YEAR; i <= LAST_YEAR; i++) {
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
			year[++j] = i;
		}								// ������ ����Ͽ� year�� ����
		num = j;
	}
	for (j = 1; j <= num; j++) {
		printf("%d	", year[j]);
		if (j % 10 == 0)
			printf("\n");
	}									// ������ ��� 10���� �ٹٲ�
	printf("\n");
}