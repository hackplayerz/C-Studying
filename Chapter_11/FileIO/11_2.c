/*2017-09-14����� ����I/o*/
#include "myheader.h"
// fopen() fclose()
int main(void)
{
	FILE *fp;    // ȭ�� ������ ���� 
	char  ch;
			

	fp = fopen("c:/CJY(VC)/���ĺ�Ʈ1.txt", "r");
						//C����̺� �� CJY(VC)������ ���ĺ�Ʈ1.txt�� �б� �������� ȣ��
	if (fp == NULL) {
		puts("�����������Ҽ�����.");
	}
	else {
			ch = fgetc(fp);  //�� ���� �о� ���� 
			printf("��������: %c \n\n", ch);
			fclose(fp);		//fp������ ����
		
	}

	getch();
	return 0;
}
