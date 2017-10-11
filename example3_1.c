#include <stdio.h>			// Standard Input Output Header
#include <limits.h>			// 변수들의 범위를 나타내는 상수를 정의하는 헤더
#include <float.h>			

int main(void) {
	/* Character형 변수의 Data 범위를 보여줌 */
	printf("char 범위 : %d ~ %d\n", CHAR_MIN, CHAR_MAX);
	printf("signed char 범위 : %d ~ %d\n", CHAR_MIN, CHAR_MAX);
	printf("unsigned char 범위 : %d ~ %d\n\n", 0, UCHAR_MAX);

	/* inteager형 변수의 Data 범위를 보여줌 */
	printf("[Signed] short [int] 범위 : %hi ~ %hi\n", SHRT_MIN, SHRT_MAX);
	printf("[Signed] [int] 범위 : %d ~ %d\n",INT_MIN, INT_MAX);
	printf("[Signed] long [int] 범위 : %li ~ %li\n",LONG_MIN, LONG_MAX);
	printf("UnSigned short [int] 범위 : %hu ~ %hu\n", 0, USHRT_MAX);
	printf("UnSigned [int] 범위 : %u ~ %u\n",0, UINT_MAX);
	printf("UnSigned long [int] 범위 : %lu ~ %lu\n\n", 0, ULONG_MAX);

	/* 실수형 변수의 Data 범위를 보여줌*/
	printf("float 범위 : %e ~ %e\n", FLT_MIN, FLT_MAX);
	printf("double 범위 : %e ~ %e\n", DBL_MIN, DBL_MAX);
	printf("long double 범위 : %e ~ %e\n\n", LDBL_MIN, LDBL_MAX);

}