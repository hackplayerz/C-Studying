#include <stdio.h>			// Standard Input Output Header
#include <limits.h>			// �������� ������ ��Ÿ���� ����� �����ϴ� ���
#include <float.h>			

int main(void) {
	/* Character�� ������ Data ������ ������ */
	printf("char ���� : %d ~ %d\n", CHAR_MIN, CHAR_MAX);
	printf("signed char ���� : %d ~ %d\n", CHAR_MIN, CHAR_MAX);
	printf("unsigned char ���� : %d ~ %d\n\n", 0, UCHAR_MAX);

	/* inteager�� ������ Data ������ ������ */
	printf("[Signed] short [int] ���� : %hi ~ %hi\n", SHRT_MIN, SHRT_MAX);
	printf("[Signed] [int] ���� : %d ~ %d\n",INT_MIN, INT_MAX);
	printf("[Signed] long [int] ���� : %li ~ %li\n",LONG_MIN, LONG_MAX);
	printf("UnSigned short [int] ���� : %hu ~ %hu\n", 0, USHRT_MAX);
	printf("UnSigned [int] ���� : %u ~ %u\n",0, UINT_MAX);
	printf("UnSigned long [int] ���� : %lu ~ %lu\n\n", 0, ULONG_MAX);

	/* �Ǽ��� ������ Data ������ ������*/
	printf("float ���� : %e ~ %e\n", FLT_MIN, FLT_MAX);
	printf("double ���� : %e ~ %e\n", DBL_MIN, DBL_MAX);
	printf("long double ���� : %e ~ %e\n\n", LDBL_MIN, LDBL_MAX);

}