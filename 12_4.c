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

	printf("char���� �Է��ϼ��� :");
	scanf("%c", &ch);
	printf("scanf : %c\n\n", ch);

	printf("short���� �Է��ϼ��� :");
	scanf("%hd", &si);
	printf("scanf : %d\n\n", si);

	printf("int���� �Է��ϼ��� :");
	scanf("%d", &i);
	printf("scanf : %d\n\n", i);

	printf("unsigned���� �Է��ϼ��� :");
	scanf("%u", &ui);
	printf("scanf : %d\n\n", ui);

	printf("long���� �Է��ϼ��� :");
	scanf("%d", &l);
	printf("scanf : %d\n\n", l);

	printf("8�������� �Է��ϼ��� :");
	scanf("%o", &o8);
	printf("scanf : %o\n\n", o8);

	printf("16�������� �Է��ϼ��� :");
	scanf("%x", &x16);
	printf("scanf : %x\n\n", x16);

	printf("float���� �Է��ϼ��� :");
	scanf("%f", &f);
	printf("scanf : %f\n\n", f);

	printf("double���� �Է��ϼ��� :");
	scanf("%lf", &d);
	printf("scanf : %lf\n\n",d);

	printf("���ڿ������� �Է��ϼ��� :");
	scanf("%s", s);
	printf("scanf : %s\n\n", s);

	printf("���� �Է��ϼ��� :");
	scanf("%4d %3d", &i, &o8);
	printf("%d, %d\n\n", i, o8);

	getch();
	return 0;
 }