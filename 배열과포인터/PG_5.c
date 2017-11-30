/* 2017-11-30 배열의 초기화 */
#include <stdio.h>

void main() {
	int grade[10] = { 31,63,62,87,14,25,92,70,75,53 };
	
	printf("===========================\n");
	printf("인덱스		  :값\n");
	printf("===========================\n");

	for (int i = 0; i < 10; i++) {
		printf("%5d		   %5d\n", i, grade[i]);
		}
}