/* 2017-09-20 �ǽ� 6 : ������ ���� ��data.txt�� ���Ͽ� �����ϴ� ���α׷��� �ۼ��Ͻÿ� */
#include <stdio.h>

void main()
{
	FILE *fp;
	int i = 12345;

	fp = fopen("E://CJY(VC)/data.txt", "w+");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		fprintf(fp, "%d", i);
		fclose(fp);
	}
}
