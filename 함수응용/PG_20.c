/* 2017-11-22 �Լ��� ����Ͽ� ���丮��(N!)�� ���� ���ϴ� ���α׷� */
#include <stdio.h>
long factorial(int number);		// ���丮���� ����ϴ� �Լ�

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
