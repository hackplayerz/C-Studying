/* 2017-11-23 ���������� ���� ����ϴ� ���α׷��� ����Լ��� ���� ���α׷� */
#include <stdio.h>
int arithmetic(int a, int d, int n);

void main() {
	int a, d, n;	// a = �ʱⰪ, d = ����, n = ����

	printf("����(a)���Է��ϼ���: ");
	scanf("%d", &a);
	printf("����(d)���Է��ϼ���: ");
	scanf("%d", &d);
	printf("����(a)���Է��ϼ���: ");
	scanf("%d", &n);

	printf("Summation  result = %d\n ", arithmetic(a, d, n));
}

int arithmetic(int a, int d, int n) {		// �������� func
	int i, sum;
	if (n == 1) {
		return a;							// n�� �������Ǿ� ���� �޶����� error�� �̸� ����
	}

	i = a + (n - 1)*d;
	sum = arithmetic(a, d, n - 1) + i;		// ����Լ��� ����� ���������� ���� ����
	return sum;
}