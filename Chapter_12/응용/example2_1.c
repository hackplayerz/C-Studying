/* 2017-09-27 Scanf()�� �̿��� Ȱ�뿹�� -�ͺ��Լ��� ������ Case */
#include <stdio.h>					// Standard Input Output Header

float triangle(int a, int b);		// �ﰢ���� ���̸� ���ϴ� �Լ�
float rectangle(int a, int b);		// �簢���� ���̸� ���ϴ� �Լ�
float f_round(int a);				// ���� ���̸� ���ϴ� �Լ�

int main(void) {
	/* �� �غ�, ����, ���� �������� ������ ������ ���� ���� */
	int t_under = 0;				
	int t_high = 0;
	int r_under = 0;
	int r_high = 0;
	int round = 0;

	printf("�ﰢ���� �غ��� ���̸� �Է��ϼ��� :");
	scanf("%d %d", &t_under, &t_high);
	/* ����ڷκ��� ���� �޾ƿ� ���� ũ�⸦ ������ ���� */ 
	printf("\n�簢���� �غ��� ���̸� �Է��ϼ��� :");
	scanf("%d %d", &r_under, &r_high);

	printf("\n���� �������� �Է��ϼ��� :");
	scanf("%d", &round);
	
	printf("�ﰢ���� ���̴� %.3f�Դϴ�.\n", triangle(t_under, t_high));
	printf("�簢���� ���̴� %.3f�Դϴ�.\n", rectangle(r_under, r_high));
	printf("���� ���̴� %.3f�Դϴ�.\n",f_round(round));
	/* ����ڷκ��� �޾ƿ� ���� ����Ͽ� �ﰢ��, �簢��, ���� ���̸� ��� */
}
	/* �Լ����� ���̸� ����� �Ǽ������� Return */
float triangle(int a, int b) {
	float x;
	x = (a*b) / 2;					
	return x;
}
float rectangle(int a, int b) {
	float x;
	x = a*b;
	return x;
}
float f_round(int a) {
	float x;
	x = a*a*3.14;
	return x;
}