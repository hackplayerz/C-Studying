/* Wonkwang Univ. 2017-09-14 getc() 함수 */
#include <stdio.h>			// getc(), putc()

void main()
{
	FILE *file1;			 // getc()
	FILE *file2;			 // putc()
	char ch;

	file1 = fopen("E:/CJY(VC)/영문1.txt", "r");
	ch = getc(file1);		// get character to File
	printf("영문1.txt에서 읽은 첫 문자: %c \n\n", ch);
	fclose(file1);			// Close File

	file2 = fopen("E:/CJY(VC)/영문2.txt", "w+");
	if (file2 == NULL)
	{
		puts("파일을생성할수없습니다.");
	}						// No File
	else
	{
		putc('Z', file2);
		putc('O', file2);
		putc('O', file2);
		puts("영문2.txt 파일이 해당 디렉트리밑에  새로생성 확인해보세요.\n");
		fclose(file2);
	}						// Put character to File
}
