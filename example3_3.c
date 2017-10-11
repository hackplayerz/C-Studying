/* 2017-10-11 ASCII CODE */
#include <stdio.h>

void main() {
	int i;
	int j;
	printf("실습 3-1 :\n");
	for (i = 65; i < 91; i++) {
		printf("%c ", i);
	}
	printf("\n");
	for (i = 97; i < 123; i++) {
		printf("%c ", i);
	}
	printf("\n\n");
	printf("보너스 문제 :\n");
	for(i=65;i<=90;i++){
		printf("%c ", i);
		i += 33;
		printf("%c ", i);
		i -=32;		
	}	
	printf("\n");
	for (i = 65; i <= 90; i++) {
		printf("%c ", i);
		i += 32;
		printf("%c ", i);
		i -= 31;
	}
}