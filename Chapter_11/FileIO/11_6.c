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

	if ((fp = fopen("D://CJY(VC)/test.txt", "w")) == NULL) {   /*  test.txt 파일이 없다면 실행	*/
		printf("Can not open test file. \n");
		exit(1);
	}

	printf("1-Enter D-name and score : ");

	fscanf(stdin, "%s %d", D_name, &score);  /* file*자리에 stdin을 쓴다면 키보드로부터직접입력 scanf()와 같음*/
	fprintf(stdout, "fprintf = %s %d \n", D_name, score); /* 아래 printf()와 같음*/
	printf("printf =  %s %d \n", D_name, score);

	fprintf(fp, "%s %d", D_name, score); /* test.txt파일에 키보드로 입력한내용이 저장됨*/
	fclose(fp);

	// test파일 만들어 있는지 fscanf()로 읽어 확인 한다.
	if ((sfp = fopen("D://CJY(VC)/test.txt", "r")) == NULL) {   /* fprintf()에 의해 생성된 test 파일을 읽음 */
		printf("Can not open test file. \n");
		exit(1);
	}
	printf("\ntext  파일에 저장된 내용이 ");
	fscanf(sfp, "%s %d", D_name, &score);  /* text 화일로부터읽음*/
	fprintf(stdout, "%s %d 임을 확인하세요\n\n", D_name, score);
	/* 화면출력  printf()와 같음*/
	fclose(sfp);
	

	getch();
	return 0;
}