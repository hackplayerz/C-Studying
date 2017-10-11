/* 실습예제 1-3 */
#include "myheader.h"

int main(void) {
	int num = 913901;
	int grade[3] = { 89,100,95 };
	int i, avg = 0;;
	
	for (i = 0; i < 3; i++) {
		avg += grade[i];
	}						// sum of grades

	printf("학번\t: %07d\n", num);
	printf("=================\n");
	printf("국어\t: %3d<점>\n", grade[0]);
	printf("세계사\t: %3d<점>\n",grade[1]);
	printf("수학\t: %3d<점>\n", grade[2]);
	printf("=================\n");
	printf("평균\t: %3d<점>\n", avg/3);
							//print average

	getch();
	return 0;
}