/* 2017-11-22 score.h������ �̿��� �л��� ������ ���ϴ� ���α׷� */
#include <stdio.h>		// Standard Input Output Header
#include "score.h"		// ������ define���� ������ ����� ���
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