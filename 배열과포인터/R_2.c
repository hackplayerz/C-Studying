/* 실습예제11.2 */
#include <stdio.h>

void swap(int *a, int *b);
void main()
{
	int val1 = 10;
	int val2 = 20;
	printf("함수 호출 전\n");
	printf("val1 : %d, val2 : %d\n", val1, val2);
	swap(&val1, &val2);
	printf("함수 호출 후\n");
	printf("val1 : %d, val2 : %d\n", val1, val2);
}
void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
