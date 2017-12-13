/* 실습에제11.4_1 배열 사용 프로그램 */
#include <stdio.h>

int SearchList(int a[], int b);
void main() {
	int list[5] = { 24, 21, 34, 11, 55 };
	int searchVal;
	int idx = -1;
	printf("탐색 값 입력 : ");
	scanf("%d", &searchVal);
	if ((idx = SearchList(list, searchVal)) != -1) {
		printf("탐색 한 값은 %d 이며 배열의 %d 번째 값입니다.\n\n", searchVal, idx);
	}
	else {
		printf("%d 값은 배열에 없습니다.\n", searchVal);
	}
}
int SearchList(int a[], int b) {
	int i;
	for (i = 0; i < 5; i++) {
		if (a[i] == b) {
			return i;
		}
	}
	return -1;
}