/* 2017-10-11 실습예제 3-1 비반복 예제 */
#include <stdio.h>

void menu();
union getmember {
	char character;
	int inteager;
	char string[20];
};
union getmember member;

void main() {
	int menu_input = 0;
	menu();
	scanf("%d", &menu_input);

	switch (menu_input + 1) {
	case 1:
		scanf("%d", &member.inteager);
		printf("%d\n", member.inteager);
		break;

	case 2:
		scanf("%c", &member.character);
		printf("%c\n", member.character);
		break;
	case 3:
		scanf("%c", &member.string);
		printf("%s\n", member.string);
		break;
	default:
		printf("잘못된 번호를 입력하셨습니다.\n");
		break;
	}
	
}

void menu() {
	int i ;
	char string[3][10] = { "정수","문자","문자열" };
	for (i = 0; i < 3; i++) {
		printf("%d. %-3s입력 및 출력\n", i + 1, string[i]);
	}
}