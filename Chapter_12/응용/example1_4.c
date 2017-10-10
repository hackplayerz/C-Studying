/* 프로그래밍 실습 - 석차 연명부 */
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
struct student M2U = { "M2U",20171231,"실용음악과",80,90,20,(80+90+20)/3 };
struct student Nicode = { "Nicode",20173242,"컴퓨터공학과",70,100,90, (70+100+90)/3};
struct student Rat = { "The Fat Rat",201582893,"기계공학과",60,90,100,(60+90+100)/3 };
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
			
		printf("이 프로그램은 석차 연명부입니다.\n");
		printf("메뉴중에서 사용하실 모드를 입력하세요.\n");
		menu1();
		printf("메뉴 :");
		scanf("%d", &choice1);
		switch (choice1) {
		case 1:
			for (i = 0; i < 3; i++) {
				system("cls");
				printf("자료입력메뉴를 입력하셨습니다.\n");
				printf("총 3명의 학생들의 정보를 더 입력할수 있습니다.\n");
				printf("학생의 이름을 입력하세요:");
				scanf("%s", &stu[i].name);
				printf("\n학번을 입력하세요:");
				scanf("%d", &stu[i].num);
				printf("\n전공을 입력하세요:");
				scanf("%s", &stu[i].maj);
				printf("\n국어점수를 입력하세요:");
				scanf("%d", &stu[i].lang);
				printf("\n수학점수를 입력하세요:");
				scanf("%d", &stu[i].math);
				printf("\n영어점수를 입력하세요:");
				scanf("%d", &stu[i].eng);
			}
			break;
			system("cls");
		case 2:
			system("cls");
			printf("자료 검색메뉴를 입력하셨습니다.\n");
			printf("어떤것을 찾으시겠습니까?\n");
			menu2();
			scanf("%d", &choice2);

			switch (choice2) {
				system("cls");
			case 1:
				printf("국어 평균 점수입니다.\n");
				printf("%d\n", avg_lang);
				getch();
				break;
			case 2:
				printf("수학 평균 점수입니다.\n");
				printf("%d\n", avg_math);
				getch();
				break;
			case 3:
				printf("영어 평균 점수입니다.\n");
				printf("%d\n", avg_eng);
				getch();
				break;
			case 4:
				printf("전체 평균 점수입니다.\n");
				printf("%d\n", avg_all);
				getch();
				break;
			default :				
				printf("잘못된 값을 입력하셨습니다.\n");
				continue;

			}
		case 3:
			system("cls");
			printf("자료 정렬메뉴를 입력하셨습니다.\n");

		}
	}
}
int menu1(void) {
	printf("===================\n");
	printf("  1. 자료 입력\n");
	printf("  2. 자료 검색\n");
	printf("  3. 자료 정렬\n");
	printf("  4. 자료 변경\n");
	printf("===================\n");
	return 0;
}
int menu2(void) {
	printf("===================\n");
	printf("  1. 국어 평균\n");
	printf("  2. 수학 평균\n");
	printf("  3. 영어 평균\n");
	printf("  4. 전체 평균\n");
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