/* 2017-09-20 fputs(), fgets() */
#include "myheader.h"

void main()
{
	FILE *fp;
	char buffer[27];

	fp = fopen("D://CJY(VC)/����26.txt", "r");
	if (fp == NULL) {
		puts("������ ������ �� �����ϴ�.");
	}
	else {
		fgets(buffer, 26, fp);  // fp������������ 25���ڸ�  ����
		printf("fgets ������ buffer�� ����: %s\n\n", buffer);
		fclose(fp);
								// file close

		fp = fopen("D://CJY(VC)/����2.txt", "w+" );
								// w+ �� �б� ���� ���
		fputs("These are American Alpabetics \n", fp);
								// ���Ͽ� ���ڿ��� �Է�
		printf("����2.txt�� ����� ����Ȯ�ιٶ��ϴ�\n\n");
		fclose(fp);
	}

	getch();
	return 0;
}