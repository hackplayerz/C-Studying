/* 2017-11-02 논리 연산자의 활용 프로그램 */
#include <stdio.h>

void main()
{
	//관계연산자 사용(==(same), !=(eq_not), <(under), >(over), <=(eq_under), >=(eq_over))
	int x = 1;
	int y = 2;
	int z = 3;

	if (x == y)
		printf("x는 y와 같습니다. \n");
	if (x != y)
		printf("x는 y와 같지 않습니다. \n");
	if (x > y)
		printf("x는 y보다 큽니다. \n");
	if (x < y)
		printf("x는 y보다 작습니다. \n");
	if (x <= y)
		printf("x는 y보다 작거나 같습니다. \n");
	if (x >= y)
		printf("x는 y보다 크거나 같습니다. \n");

	//논리 연산자 사용(&&(and), ||(or), !(not))
	x = 5;
	y = 2;

	if (x > 0 && x < 10)
		printf("0 < x < 10\n");

	if (x < 0 || y == 2)
		printf("x가 0보다 작거나, y는 2입니다. \n");

	if (!(x>y))
		printf("x가 y보다 크지 않습니다. \n");
}