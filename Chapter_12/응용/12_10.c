#include <stdio.h>
#include <limits.h>
#include <float.h>

void main() {
	printf("char�� ���� : %d ~ %d \n", CHAR_MIN, CHAR_MAX);
	printf("unsigned char ���� : %d ~ %d \n",0, UCHAR_MAX);
	printf("int�� ���� : %d ~ %d\n", INT_MIN, INT_MAX);
	printf("unsigned int�� ���� : %d ~ %d\n",0, UINT_MAX);
	printf("float�� ���� : %.10e ~ %.10e\n", FLT_MIN, FLT_MAX);
	printf("double�� ���� : %.10e ~ %.10e\n", DBL_MIN, DBL_MAX);
}