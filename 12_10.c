#include <stdio.h>
#include <limits.h>
#include <float.h>

void main() {
	printf("char의 범위 : %d ~ %d \n", CHAR_MIN, CHAR_MAX);
	printf("unsigned char 범위 : %d ~ %d \n",0, UCHAR_MAX);
	printf("int의 범위 : %d ~ %d\n", INT_MIN, INT_MAX);
	printf("unsigned int의 범위 : %d ~ %d\n",0, UINT_MAX);
	printf("float의 범위 : %.10e ~ %.10e\n", FLT_MIN, FLT_MAX);
	printf("double의 범위 : %.10e ~ %.10e\n", DBL_MIN, DBL_MAX);
}