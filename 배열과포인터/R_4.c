/* �ǽ�����11.4_1 �迭 ��� ���α׷� */
#include <stdio.h>

int SearchList(int a[], int b);
void main() {
	int list[5] = { 24, 21, 34, 11, 55 };
	int searchVal;
	int idx = -1;
	printf("Ž�� �� �Է� : ");
	scanf("%d", &searchVal);
	if ((idx = SearchList(list, searchVal)) != -1) {
		printf("Ž�� �� ���� %d �̸� �迭�� %d ��° ���Դϴ�.\n\n", searchVal, idx);
	}
	else {
		printf("%d ���� �迭�� �����ϴ�.\n", searchVal);
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