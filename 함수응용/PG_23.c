/* 2017-11-23 등차수열의 합을 계산하는 프로그램을 재귀함수로 만든 프로그램 */
#include <stdio.h>
int arithmetic(int a, int d, int n);

void main() {
	int a, d, n;	// a = 초기값, d = 공차, n = 차수

	printf("초항(a)을입력하세요: ");
	scanf("%d", &a);
	printf("공차(d)을입력하세요: ");
	scanf("%d", &d);
	printf("차수(a)을입력하세요: ");
	scanf("%d", &n);

	printf("Summation  result = %d\n ", arithmetic(a, d, n));
}

int arithmetic(int a, int d, int n) {		// 등차수열 func
	int i, sum;
	if (n == 1) {
		return a;							// n이 음수가되어 값이 달라지는 error를 미리 제거
	}

	i = a + (n - 1)*d;
	sum = arithmetic(a, d, n - 1) + i;		// 재귀함수를 사용해 등차수열의 합을 구함
	return sum;
}