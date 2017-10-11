/* 실습예제 1-2 */
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(void)
{
	char Name[] = "홍길동";
	int len = strlen(Name);		// strlen() -> length of Name funcion

	printf("%6s %6s\n", Name, Name);
	printf("%6d %-6d\n\n", len, len);

	printf("%6s %6s\n", Name, Name);
	printf("%6.1f %-6.1f\n\n", (float)len, (float)len);
	// change cast to float
	getch();
	return 0;
}