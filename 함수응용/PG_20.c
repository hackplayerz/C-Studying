/* 2017-11-22 함수를 사용하여 팩토리얼(N!)의 값을 구하는 프로그램 */
#include <stdio.h>
long factorial(int number);		// 팩토리얼을 계산하는 함수

void main()
{
	int i;

	for (i = 1; i <= 10; i++)
		printf("%2d! = %ld\n", i, factorial(i));
}

long factorial(int number)
{
	if (number <= 1)
		return 1;
	else
		return (number * factorial(number - 1));
}
