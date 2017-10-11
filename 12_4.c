/* 2017-09-21 Scanf() */
#include "myheader.h"
int main(void) {
	char ch = 0;
	short int si = 0;
	int i = 0, o8 = 0, x16 = 0;
	unsigned ui = 0;
	long l = 0;
	float f = 0;
	double d = 0;
	char s[100] = { 0, };

	printf("char형을 입력하세요 :");
	scanf("%c", &ch);
	printf("scanf : %c\n\n", ch);

	printf("short형을 입력하세요 :");
	scanf("%hd", &si);
	printf("scanf : %d\n\n", si);

	printf("int형을 입력하세요 :");
	scanf("%d", &i);
	printf("scanf : %d\n\n", i);

	printf("unsigned형을 입력하세요 :");
	scanf("%u", &ui);
	printf("scanf : %d\n\n", ui);

	printf("long형을 입력하세요 :");
	scanf("%d", &l);
	printf("scanf : %d\n\n", l);

	printf("8진수형을 입력하세요 :");
	scanf("%o", &o8);
	printf("scanf : %o\n\n", o8);

	printf("16진수형을 입력하세요 :");
	scanf("%x", &x16);
	printf("scanf : %x\n\n", x16);

	printf("float형을 입력하세요 :");
	scanf("%f", &f);
	printf("scanf : %f\n\n", f);

	printf("double형을 입력하세요 :");
	scanf("%lf", &d);
	printf("scanf : %lf\n\n",d);

	printf("문자열형형을 입력하세요 :");
	scanf("%s", s);
	printf("scanf : %s\n\n", s);

	printf("정수 입력하세요 :");
	scanf("%4d %3d", &i, &o8);
	printf("%d, %d\n\n", i, o8);

	getch();
	return 0;
 }