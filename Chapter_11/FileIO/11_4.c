/*2017-09-14 fput()함수*/
#include "myheader.h" // fgetc(), fputc()  : 함수로 사용

void main()
{
	FILE *file1;     // fgetc()
	FILE *file2;     // fputc()
	char  ch;
	file1 = fopen("D:/CJY(VC)/영문1.txt", "r");
					// File Read Only
	ch = fgetc(file1);
	printf("영문1.txt에서 읽은 첫 문자 : %c \n\n", ch);
	fclose(file1);
					// Close File
	file2 = fopen("D://CJY(VC)/영문2.txt", "w");
					// File New Right and Release
	if (file2 == NULL)
	{
		puts("파일을생성할수없습니다.");
	}
	else
	{
		fputc('Z', file2);
		fputc('O', file2);
		fputc('O', file2);
					//영문2.txt파일에 문자열 입력
		puts("영문2.txt 파일이 해당 디렉트리밑에  새로생성 확인해보세요.\n");
		fclose(file2);
					// Close File
	}

	getch();
	return 0;
}
