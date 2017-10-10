/* 2017-09-20 fputs(), fgets() */
#include "myheader.h"

void main()
{
	FILE *fp;
	char buffer[27];

	fp = fopen("D://CJY(VC)/영문26.txt", "r");
	if (fp == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		fgets(buffer, 26, fp);  // fp포인터점에서 25문자를  읽음
		printf("fgets 실행후 buffer의 내용: %s\n\n", buffer);
		fclose(fp);
								// file close

		fp = fopen("D://CJY(VC)/영문2.txt", "w+" );
								// w+ 는 읽기 쓰기 모드
		fputs("These are American Alpabetics \n", fp);
								// 파일에 문자열을 입력
		printf("영문2.txt에 저장된 내용확인바랍니다\n\n");
		fclose(fp);
	}

	getch();
	return 0;
}