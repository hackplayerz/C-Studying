/* 2017-11-30 strcpy()함수를 이용해 배열을 초기화 */
#include <stdio.h>
#include <string.h> // strcpy()

void main() {
	char string[15];
	strcpy(string, "C PROGRAMMING");	// 배열의 초기화
	printf("%s\n\n", string);

	string[3] = 'r';
	printf("%s\n\n", string);
}