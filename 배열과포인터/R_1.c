/* �ǽ����� 11.1 */
#include <stdio.h>

void main() {
	int array1[16], array2[4][4], array3[4][2][2];
	int i, j, k, sum, avg;
	int *parr;

	printf("1) �迭 �ʱⰪ�� ��ü ��, ��հ�\n");

	for (i = 0; i<16; i++)
		array1[i] = i + 1;

	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			array2[i][j] = i * 4 + j + 1;

	for (i = 0; i<4; i++)
		for (j = 0; j<2; j++)
			for (k = 0; k<2; k++)
				array3[i][j][k] = i * 4 + j * 2 + k + 1;
	printf("\n1���� �迭 ��� ���\n");
	sum = 0;
	for (i = 0; i<16; i++) {
		printf("%2d ", array1[i]);
		sum += array1[i];
	}avg = sum / 16;
	printf("\n��ü ��: %3d, ���: %2d\n", sum, avg);

	printf("\n\n2���� �迭 ��� ���\n");
	sum = 0;
	for (i = 0; i<4; i++) {
		for (j = 0; j<4; j++) {
			printf("%2d ", array2[i][j]);
			sum += array2[i][j];
		}
		puts("");
	}avg = sum / 16;
	printf("��ü ��: %3d, ���: %2d\n", sum, avg);
	printf("\n3���� �迭 ��� ���\n");
	sum = 0;
	for (i = 0; i<4; i++) {
		for (j = 0; j<2; j++) {
			for (k = 0; k<2; k++) {
				printf("%2d ", array3[i][j][k]);
				sum += array3[i][j][k];
			}
			puts("");
		}
		puts("");
	}avg = sum / 16;
	printf("��ü ��: %3d, ���: %2d\n", sum, avg);

	printf("\n\n2) 1���� �迭�� ���� ������ Ȱ��\n");
	parr = array1;
	sum = 0;
	for (i = 0; i<16; i++)
		sum += *(parr + i);
	avg = sum / 16;
	printf("��ü ��: %3d, ���: %2d\n\n", sum, avg);
}