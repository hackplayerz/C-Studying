#include "myheader.h"

int main(void) {
	int i = 1, a = 0;
	char ch = 0;
	char str[20];
	while (1)
	{
		printf("%d 번째 루프\n", i++);
		scanf("%d", &a);				// get inteager from keyboard
		printf("%d\n", a);
		getchar();						// Clean buffer
		scanf("%c", &ch);
		printf("%c\n", ch);
		getchar();
		scanf("%c", &ch);
		printf("%c\n", ch);

		if (getchar() == 'q') {			// break loop
			break;
		}
	}

	getch();
	return 0;
}