/* 2017-11-02 Report �ǽ� 3 �������Ǻ� ���α׷� */
#include <stdio.h>

int ValidityCheck(char *str);		// ������ �Ǻ��Լ� ����

void main() {
	char equation[50];

	while (1) {
		printf("������ �Է� : ");
		gets_s(equation, sizeof(equation));				// ����ڷκ��� ���� �޾ƿ�

		if (!ValidityCheck(equation))
			printf("�߸��� ������ �Դϴ�.\n\n");
		else
			printf("�������� ������ �Դϴ�.\n\n");
	}
}
int ValidityCheck(char *str)
{
	int i, token, numberFlag = 0, operFlag = 0;

	for (i = 0; str[i] != '\0'; i++) {
		//��ū �з� (�ڿ����� 0, �����ڴ� 1
		if (str[i] >= '0' && str[i] <= '9')  token = 0;
		else if (str[i] == '+' || str[i] == '-') token = 1;
		else {  //�߸��� ���ڴ� ����
			printf("�߸��� ���� ����. ");
			return 0;
		}
		if (token) { //��ū�� �������� ��
			if (operFlag) { //������ ������ �����ڰ� ���� ����
				printf("���� �����ڷ� ����. ");
				return 0;
			}
			else {
				operFlag = 1;  //������ ���� on ����
				numberFlag = 0;  //�������̹Ƿ��ڿ������� off����
			}
		}
		else {
			//�ڿ����� ������ ������ ��(�ڿ��� ������ ��)
			if (numberFlag) continue;
			else {
				numberFlag = 1;
				operFlag = 0;
			}
		}
	}
	return 1;
}