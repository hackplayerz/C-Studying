#include <stdio.h>
void main()
{
	int i, j, su, dan;
	for (i = 0; i <= 2; i++) {
		for (su = 1; su <= 9; su++) {
			for (j = 1; j <= 3; j++) {
				dan = 3 * i + j;
				printf("%d * %d = %2d\t", dan, su, dan*su);
			}
			printf("\n");
		}
		printf("\n");
	}
}