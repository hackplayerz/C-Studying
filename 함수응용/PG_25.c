/* 2017-11-23 Switch - case ���� ����� ��Ģ������ ����ϴ� ���α׷� */
#include <stdio.h>
#include "oper.h"

int main(void) {
	int num_1, num_2, sum;
	char oper;
	while (1) {
		printf("***���α׷��� �����Ϸ��� 'q'�� �Է��ϼ���.***\n\n");
		printf("���� ���ÿ� : ");
		scanf("%d %c %d", &num_1, &oper, &num_2);

		switch (oper)
		{
		case '+':
			sum = add(num_1, num_2);
			break;
		case '-':
			sum = sub(num_1, num_2);
			break;
		case '*':
			sum = mul(num_1, num_2);
			break;
		case '/':
			sum = div(num_1, num_2);
			break;
		default:
			printf("�߸��� �����ڸ� �Է��ϼ̽��ϴ�.\n");
			continue;
		}
		printf("\nResult : %d %c %d = %d\n", num_1, oper, num_2, sum);
	}

	return 0;
}