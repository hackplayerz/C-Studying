/* 2017-11-09 do - while */
#include <stdio.h>

void main()
{
	// for��
	int i;
	int hap = 0;
	for (i = 0; i <= 10; i++)
	{
		hap = hap + i;
	}
	printf("for��   : hap = %d\n", hap);
	//while��
	i = 1;
	hap = 0;
	while (i <= 10)
	{
		hap = hap + i;
		i++;
	}
	printf("while�� : hap = %d\n", hap);
	//do - while��
	i = 1;
	hap = 0;
	do
	{
		hap = hap + i;
		i++;
	} while (i <= 10);
	printf("while�� : hap = %d\n", hap);
}
