/* 2017-11-23 재귀호출 답 */
#include <stdio.h>

int sigma(int a, int b, int n);

void main() {
	int a, b, n;
	printf("입력 : a, b, n :");
	scanf("%d %d %d", &a, &b, &n);
	printf("\nResult : %d\n", sigma(a, b, n));
}
int sigma(int a, int b, int n) {
	if (n == 1) {
		return a;
	}
	else
		return a + (n - 1)*b + sigma(a, b, n - 1);
}