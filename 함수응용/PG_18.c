/* 2017-11-22 ���������� ���������� ���� */
#include <stdio.h>

void aut() {
	int x = 0;
	x += 2;
	printf("x = %d\n", x);
}
void stat() {
	static int x = 0;
	x = x + 2;
	printf("x = %d\n", x);
}
void main()
{
	printf("===== auto variable =====\n");
	aut();	aut();	aut();			// ���������� ����� �Լ��� ȣ�� : ���� �ʱ�ȭ�Ǿ� ���Ӱ� ���
	printf("===== static variable =====\n");
	stat();	stat();	stat();			// ���������� ����� �Լ��� ȣ�� : ���� �����Ǿ� ���
}