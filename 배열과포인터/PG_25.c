/* 2017-12-06 포인터를 이용한 정수 배열의 연산 */
#include <stdio.h>

void main() {
	int i;
	int array[] = { 10,20,30,40,50 };
	int *ptr;
	ptr = array;
	printf("ptr의 주소       : %d\n", &ptr);
	printf("ptr의 값         : %d\n", ptr);
	printf("array 시작 주소  : %d\n", array);

	for (i = 0; i < 5; i++) {
		printf("array[%d]의 주소 : %d ==> %d\n", i, &array[i], array[i]);
	}
		printf("\n");

		printf("*(ptr+2)   : %d \n", *(ptr + 2));
		printf("*(ptr+2)+6 : %d \n\n", *(ptr + 2) + 6);

		printf("     ptr+2 : %d \n", ptr + 2);
		printf(" (ptr+2)-1 : %d \n", (ptr + 2) - 1);
		printf("*(ptr+2)-1 : %d \n\n", *(ptr + 2) - 1);
	
}