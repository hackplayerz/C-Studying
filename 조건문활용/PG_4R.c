/* 2017-11-09 Report 반복문 활용 프로그램 */
#include <stdio.h>
void main()
{
	// for문
	int i;
	int hap = 0;
	for (i = 0; i <= 10; i++) {
		if (i == 5) continue;
		printf("%d", i);//출력 1, 2, 3, 4, 6, 7
		hap = hap + i;
		if (i == 7) break;
	}
	printf("for문 : hap = %d\n", hap);//hap = 23
									 //while문
	i = 1;
	hap = 0;
	while (i <= 10) {
		i++;							// continue문 아래 있으면 무한루프 발생
		if (i == 5) 
			continue;
		printf("%d", i);//출력 1, 2, 3, 4, 6, 7
		hap = hap + i;
		if (i == 7)
			break;
	}
	printf("while문 : hap = %d\n", hap);//hap = 23
									   //do - while문
	i = 1;
	hap = 0;
	do {
		i++;							// continue문 아래 있으면 무한루프 발생
		if (i == 5) continue;
		printf("%d", i);//출력 1, 2, 3, 4, 6, 7
		hap = hap + i;
		if (i == 7) break;		
	} while (i <= 10);
	printf("while문 : hap = %d\n", hap);//hap = 23
}