/* 2017-12-07 1���� �迭 ������ */
#include <stdio.h>
#include <string.h>

void main() {
	char string[12];
	unsigned int i;

	char *ptr;
	strcpy(string, "Programming"); // �迭 �ʱ�ȭ

	ptr = string;       // ������ ���� �ʱ�ȭ

	printf("ptr�� �ּ�            : %d \n", &ptr);
	printf("ptr�� ����Ű�� ��     : %c \n", *ptr);
	printf("ptr�� ����Ű�� ���ڿ� : %s \n\n", ptr);

	for (i = 0; i <= 11; i++)
		printf("string[%2d] �� �ּ� : %d\t prt+ %2d �� �� : %d\n", i, &string[i], i, ptr + i);
	printf("\n");

	for (i = 0; i <= 11; i++)
		printf("*(ptr +%3d) : %c (%3d) \n", i, *(ptr + i), *(ptr + i));
	printf("\n");
	for (i = 0; i <= 11; i++)
		printf("ptr +%3d : %s\n", i, ptr + i);
	printf("\n\n");
}