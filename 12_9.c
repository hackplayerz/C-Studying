#include <stdio.h>

void main() {
	int i;
	for (i = 0; i < 127; i++) {
		printf("수치값 %d의 문자 : %c\n", i, i);
	}
}