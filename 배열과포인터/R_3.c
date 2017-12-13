/* 실습에제 11.3 */
#include <stdio.h>
#define ARRAY 10

void BubbleSort(int *a);
void printList(int list[]);
void main() {
	int list[ARRAY];

	for (int i = 0; i < ARRAY; i++)
		list[i] = i + 1;

	printf("정렬 전 : ");
	printList(list);
	BubbleSort(list);
	printf("정렬 후 : ");
	printList(list);
}
void BubbleSort(int *a) {
	int temp, i, j;
	for (i = 0; i<ARRAY; i++) {
		for (j = i + 1; j < ARRAY; j++) {
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void printList(int list[]) {
	int i = 0;
	for (i = 0; i<ARRAY; i++)  printf("%5d", list[i]);
	printf("\n");
}
