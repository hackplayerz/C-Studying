/*	2017-09-06 구조체에 대한 포인터*/
#include "myheader.h"
#define LEN 25

struct author {
	char first[LEN];
	char last[LEN];
};						// 구조체 author 선언

int main(void) {
	static struct author names = { "Harby","Deitel" };
	struct author *ptr;	// 구초제 포인터 *ptr선언
	ptr = &names;		// ptr에 names의 주소를 대입

	printf("구조체 변수 names 사용\n");
	printf("책의 저자명 이름 names.first : %s\n", names.first);
	printf("책의 저자명 성   names.last : %s\n\n", names.last);

	printf("구조체 포인터ptr 사용 [name와 (*ptr)은 같음]\n");
	printf("책의 저자명 이름(*ptr).first : %s\n", (*ptr).first);
	printf("책의 저자명 성  (*ptr).last : %s\n\n",(*ptr).last);

	printf("구조체 포인터 ptr 사용[(*ptr)와 ptr->은 같음]\n");
	printf("책의 저자명 이름 ptr->first : %s\n", ptr->first);
	printf("책의 저자명 성   ptr->last : %s\n\n", ptr->last);

	getch();
	return 0;
}