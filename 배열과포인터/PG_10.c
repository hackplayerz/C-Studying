/* 2017-11-30 �������迭�� �ʱ�ȭ �� ���� ũ�Ⱑ ������ 2���� �迭 ����*/
#include <stdio.h>

void main()
{
	int array[][4] = { { 50, 80, 0 },{ 2, },{ 121, 0, 0 }, 1, 2 };

	int i, j, size;

	size = sizeof(array) / sizeof(int) / 4;

	for (i = 0; i < size; i++) {
		for (j = 0; j < 4; j++)
			printf("array[%d][%d] = %d\n", i, j, array[i][j]);

		printf("\n");
	}
}