/*2017-09-14고수준 파일I/o*/
#include "myheader.h"
// fopen() fclose()
int main(void)
{
	FILE *fp;    // 화일 포인터 선언 
	char  ch;
			

	fp = fopen("c:/CJY(VC)/알파베트1.txt", "r");
						//C드라이브 내 CJY(VC)폴더의 알파베트1.txt를 읽기 전용으로 호출
	if (fp == NULL) {
		puts("파일을생성할수없음.");
	}
	else {
			ch = fgetc(fp);  //한 문자 읽어 저장 
			printf("읽은문자: %c \n\n", ch);
			fclose(fp);		//fp파일을 닫음
		
	}

	getch();
	return 0;
}
