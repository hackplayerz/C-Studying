/* 2017-11-30 strcpy()�Լ��� �̿��� �迭�� �ʱ�ȭ */
#include <stdio.h>
#include <string.h> // strcpy()

void main() {
	char string[15];
	strcpy(string, "C PROGRAMMING");	// �迭�� �ʱ�ȭ
	printf("%s\n\n", string);

	string[3] = 'r';
	printf("%s\n\n", string);
}