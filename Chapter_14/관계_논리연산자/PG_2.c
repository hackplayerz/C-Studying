/* 2017-11-02 �� �������� Ȱ�� ���α׷� */
#include <stdio.h>

void main()
{
	//���迬���� ���(==(same), !=(eq_not), <(under), >(over), <=(eq_under), >=(eq_over))
	int x = 1;
	int y = 2;
	int z = 3;

	if (x == y)
		printf("x�� y�� �����ϴ�. \n");
	if (x != y)
		printf("x�� y�� ���� �ʽ��ϴ�. \n");
	if (x > y)
		printf("x�� y���� Ů�ϴ�. \n");
	if (x < y)
		printf("x�� y���� �۽��ϴ�. \n");
	if (x <= y)
		printf("x�� y���� �۰ų� �����ϴ�. \n");
	if (x >= y)
		printf("x�� y���� ũ�ų� �����ϴ�. \n");

	//�� ������ ���(&&(and), ||(or), !(not))
	x = 5;
	y = 2;

	if (x > 0 && x < 10)
		printf("0 < x < 10\n");

	if (x < 0 || y == 2)
		printf("x�� 0���� �۰ų�, y�� 2�Դϴ�. \n");

	if (!(x>y))
		printf("x�� y���� ũ�� �ʽ��ϴ�. \n");
}