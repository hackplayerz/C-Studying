#include <stdio.h>
int sum(int val1, int val2);
void main()
{

	int v1 = 1;
	int result = 0;

	result = sum(v1--, (v1--) * 2);
	printf("result = %d\n", result);
	printf("v1 = %d", v1);
	
}
int sum(int val1, int val2) {	
	printf("val1 = %d val2 = %d", val1, val2);
	return val1 + val2;
}

