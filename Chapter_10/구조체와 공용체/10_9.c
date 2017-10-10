/*2017-09-07 공용체(Union)*/
#include "myheader.h"
void main()
{
	union book {
		char title[25];
		char author[25];
		float value;
	}book1;    // 유니온변수 book1 로선언
	printf("Union size is %d Bytes\n\n", sizeof(book1));
	/*	union 선언에서 Turbo C에서는 25 bytes로 나타남
		Visual Studio(C++)에서는 선언된 실수형 4 bytes 의 곱의
		수의 크기인 28 bytets로 제공함.	*/
	getch();
	return 0;
}