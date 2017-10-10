/*2017-09-06 구조체 멤버의 참조의 예*/
#pragma warning (disable : 4996)
#include <stdio.h>
#include <conio.h>

struct book {
	char title[20];
	char author[25];
	float values;
};						//구조체 book형 선언


struct book park[3] = { { "Self - Study C 언어","주수종",14000.0 },{ "공학입문","홍길동",13000.0 },
{ "수학미적분","스마트",20000.0} };
						//구조체 book형의 변수배열 선언
int main(void) {
					/*	구조체 변수 park[i]의 멤버를 출력	*/
	int i;

	for (i = 0; i < 3; i++) {
		printf("구조체변수 park[%d]\n",i);
		printf("책의 제목 : %s\n", park[i].title);
		printf("책의 저자 : %s\n", park[i].author);
		printf("책의 가격 : %7.1f\n\n", park[i].values);
	}
	getch();
	return 0;
}