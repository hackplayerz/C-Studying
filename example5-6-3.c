/* 2017-10-18 �ǽ�����3 */
#include <stdio.h>							// Standard Input Output Header
#include <conio.h>							// Console Input Output Header
#pragma warning (disable:4996)

void main() {
	char input[100];						// ������ ���ڸ� ������ ���� ����
				/* ������ ���ڸ� ������ ������ ���� */
	char inteager[40];						
	char upper[40];							
	char down[40];
	char ect[40];

	int i, in = 0, d = 0, u = 0, e = 0;

	printf("�Է� :");
	gets_s(input,sizeof(input));			// ����ڷκ��� ���ڸ� �޾ƿ�

	for (i = 0; input[i] != NULL; i++) {	// ����ڷκ��� �޾ƿ� ������ �з�
		if ('0' <= input[i] && input[i] <= '9') {
			inteager[in++] = input[i];
		}
		else if ('a' <= input[i] && input[i] <= 'z') {
			down[d++] = input[i];
		}
		else if ('A' <= input[i] && input[i] <= 'Z') {
			upper[u++] = input[i];
		}
		else
			ect[e++] = input[i];

		inteager[in] = NULL;
		down[d] = NULL;
		upper[u] = NULL;
		ect[e] = NULL;						// �з��ѵ� ������ ���� ESCAPE���ڸ� �����Ͽ� ���ڿ��� ���� �˷���
	}
	printf("���� : %s", inteager);
	printf("�ҹ��� : %s\n", down);
	printf("�빮�� : %s\n", upper);
	printf("��Ÿ : %s\n", ect);				// �з��� ���ڸ� ���
}