/* 2017-12-06 다중 간섭 참조가 이루어 질때 각 포인터 변수의 주소와 값 */
#include <stdio.h>
void lineplot(void);		// 줄나누기함수

void main() {
	int a = 100;
	int *p1;
	int **p2;
	int ***p3;

	printf("\t\t\t변수별 메모리 주소\n");
	lineplot(); // ==

	/* a의 값,주소와 포인터의 주소 */
	printf(" a   값 => %d\n", a);
	printf(" a 주소 => %u\n", &a);
	printf("p1 주소 => %u\n", &p1);
	printf("p2 주소 => %u\n", &p2);
	printf("p3 주소 => %u\n", &p3);
	lineplot();   
	
	printf("\n");
	printf("*p1 자료 [p1 = &a]\t");
	printf("**p2 자료 [p2 = &p1]\t");
	printf(" ***p3 자료 [p3 = &p2]\n");
	lineplot();

	p1 = &a;     p2 = &p1;     p3 = &p2;

	printf("p1주소 =>%8u\t p2주소 =>%8u\t  p3주소 =>%8u\n", &p1, &p2, &p3);
	printf("  p1값 =>%8d\t   p2값 =>%8d\t    p3값 =>%8d\n", p1, p2, p3);
	printf(" *p1값 =>%8d\t  *p2값 =>%8d\t   *p3값 =>%8d\n", *p1, *p2, *p3);
	printf("\t\t\t **p2값 =>%8d\t", **p2);
	printf("  **p3값 =>%8d\n", **p3);
	printf("\t \t \t \t \t \t ***p3값 =>%8d \n", ***p3);

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
