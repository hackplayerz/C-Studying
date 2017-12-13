/* 2017-12-07 2차원배열을 이용한 전치행렬 */
#include <stdio.h>
void main() {
	int i, j, matrix[5][5] = { { 5,7,3,9,2 },{ 5,2,4,5,2 },{ 2,7,8,3,1 },{ 6,5,8,4,7 },{ 7,5,6,3,8 } };

	int nCount = sizeof(matrix) / sizeof(matrix[0]);

	printf("원래의 행렬\n\n");
	for (i = 0; i < nCount; i++) {
		for (j = 0; j < nCount; j++)
			printf(" %d ", matrix[i][j]);
		printf("\n");
	}
		printf("\n");

		// 전치행렬로 변환하는 과정
		for (i = 0; i< nCount; i++) {
			for (j = 0; j<i; j++) { // 두 개의 데이터를 맞교환
				matrix[i][j] ^= matrix[j][i];		// ^= : XOR 
				matrix[j][i] ^= matrix[i][j];
				matrix[i][j] ^= matrix[j][i];
			}
		}

		printf("전치 행렬\n\n");
		for (i = 0; i< nCount; i++) {
			for (j = 0; j< nCount; j++)
				printf(" %d ", matrix[i][j]);
			printf("\n");
		}

		printf("\n\n");
}