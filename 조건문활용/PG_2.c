/* 2017-11-09 조건문 활용 프로그램 */
#include <stdio.h>
void main()
{
	// if문 ~ if ~ elseif ~ else 절
	int i = 1;
	int j = 2;
	int k = 7;
	if (i == 1) {
		if (j == 2) {
			if (k == 3)
				printf("i=1, j=2, k=3입니다.\n");
			else if (k == 4)
				printf("i=1, j=2, k=4입니다.\n");
			else if (k == 5)
				printf("i=1, j=2, k=5입니다.\n");
			else
				printf("i=1, j=2, k=%d입니다.\n", k);
		}
	}
	//switch문
	int m = 3;
	switch (m) {
	case 3:
		printf("i=1, j=2, m=%d입니다.\n", m);
		break;
	case 4:
		printf("i=1, j=2, m=%d입니다.\n", m);
		break;
	case 5:
		printf("i=1, j=2, m=%d입니다.\n", m);
		break;
	default:
		printf("i=1, j=2, m=%d입니다.\n", m);
		break;
	}
}
