#include <stdio.h>
#include <conio.h>

void main() {
	int x, y;
	
	printf("******RESULT******\n\n");
	printf("%d %d", &x, &y);

	if (x + y)
		printf("x+y is greater than zero\n");
	else
		printf("x+y is equal to or less than zero\n");

	getch();
	return 0;
}