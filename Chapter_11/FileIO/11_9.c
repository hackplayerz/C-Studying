/* 2017-09-14 fopen() */
#include <stdio.h>

void main()
{
	FILE *file;

	file = fopen("E:/CJY(VC)/data1.txt", "w+");
		
	if (file == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		puts("파일이 정상적으로 생성되었습니다.");
		fclose(file);
	}
}