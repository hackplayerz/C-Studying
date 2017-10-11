/* 2017-09-21 scanf() */
#include "myheader.h"

int main(void) {
	char stdMaj[30] = { 0, };
	char stdName[20] = { 0, };
	int stdNum = 0;

	printf("학과를 입력하세요 :");
	scanf("%s", stdMaj);			// get charater from User
	printf("\n학번을 입력하세요 :");
	scanf("%d", &stdNum);			// get inteager from User
	printf("\n이름을 입력하세요 :");
	scanf("%s", stdName);			

	printf("\n\n학생의 학과는 \'%s이고\' ", stdMaj);
	printf("학번은 \'%d\'이며 ", stdNum);
	printf("이름은 \'%s\'입니다.\n", stdName);
									// print Student's Majer, Number, Name
	getch();
	return 0;
}