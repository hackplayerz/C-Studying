/* 2017-12-07 1차원 배열 포인터 */
#include <stdio.h>
#include <string.h>

void main() {
	char string[12];
	unsigned int i;

	char *ptr;
	strcpy(string, "Programming"); // 배열 초기화

	ptr = string;       // 포인터 변수 초기화

	printf("ptr의 주소            : %d \n", &ptr);
	printf("ptr이 가리키는 값     : %c \n", *ptr);
	printf("ptr이 가리키는 문자열 : %s \n\n", ptr);

	for (i = 0; i <= 11; i++)
		printf("string[%2d] 의 주소 : %d\t prt+ %2d 의 값 : %d\n", i, &string[i], i, ptr + i);
	printf("\n");

	for (i = 0; i <= 11; i++)
		printf("*(ptr +%3d) : %c (%3d) \n", i, *(ptr + i), *(ptr + i));
	printf("\n");
	for (i = 0; i <= 11; i++)
		printf("ptr +%3d : %s\n", i, ptr + i);
	printf("\n\n");
}