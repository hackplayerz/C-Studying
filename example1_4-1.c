#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)

int input_result(void);
struct student {
	char name[20];
	int number;
	char myway[20];
	float kor;
	float math;
	float eng;
	float avg;
};
struct student student1;
struct student student2;
struct student student3;
void main()
{

	int a = 0;
	printf("메뉴를 선택해 주세요\n");
	printf("1:성적입력\n");
	printf("2:석차표현\n");
	scanf("%d", &a);
	switch (a)
	{
		system("cls");
	case 1:
		printf("성적입력을 선택하셨습니다\n");
		input_result();
		break;


	}
}
int input_result(void)
{
	int  i=0;
	printf("이름을 쓰세요.");
	scanf("%s", &student1.name);
	printf("\n학번을 쓰세요.");
	scanf("%d", &student1.number);
	printf("\n전공을 쓰세요.");
	scanf("%s", &student1.myway);
	printf("\n국어점수를 입력하세요");
	scanf("%f", &student1.kor);
	printf("\n수학점수를 입력하세요");
	scanf("%f", &student1.math);
	printf("\n영어점수를 입력하세요");
	scanf("%f", &student1.eng);
	student1.avg = ((student1.kor + student1.math + student1.eng) / 3);
	printf("\n평균은:%f", student1.avg);

	printf("\n--------------------------------------------------------\n");
	printf("NO\t   이름:\t학번:\t\t전공:\t국어:\t수학:\t영어:\t평균:\t");
	printf("\n--------------------------------------------------------\n");
	printf("%2d : %9s : %10d : %13s :  %3.1f : %3.1f : %3.1f : %3.1f\n",i, 
		student1.name, student1.number, student1.myway, student1.kor, student1.math, student1.eng,student1.avg);
	printf("---------------------------------------------------------\n");

	return 0;
}