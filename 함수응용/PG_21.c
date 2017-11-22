/* 2017-11-22 score.h파일을 이용해 학생의 점수를 구하는 프로그램 */
#include <stdio.h>		// Standard Input Output Header
#include "score.h"		// 점수를 define으로 정의해 저장된 헤더
#define STUDENTNUM 5

void main()
{
	int score[STUDENTNUM];
	char grade[STUDENTNUM];
	int num;

	for (num = 0; num<STUDENTNUM; num++)
	{
		printf("\n Input the score => ");
		scanf("%d", &score[num]);
	}
	for (num = 0; num<STUDENTNUM; num++)
	{
		if (score[num] <= PERFECT && score[num] >= A)
			grade[num] = 'A';
		else if (score[num]<A && score[num] >= B)
			grade[num] = 'B';
		else if (score[num]<B && score[num] >= C)
			grade[num] = 'C';
		else if (score[num]<C && score[num] >= D)
			grade[num] = 'D';
		else if (score[num]<D)
			grade[num] = 'F';
	}
	printf("\n  SCORE	GRADE  \n");
	for (num = 0; num<STUDENTNUM; num++)
		printf("   %d	  %c\n", score[num], grade[num]);
}