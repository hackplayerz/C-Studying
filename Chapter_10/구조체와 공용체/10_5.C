/*2017-09-06 중첩된 구조체의 멤버 참조*/
#include "myheader.h"
#define  LEN 25

struct author {
	char first[LEN];
	char last[LEN];
};					//구조체 author 선언

struct book {
	char title[LEN];
	struct author names;
	float value;
};					//구조체 book 선언

int main(void)
{
	int i;
	static struct book book1[2] = {
		{ "Operating system",{ "Harby m", "Deitel" }, 6000.0 },
		{ "Architecture",{ "Moris", "Mano" }, 4500.0 } };
					//구조체 book의 배열 book1[2] 선언
	struct  book  *ptr;
					//구조체 book의 포인터 선언
	ptr = &book1[0];
	/*	book1:구조체변수, book1[2]:구조체배열, *ptr : 구조체에대한포인터	*/

	for (i = 0; i<2; i++) {

		printf("구조체배열book1[%d}.title  : %s \n", i, book1[i].title);
		printf("구조체포인터(*ptr).title   : %s \n", (*ptr).title);
		printf("구조체포인터ptr->title     : %s \n\n", ptr->title);


		printf("구조체배열book1[%d}.names.first : %s \n", i, book1[i].names.first);
		printf("구조체포인터(*ptr).names.first  : %s \n", (*ptr).names.first);
		printf("구조체포인터ptr->names.first   : %s \n\n", ptr->names.first);


		printf("구조체배열book1[%d}.names.last  : %s \n", i, book1[i].names.last);
		printf("구조체포인터(*ptr).names.last   : %s \n", (*ptr).names.last);
		printf("구조체포인터ptr->names.last     : %s \n\n", ptr->names.last);


		printf("구조체배열book1[%d}.value : %7.1f \n", i, book1[i].value);
		printf("구조체포인터(*ptr).value  : %7.1f \n", (*ptr).value);
		printf("구조체포인터ptr->value    : %7.1f \n\n", ptr->value);
		ptr++;
		printf("================================================= \n\n");
	}

	getch();
	return 0;
}