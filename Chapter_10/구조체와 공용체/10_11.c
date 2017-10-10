/*2017-09-07 구조체와 공용체의 크기비교*/
#include "myheader.h"
union wk {
	int i;
	float f;
} wka;   // 유니온 변수  wka(4바이트) 선언

struct wka {
	int i;
	float f;
} wkb;  // 구조변수 wkb(8바이트) 선언 

int main(void)
{
	printf("유니온 변수와 구조체변수의 크기를 확인하시오? \n");
	printf("유니온 변수 wka 의 크기는    =  %d Bytes\n", sizeof(wka));
	printf("구조체변수  wkb 의크기는     =  %d Bytes\n\n", sizeof(wkb));

	getch();
	return 0;
}