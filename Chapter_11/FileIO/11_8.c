/* Wonkwang Univ. 2017-09-14 getc() �Լ� */
#include <stdio.h>			// getc(), putc()

void main()
{
	FILE *file1;			 // getc()
	FILE *file2;			 // putc()
	char ch;

	file1 = fopen("E:/CJY(VC)/����1.txt", "r");
	ch = getc(file1);		// get character to File
	printf("����1.txt���� ���� ù ����: %c \n\n", ch);
	fclose(file1);			// Close File

	file2 = fopen("E:/CJY(VC)/����2.txt", "w+");
	if (file2 == NULL)
	{
		puts("�����������Ҽ������ϴ�.");
	}						// No File
	else
	{
		putc('Z', file2);
		putc('O', file2);
		putc('O', file2);
		puts("����2.txt ������ �ش� ��Ʈ���ؿ�  ���λ��� Ȯ���غ�����.\n");
		fclose(file2);
	}						// Put character to File
}
