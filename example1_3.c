/* �ǽ����� 1-3 */
#include "myheader.h"

int main(void) {
	int num = 913901;
	int grade[3] = { 89,100,95 };
	int i, avg = 0;;
	
	for (i = 0; i < 3; i++) {
		avg += grade[i];
	}						// sum of grades

	printf("�й�\t: %07d\n", num);
	printf("=================\n");
	printf("����\t: %3d<��>\n", grade[0]);
	printf("�����\t: %3d<��>\n",grade[1]);
	printf("����\t: %3d<��>\n", grade[2]);
	printf("=================\n");
	printf("���\t: %3d<��>\n", avg/3);
							//print average

	getch();
	return 0;
}