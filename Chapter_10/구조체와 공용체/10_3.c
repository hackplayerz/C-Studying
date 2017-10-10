/*	2017-09-06 중첩된 구조체	*/
#include "myheader.h"

struct author {					// 구조체  author 선언
	char first[15];
	char last[10];
};
struct book {
	char title[20];
	struct author names;		// 구조체 book 내에 구조체 author 가 중첩선언
	float value;
};

int main(void)
{
	static struct book guide = { "Computer network",{ "Andrew", "Tanenbaum" }, 6000.0 };
	/* guide는 구조체 book의 구조체변수, names는 구조체 author의  구조체변수  */

	printf("책의제목guide.title : %s \n", guide.title);
								// 중첩된 구조체 멤버 출력
	printf("책의저자명 이름guide.names.first : %s \n", guide.names.first); 
	printf("책의저자명  성guide.names.last  : %s \n", guide.names.last); 
	printf("책의가격guide.value : %7.1f\n\n", guide.value);

	getch();
	return 0;
}