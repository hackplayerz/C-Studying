/* 2017-11-09 do - while */
#include <stdio.h>

void main()
{
	// for문
	int i;
	int hap = 0;
	for (i = 0; i <= 10; i++)
	{
		hap = hap + i;
	}
	printf("for문   : hap = %d\n", hap);
	//while문
	i = 1;
	hap = 0;
	while (i <= 10)
	{
		hap = hap + i;
		i++;
	}
	printf("while문 : hap = %d\n", hap);
	//do - while문
	i = 1;
	hap = 0;
	do
	{
		hap = hap + i;
		i++;
	} while (i <= 10);
	printf("while문 : hap = %d\n", hap);
}
