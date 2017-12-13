/* 2017-12-07 배열 포인터의 이용 */
#include <stdio.h>

void main()
{
	int r, c;
	int a[3][2] = { { 1, 2 },{ 3, 4 },{ 5, 6 } };
	int(*ptr)[2]; // 배열 포인터 선언

	ptr = a;

	printf("ptr 의 주소 : %d\n\n", &ptr);

	for (r = 0; r < 3; r++)
		for (c = 0; c < 2; c++)
			printf("a[%d][%d] : %d ==> %d\n", r, c, &a[r][c], a[r][c]);
	printf("\n");
	for (r = 0; r < 3; r++) {
		printf("ptr + %d = %-8u    ", r, ptr + r);
		printf("*(ptr + %d) = %-8d   ", r, *(ptr + r));
		printf("**(ptr + %d) = %-8d", r, **(ptr + r));
		printf("\n\n");

		for (c = 0; c < 2; c++) {
			printf("     *(ptr + %d) + %d = %-8d", r, c, *(ptr + r) + c);
			printf(" ==>");
			printf("  *(*(ptr + %d) + %d) = %-8d", r, c, *(*(ptr + r) + c));
			printf("\n");
		}
		printf("\n");
	}
	printf("\n\n");
}
