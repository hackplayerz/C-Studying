/*2017-09-14 fput()�Լ�*/
#include "myheader.h" // fgetc(), fputc()  : �Լ��� ���

void main()
{
	FILE *file1;     // fgetc()
	FILE *file2;     // fputc()
	char  ch;
	file1 = fopen("D:/CJY(VC)/����1.txt", "r");
					// File Read Only
	ch = fgetc(file1);
	printf("����1.txt���� ���� ù ���� : %c \n\n", ch);
	fclose(file1);
					// Close File
	file2 = fopen("D://CJY(VC)/����2.txt", "w");
					// File New Right and Release
	if (file2 == NULL)
	{
		puts("�����������Ҽ������ϴ�.");
	}
	else
	{
		fputc('Z', file2);
		fputc('O', file2);
		fputc('O', file2);
					//����2.txt���Ͽ� ���ڿ� �Է�
		puts("����2.txt ������ �ش� ��Ʈ���ؿ�  ���λ��� Ȯ���غ�����.\n");
		fclose(file2);
					// Close File
	}

	getch();
	return 0;
}
