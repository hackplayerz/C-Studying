/* 2017-09-14 fopen() */
#include <stdio.h>

void main()
{
	FILE *file;

	file = fopen("E:/CJY(VC)/data1.txt", "w+");
		
	if (file == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		puts("������ ���������� �����Ǿ����ϴ�.");
		fclose(file);
	}
}