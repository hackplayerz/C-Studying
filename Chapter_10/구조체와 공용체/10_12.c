/* Wonkwang Univ. 2017-09-06 ����ü�� ����Ͽ� �л��� ������ ���� */
#include <stdio.h>

struct human {
	char name[20];
	unsigned age;
	char sex;
	int birthday;		
	char job[20];
};

struct student {
	char name[20];
	int num;
	char maj[20];
	int grade;
	char call[13];
};

void main() {
	struct human family = { "ȫ�浿",20,'M',19980101,"���" };
	struct student student = { "��ö��",20170101,"��ǻ�Ͱ��а�",1,"010-7777-7777" };
	printf("=================================================================================\n");
	printf("�̸� : %s	", family.name);
	printf("���� : %d	", family.age);
	printf("���� : %c	", family.sex);
	printf("������� : %d	", family.birthday);
	printf("���� : %s	\n", family.job);
	printf("=================================================================================\n");
	printf("�̸� : %s	", student.name);
	printf("�й� : %d	", student.num);
	printf("���� : %s	", student.maj);
	printf("�г� : %d	", student.grade);
	printf("��ȭ��ȣ : %d	\n", student.call);
	printf("=================================================================================\n");
}