/* 2017-09-21 scanf() */
#include "myheader.h"

int main(void) {
	char stdMaj[30] = { 0, };
	char stdName[20] = { 0, };
	int stdNum = 0;

	printf("�а��� �Է��ϼ��� :");
	scanf("%s", stdMaj);			// get charater from User
	printf("\n�й��� �Է��ϼ��� :");
	scanf("%d", &stdNum);			// get inteager from User
	printf("\n�̸��� �Է��ϼ��� :");
	scanf("%s", stdName);			

	printf("\n\n�л��� �а��� \'%s�̰�\' ", stdMaj);
	printf("�й��� \'%d\'�̸� ", stdNum);
	printf("�̸��� \'%s\'�Դϴ�.\n", stdName);
									// print Student's Majer, Number, Name
	getch();
	return 0;
}