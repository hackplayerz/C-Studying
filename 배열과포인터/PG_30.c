/* 2017-12-06 ���� ���� ������ �̷�� ���� �� ������ ������ �ּҿ� �� */
#include <stdio.h>
void lineplot(void);		// �ٳ������Լ�

void main() {
	int a = 100;
	int *p1;
	int **p2;
	int ***p3;

	printf("\t\t\t������ �޸� �ּ�\n");
	lineplot(); // ==

	/* a�� ��,�ּҿ� �������� �ּ� */
	printf(" a   �� => %d\n", a);
	printf(" a �ּ� => %u\n", &a);
	printf("p1 �ּ� => %u\n", &p1);
	printf("p2 �ּ� => %u\n", &p2);
	printf("p3 �ּ� => %u\n", &p3);
	lineplot();   
	
	printf("\n");
	printf("*p1 �ڷ� [p1 = &a]\t");
	printf("**p2 �ڷ� [p2 = &p1]\t");
	printf(" ***p3 �ڷ� [p3 = &p2]\n");
	lineplot();

	p1 = &a;     p2 = &p1;     p3 = &p2;

	printf("p1�ּ� =>%8u\t p2�ּ� =>%8u\t  p3�ּ� =>%8u\n", &p1, &p2, &p3);
	printf("  p1�� =>%8d\t   p2�� =>%8d\t    p3�� =>%8d\n", p1, p2, p3);
	printf(" *p1�� =>%8d\t  *p2�� =>%8d\t   *p3�� =>%8d\n", *p1, *p2, *p3);
	printf("\t\t\t **p2�� =>%8d\t", **p2);
	printf("  **p3�� =>%8d\n", **p3);
	printf("\t \t \t \t \t \t ***p3�� =>%8d \n", ***p3);

	lineplot();   printf("\n");

}
/* == */
void lineplot(void) {
	int k;
	for (k = 0; k < 78; k++) {
		putchar('='); continue;
	}
	printf("\n");
}
