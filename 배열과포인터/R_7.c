/* 실습예제11.6 */
#include <stdio.h>

// void PascalTriangle(int a[10][10]);
void PascalTriangle(int(*p)[10]);

main() {
	int pascal[10][10];
	int i, j;

	PascalTriangle(pascal);

	for (i = 0; i<10; i++) {
		for (j = 0; j <= i; j++)
			printf("%d ", pascal[i][j]);
		puts("");
	}
}
// 포인터 배열 사용 프로그램
void PascalTriangle(int(*p)[10]) {
	int i, j;
	for (i = 0; i<10; i++)
		for (j = 0; j <= i; j++)
			if (!j || i == j) *(*(p + i) + j) = 1;
			else *(*(p + i) + j) = *(*(p + i - 1) + j - 1) + *(*(p + i - 1) + j);
}