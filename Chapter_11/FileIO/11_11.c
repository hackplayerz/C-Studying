/* 2017-09-20 실습 6 : 정수의 값을 ‘data.txt’ 파일에 저장하는 프로그램을 작성하시오 */
#include <stdio.h>

void main()
{
	FILE *fp;
	int i = 12345;

	fp = fopen("E://CJY(VC)/data.txt", "w+");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		fprintf(fp, "%d", i);
		fclose(fp);
	}
}
