/* 2017-09-20 fprintf(), fscanf() */
#include "myheader.h"
#include <io.h>				// Low - level input output header
#include <stdlib.h>			// Standard library header	


int main(void)
{
	FILE *fp;
	FILE *sfp;
	char D_name[30];
	int score;

	if ((fp = fopen("D://CJY(VC)/test.txt", "w")) == NULL) {   /*  test.txt ������ ���ٸ� ����	*/
		printf("Can not open test file. \n");
		exit(1);
	}

	printf("1-Enter D-name and score : ");

	fscanf(stdin, "%s %d", D_name, &score);  /* file*�ڸ��� stdin�� ���ٸ� Ű����κ��������Է� scanf()�� ����*/
	fprintf(stdout, "fprintf = %s %d \n", D_name, score); /* �Ʒ� printf()�� ����*/
	printf("printf =  %s %d \n", D_name, score);

	fprintf(fp, "%s %d", D_name, score); /* test.txt���Ͽ� Ű����� �Է��ѳ����� �����*/
	fclose(fp);

	// test���� ����� �ִ��� fscanf()�� �о� Ȯ�� �Ѵ�.
	if ((sfp = fopen("D://CJY(VC)/test.txt", "r")) == NULL) {   /* fprintf()�� ���� ������ test ������ ���� */
		printf("Can not open test file. \n");
		exit(1);
	}
	printf("\ntext  ���Ͽ� ����� ������ ");
	fscanf(sfp, "%s %d", D_name, &score);  /* text ȭ�Ϸκ�������*/
	fprintf(stdout, "%s %d ���� Ȯ���ϼ���\n\n", D_name, score);
	/* ȭ�����  printf()�� ����*/
	fclose(sfp);
	

	getch();
	return 0;
}