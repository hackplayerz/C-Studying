/* Wonkwang Univ. 2017-09-06 구조체를 사용하여 학생의 정보를 저장 */
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
	struct human family = { "홍길동",20,'M',19980101,"백수" };
	struct student student = { "김철수",20170101,"컴퓨터공학과",1,"010-7777-7777" };
	printf("=================================================================================\n");
	printf("이름 : %s	", family.name);
	printf("나이 : %d	", family.age);
	printf("성별 : %c	", family.sex);
	printf("생년월일 : %d	", family.birthday);
	printf("직업 : %s	\n", family.job);
	printf("=================================================================================\n");
	printf("이름 : %s	", student.name);
	printf("학번 : %d	", student.num);
	printf("전공 : %s	", student.maj);
	printf("학년 : %d	", student.grade);
	printf("전화번호 : %d	\n", student.call);
	printf("=================================================================================\n");
}