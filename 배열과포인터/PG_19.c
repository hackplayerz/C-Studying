/* 2017-12-06 �����ͺ����� ���� */
#include <stdio.h> 
void main()
{
	int x = 10, y = 20;
	int *ptrx, *ptry;  // 2���� �����ͺ���ptrx, ptry ����
	ptrx = &x;          // ptrx���� x�Ǻ����� ��ġ������ ����
	ptry = &y;          // ptry���� y�Ǻ����� ��ġ������ ����

	printf("x�ǹ���(&x) = %d   y�ǹ���(&y) = %d \n", &x, &y);
	printf("ptrx        = %d   ptry        = %d \n\n", ptrx, ptry);

	printf("x�ǰ�       = %d    y�ǰ�           = %d \n", x, y);     // ���� x�� y��  ����  ���������ؼ� ����
	printf("*ptrx       = %d   *ptry            = %d \n\n", *ptrx, *ptry);  // ���� x�� y��  ���� �����ͺ��� ptrx, ptry�� �̿��Ͽ�  ����(��ȸ)�����ؼ� ���� 
}