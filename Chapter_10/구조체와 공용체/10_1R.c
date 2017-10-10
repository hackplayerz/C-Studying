/*	2017-8-31 구조체	Report	*/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <conio.h>

struct book {
	char title[20];
	char author[25];
	float value;
};

struct book book1 = { "Operating system", "Stallings", 15000.0 };
struct book book2 = { "Database system", " Korth", };	//	구조체 book2의 value를 뺴고 초기화

int main(void)
{
	printf("구조체변수 : book1 \n");					// 구조체변수 book1의 member를 출력
	printf("책의제목   : %s \n", book1.title);
	printf("책의저자   : %s \n", book1.author);
	printf("책의가격   : %7.1f \n\n", book1.value);

	printf("구조체변수 : book2 \n");					// 구조체변수 book2의 member를 출력 
	printf("책의제목   : %s \n", book2.title);
	printf("책의저자   : %s \n", book2.author);
	printf("책의가격   : %7.1f \n\n", book2.value);		// 초기값 없음  
	getch();
	return 0;
}
