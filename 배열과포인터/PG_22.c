/* 2017-11-30 �������� ����� ũ�� */
#include <stdio.h>

void main() {
	char a = 'A';
	int b = 10;
	float c = 34.5;
	double d = 1234.5678;

	char *p;
	int *q;
	float *r;
	double *z;
	p = &a;
	q = &b;
	r = &c;
	z = &d;


	printf("\n==== �� �Ϲ� ������ ũ�� ==== \n\n");
	printf(" a(char)=%dbyte, b(int)= %dbyte, c(folat)=%dbyte, d(double)=%dbyte\n", sizeof(a), sizeof(b),sizeof(c), sizeof(d));

	printf("\n\n==== �� ������ ������ ũ�� ==== \n\n");
	printf(" p(char)=%dbyte, q(int)= %dbyte, r(folat)=%dbyte, z(double)=%dbyte\n", sizeof(p), sizeof(q),sizeof(r), sizeof(z));

	printf("\n\n==== �� �Ϲ� ������ ����� �� ==== \n\n");
	printf(" a(char)=%c, b(int)= %d, c(folat)=%f, d(double)=%f\n", a, b, c, d);

	printf("\n\n==== �� �Ϲ� ������ �ּ� �� ==== \n\n");
	printf(" a(char)=%d, b(int)= %d, c(folat)=%d, d(double)=%d\n", &a, &b, &c, &d);

	printf("\n\n==== �� ������ ������ ����� �� ==== \n\n");
	printf(" p(char)=%d, q(int)= %d, r(folat)=%d, z(double)=%d\n\n", p, q, r, z);
}