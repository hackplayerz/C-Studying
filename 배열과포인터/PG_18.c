/* 2017-12-07 �Լ������͸� �̿��� �Լ� ȣ�� ���� */
#include <stdio.h>

void plus(int, int);
void minus(int, int);
void multiply(int, int);

void main(void)
{
	int a = 10, b = 5, i;

	void(*result[])(int, int) = { plus, minus, multiply };
	//�Լ� ������ �迭 ���� 

	for (i = 0; i<3; i++) {
		printf("%d �� �Լ��� �����ּ� : %d\n", i, result[i]);
		result[i](a, b);
		printf("\n");
	}
}

void plus(int a, int b)
{
	printf("%d + %d = %d\n", a, b, a + b);
}

void minus(int a, int b)
{
	printf("%d - %d = %d\n", a, b, a - b);
}

void multiply(int a, int b)
{
	printf("%d * %d = %d\n", a, b, a*b);
}
