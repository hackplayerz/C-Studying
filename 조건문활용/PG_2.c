/* 2017-11-09 ���ǹ� Ȱ�� ���α׷� */
#include <stdio.h>
void main()
{
	// if�� ~ if ~ elseif ~ else ��
	int i = 1;
	int j = 2;
	int k = 7;
	if (i == 1) {
		if (j == 2) {
			if (k == 3)
				printf("i=1, j=2, k=3�Դϴ�.\n");
			else if (k == 4)
				printf("i=1, j=2, k=4�Դϴ�.\n");
			else if (k == 5)
				printf("i=1, j=2, k=5�Դϴ�.\n");
			else
				printf("i=1, j=2, k=%d�Դϴ�.\n", k);
		}
	}
	//switch��
	int m = 3;
	switch (m) {
	case 3:
		printf("i=1, j=2, m=%d�Դϴ�.\n", m);
		break;
	case 4:
		printf("i=1, j=2, m=%d�Դϴ�.\n", m);
		break;
	case 5:
		printf("i=1, j=2, m=%d�Դϴ�.\n", m);
		break;
	default:
		printf("i=1, j=2, m=%d�Դϴ�.\n", m);
		break;
	}
}
