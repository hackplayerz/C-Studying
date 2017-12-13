/* 2017-12-07 함수포인터를 이용한 함수 호출 제어 */
#include <stdio.h>

void plus(int, int);
void minus(int, int);
void multiply(int, int);

void main(void)
{
	int a = 10, b = 5, i;

	void(*result[])(int, int) = { plus, minus, multiply };
	//함수 포인터 배열 선언 

	for (i = 0; i<3; i++) {
		printf("%d 번 함수의 시작주소 : %d\n", i, result[i]);
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
