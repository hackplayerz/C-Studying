/* 2017-09-21 printf() */
#include <stdio.h>
#include <conio.h>

int main(void){
	int n = - 123, m = 123;
	printf("[n = %d],\t",n);
	printf("[m = %d]\n", m);
	printf("n = %7d],\t", n);
	printf("[m = %+d]\n", m);
	printf("[n = %+7d],\t", n);
	printf("[m = %+7d\n", m);
	printf("[n = %-7d],\t", n);
	printf("[m = %-7d]\n", m);
	printf("[n = %-+d],\t", n);
	printf("[m = %-+d]\n", m);

	getch();
	return 0;
}
