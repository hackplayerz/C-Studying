/* 실습예제 1-1 */
#include <stdio.h>				// Standara Input Output Header
#include <conio.h>				// Console Input Output Header

int main(void) {
	int i;
	char Name[] = "홍길동";
	int Age = 20;
	int height = 175;
	int weights[12] = { 80, 78, 79, 77, 75, 76, 77, 74, 73, 75, 73, 71 };

	printf("이름 : %s\n", Name);
	printf("나이 : %d\n", Age);
	printf("키 : %d\n", height);
	printf("체중 : ");

	for (i = 0; i < 12; i++) {
		printf("%3d ", weights[i]);
	}
	printf("\n");

	getch();
	return 0;
}