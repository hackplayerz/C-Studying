/*2017-09-14���� Open Close*/
#include "myheader.h"  // <Stdio.h> => fopen(), fclose(), fgetc()
void main()
{
	FILE *in, *out;    //  ���� ������ 
	char ech, kch;


	in = fopen("D:/CJY(VC)/����1.txt", "r");
	out = fopen("D:/CJY(VC)/����1.txt", "r");
						// File Open

	if ((in == NULL) && (out = NULL)) {
		puts("������ ������ �� ����.");
	}
	else {
		ech = fgetc(in);
		kch = fgetc(out);
						// File���� ������ �о��
		printf("����-���� ù����: %c \n\n", ech);
		printf("���� - ���� ù ���� : %c \n\n", kch );
	}
	fclose(in);
	fclose(out);
						//File Close
	getch();
	return 0;
}
