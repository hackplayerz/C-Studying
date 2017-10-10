#include "myheader.h"

void main()
{
	int arg;
	printf("일반적인 입력");
	printf("입력:");
	scanf("%d", &arg);
	printf("출력:%d\n", arg);

	printf("공백 하나 입력 후 입력");
	printf("입력:");
	scanf("%d", &arg);
	printf("출력:%d\n", arg);

	printf("여러 공백 입력 후 입력");
	printf("입력:");
	scanf("%d", &arg);
	printf("출력:%d\n", arg);

	printf("탭문자 입력 후 입력");
	printf("입력:");
	scanf("%d", &arg);
	printf("출력:%d\n", arg);

	printf("개행<엔터> 입력 후 입력");
	printf("입력:");
	scanf("%d", &arg);
	printf("출력:%d\n", arg);

	getch();
	return 0;
}
