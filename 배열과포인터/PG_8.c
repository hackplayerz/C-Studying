/* 2017-12-07 2�����迭�� �̿��� ��ġ��� */
#include <stdio.h>
void main() {
	int i, j, matrix[5][5] = { { 5,7,3,9,2 },{ 5,2,4,5,2 },{ 2,7,8,3,1 },{ 6,5,8,4,7 },{ 7,5,6,3,8 } };

	int nCount = sizeof(matrix) / sizeof(matrix[0]);

	printf("������ ���\n\n");
	for (i = 0; i < nCount; i++) {
		for (j = 0; j < nCount; j++)
			printf(" %d ", matrix[i][j]);
		printf("\n");
	}
		printf("\n");

		// ��ġ��ķ� ��ȯ�ϴ� ����
		for (i = 0; i< nCount; i++) {
			for (j = 0; j<i; j++) { // �� ���� �����͸� �±�ȯ
				matrix[i][j] ^= matrix[j][i];		// ^= : XOR 
				matrix[j][i] ^= matrix[i][j];
				matrix[i][j] ^= matrix[j][i];
			}
		}

		printf("��ġ ���\n\n");
		for (i = 0; i< nCount; i++) {
			for (j = 0; j< nCount; j++)
				printf(" %d ", matrix[i][j]);
			printf("\n");
		}

		printf("\n\n");
}