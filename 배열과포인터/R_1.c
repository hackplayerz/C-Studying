/* 실습예제 11.1 */
#include <stdio.h>

void main() {
	int array1[16], array2[4][4], array3[4][2][2];
	int i, j, k, sum, avg;
	int *parr;

	printf("1) 배열 초기값과 전체 합, 평균값\n");

	for (i = 0; i<16; i++)
		array1[i] = i + 1;

	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			array2[i][j] = i * 4 + j + 1;

	for (i = 0; i<4; i++)
		for (j = 0; j<2; j++)
			for (k = 0; k<2; k++)
				array3[i][j][k] = i * 4 + j * 2 + k + 1;
	printf("\n1차원 배열 결과 출력\n");
	sum = 0;
	for (i = 0; i<16; i++) {
		printf("%2d ", array1[i]);
		sum += array1[i];
	}avg = sum / 16;
	printf("\n전체 합: %3d, 평균: %2d\n", sum, avg);

	printf("\n\n2차원 배열 결과 출력\n");
	sum = 0;
	for (i = 0; i<4; i++) {
		for (j = 0; j<4; j++) {
			printf("%2d ", array2[i][j]);
			sum += array2[i][j];
		}
		puts("");
	}avg = sum / 16;
	printf("전체 합: %3d, 평균: %2d\n", sum, avg);
	printf("\n3차원 배열 결과 출력\n");
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
	printf("전체 합: %3d, 평균: %2d\n", sum, avg);

	printf("\n\n2) 1차원 배열에 대한 포인터 활용\n");
	parr = array1;
	sum = 0;
	for (i = 0; i<16; i++)
		sum += *(parr + i);
	avg = sum / 16;
	printf("전체 합: %3d, 평균: %2d\n\n", sum, avg);
}