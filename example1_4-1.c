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
	printf("�޴��� ������ �ּ���\n");
	printf("1:�����Է�\n");
	printf("2:����ǥ��\n");
	scanf("%d", &a);
	switch (a)
	{
		system("cls");
	case 1:
		printf("�����Է��� �����ϼ̽��ϴ�\n");
		input_result();
		break;


	}
}
int input_result(void)
{
	int  i=0;
	printf("�̸��� ������.");
	scanf("%s", &student1.name);
	printf("\n�й��� ������.");
	scanf("%d", &student1.number);
	printf("\n������ ������.");
	scanf("%s", &student1.myway);
	printf("\n���������� �Է��ϼ���");
	scanf("%f", &student1.kor);
	printf("\n���������� �Է��ϼ���");
	scanf("%f", &student1.math);
	printf("\n���������� �Է��ϼ���");
	scanf("%f", &student1.eng);
	student1.avg = ((student1.kor + student1.math + student1.eng) / 3);
	printf("\n�����:%f", student1.avg);

	printf("\n--------------------------------------------------------\n");
	printf("NO\t   �̸�:\t�й�:\t\t����:\t����:\t����:\t����:\t���:\t");
	printf("\n--------------------------------------------------------\n");
	printf("%2d : %9s : %10d : %13s :  %3.1f : %3.1f : %3.1f : %3.1f\n",i, 
		student1.name, student1.number, student1.myway, student1.kor, student1.math, student1.eng,student1.avg);
	printf("---------------------------------------------------------\n");

	return 0;
}