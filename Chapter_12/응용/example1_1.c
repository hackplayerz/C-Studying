/* �ǽ����� 1-1 */
#include <stdio.h>				// Standara Input Output Header
#include <conio.h>				// Console Input Output Header

int main(void) {
	int i;
	char Name[] = "ȫ�浿";
	int Age = 20;
	int height = 175;
	int weights[12] = { 80, 78, 79, 77, 75, 76, 77, 74, 73, 75, 73, 71 };

	printf("�̸� : %s\n", Name);
	printf("���� : %d\n", Age);
	printf("Ű : %d\n", height);
	printf("ü�� : ");

	for (i = 0; i < 12; i++) {
		printf("%3d ", weights[i]);
	}
	printf("\n");

	getch();
	return 0;
}