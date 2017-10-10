/*2017-09-14파일 Open Close*/
#include "myheader.h"  // <Stdio.h> => fopen(), fclose(), fgetc()
void main()
{
	FILE *in, *out;    //  파일 포인터 
	char ech, kch;


	in = fopen("D:/CJY(VC)/영문1.txt", "r");
	out = fopen("D:/CJY(VC)/숫자1.txt", "r");
						// File Open

	if ((in == NULL) && (out = NULL)) {
		puts("파일을 생성할 수 없음.");
	}
	else {
		ech = fgetc(in);
		kch = fgetc(out);
						// File내의 내용을 읽어옴
		printf("영문-읽은 첫문자: %c \n\n", ech);
		printf("숫자 - 읽은 첫 문자 : %c \n\n", kch );
	}
	fclose(in);
	fclose(out);
						//File Close
	getch();
	return 0;
}
