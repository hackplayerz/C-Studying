/* 2017-10-11 �ǽ����� 3-1 ��ݺ� ���� */
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
		printf("�߸��� ��ȣ�� �Է��ϼ̽��ϴ�.\n");
		break;
	}
	
}

void menu() {
	int i ;
	char string[3][10] = { "����","����","���ڿ�" };
	for (i = 0; i < 3; i++) {
		printf("%d. %-3s�Է� �� ���\n", i + 1, string[i]);
	}
}