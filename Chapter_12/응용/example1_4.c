/* ���α׷��� �ǽ� - ���� ����� */
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

struct student {
	char name[30];
	int num;
	char maj[30];
	int lang;
	int math;
	int eng;
	float avg;
};
struct student M2U = { "M2U",20171231,"�ǿ����ǰ�",80,90,20,(80+90+20)/3 };
struct student Nicode = { "Nicode",20173242,"��ǻ�Ͱ��а�",70,100,90, (70+100+90)/3};
struct student Rat = { "The Fat Rat",201582893,"�����а�",60,90,100,(60+90+100)/3 };
struct student stu[3] = { 0, };

int menu1(void);
int menu2(void);
float avg_lang();
float avg_math();
float avg_eng();
float avg_all();

int main(void) {

	int i;
	int choice1 = 0;
	int choice2 = 0;
	char c_name[30] = { 0 };

	
	system("cls");
	while (1) {
			
		printf("�� ���α׷��� ���� ������Դϴ�.\n");
		printf("�޴��߿��� ����Ͻ� ��带 �Է��ϼ���.\n");
		menu1();
		printf("�޴� :");
		scanf("%d", &choice1);
		switch (choice1) {
		case 1:
			for (i = 0; i < 3; i++) {
				system("cls");
				printf("�ڷ��Է¸޴��� �Է��ϼ̽��ϴ�.\n");
				printf("�� 3���� �л����� ������ �� �Է��Ҽ� �ֽ��ϴ�.\n");
				printf("�л��� �̸��� �Է��ϼ���:");
				scanf("%s", &stu[i].name);
				printf("\n�й��� �Է��ϼ���:");
				scanf("%d", &stu[i].num);
				printf("\n������ �Է��ϼ���:");
				scanf("%s", &stu[i].maj);
				printf("\n���������� �Է��ϼ���:");
				scanf("%d", &stu[i].lang);
				printf("\n���������� �Է��ϼ���:");
				scanf("%d", &stu[i].math);
				printf("\n���������� �Է��ϼ���:");
				scanf("%d", &stu[i].eng);
			}
			break;
			system("cls");
		case 2:
			system("cls");
			printf("�ڷ� �˻��޴��� �Է��ϼ̽��ϴ�.\n");
			printf("����� ã���ðڽ��ϱ�?\n");
			menu2();
			scanf("%d", &choice2);

			switch (choice2) {
				system("cls");
			case 1:
				printf("���� ��� �����Դϴ�.\n");
				printf("%d\n", avg_lang);
				getch();
				break;
			case 2:
				printf("���� ��� �����Դϴ�.\n");
				printf("%d\n", avg_math);
				getch();
				break;
			case 3:
				printf("���� ��� �����Դϴ�.\n");
				printf("%d\n", avg_eng);
				getch();
				break;
			case 4:
				printf("��ü ��� �����Դϴ�.\n");
				printf("%d\n", avg_all);
				getch();
				break;
			default :				
				printf("�߸��� ���� �Է��ϼ̽��ϴ�.\n");
				continue;

			}
		case 3:
			system("cls");
			printf("�ڷ� ���ĸ޴��� �Է��ϼ̽��ϴ�.\n");

		}
	}
}
int menu1(void) {
	printf("===================\n");
	printf("  1. �ڷ� �Է�\n");
	printf("  2. �ڷ� �˻�\n");
	printf("  3. �ڷ� ����\n");
	printf("  4. �ڷ� ����\n");
	printf("===================\n");
	return 0;
}
int menu2(void) {
	printf("===================\n");
	printf("  1. ���� ���\n");
	printf("  2. ���� ���\n");
	printf("  3. ���� ���\n");
	printf("  4. ��ü ���\n");
	printf("===================\n");

	return 0;
}
float avg_lang() {
	float avg = 0;
	avg = (M2U.lang + Nicode.lang + Rat.lang + stu[0].lang + stu[1].lang + stu[2].lang) / 3;

	return avg;
}
float avg_math() {
	float avg = 0;
	avg = (M2U.math + Nicode.math + Rat.math + stu[0].math + stu[1].math + stu[2].math) / 3;

	return avg;
}
float avg_eng() {
	float avg = 0;
	avg = (M2U.eng + Nicode.eng + Rat.eng + stu[0].eng + stu[1].eng + stu[2].eng) / 3;

	return avg;
}
float avg_all() {
	float avg = 0;
	avg = ((int)avg_lang + (int)avg_math + (int)avg_eng);
	return avg;
}