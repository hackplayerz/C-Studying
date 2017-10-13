/* 실습5.6-2 1800년부터 2012년까지 윤년을	구하여 출력 */
#include <stdio.h>						// Standard Input Output Header
#define FIRST_YEAR 1800					// 연도의 시작
#define LAST_YEAR 2012					// 연도의 끝

void main() {
	int i, j = 0, num = 0;
	int year[LAST_YEAR - FIRST_YEAR];	// 윤년을 저장

	printf("%d년부터 %d년까지 윤년 리스트\n", FIRST_YEAR, LAST_YEAR);
	for (i = FIRST_YEAR; i <= LAST_YEAR; i++) {
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
			year[++j] = i;
		}								// 윤년을 계산하여 year에 저장
		num = j;
	}
	for (j = 1; j <= num; j++) {
		printf("%d	", year[j]);
		if (j % 10 == 0)
			printf("\n");
	}									// 윤년을 출력 10개씩 줄바꿈
	printf("\n");
}