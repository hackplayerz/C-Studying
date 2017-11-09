/* 2017-11-02 ������ ���� ���α׷� */
#include <stdio.h>				// Standard Input Output Header
#include <string.h>				// Standard String Header

int ValidityCheck(char *str);

main() {
	char equation[50];

	while (1) {
		printf("������ �Է�(exit �Է� �� ����) : ");
		gets_s(equation, sizeof(equation));

		if (!strcmp(equation, "exit")) {	// ����ڰ� "exit"�� ġ�� ���α׷� ����
			printf("�����մϴ�.\n");
			break;
		}
		else if (!ValidityCheck(equation))
			printf("�߸��� �������Դϴ�.\n\n");
		else
			printf("�������� �������Դϴ�.\n\n");
	}
}

int ValidityCheck(char *str) {

	int i, token, numberFlag = 0, operFlag = 0, unknownQuantityFlag = 0;

	/* ��ū �з� (�ڿ����� 0, �����ڴ� 1, �������� 2) */
	for (i = 0; str[i] != '\0'; i++) {

		if (str[i] >= '0'&&str[i] <= '9')
			token = 0;		// �ڿ����ϋ� token = 0
		else if (str[i] == '+' || str[i] == '-')
			token = 1;		// �����������϶� token = 1
		else if (str[i] >= 'a' || str[i] <= 'z') {
			token = 2;		// ������ ��ū ����
		}
		else {
			printf("�߸��� ���� �Է� �߸��� ���� �ε���: %d\n", i);
			return 0;
		}

		if (token == 0) {	// �ڿ��� ��ū			
			if (numberFlag) // �ڿ����� ������ ������ ��(�ڿ��� ������ ��)
				continue;

			else if (unknownQuantityFlag) {	// ������ �ڿ� �ڿ����� ���� ��
				printf("���� ���۵Ǵµ� �����ڰ� �����ϴ�. �߸��� ���� �ε���: %d\n", i);
				return 0;		// ���� ���� ���� �� �����ڰ� ���� ���� ����
			}

			else {
				numberFlag = 1; //�ڿ��� ���� on ����
				operFlag = 0;	//�� �������� ������ ���� off ����
			}
		}
		else if (token == 1) {	// ������ ��ū			
			if (operFlag) {		// ������ ������ �����ڰ� ���� ����
				printf("���� �����ڷ� ����. �߸��� ���� �ε���: %d\n", i);
				return 0;
			}
			else {
				operFlag = 1;	// ������ ���� on ����
				numberFlag = 0;
				unknownQuantityFlag = 0;
				// �� �����̹Ƿ� �ڿ��� ����, ������ ���� off ����
			}
		}

		else {							// ��ū�� �������϶�				
			if (unknownQuantityFlag) {
				continue;
			}

			else {						// �� �����̹Ƿ� �ڿ�������, ������ ���� off ����
				unknownQuantityFlag = 1;
				operFlag = 0;
				numberFlag = 0;
			}
		}
	}
	if (token == 1) {					// ���������� �������Ͻ� �׿� ������ �߻� 
		printf("���������� �������Դϴ�.");
		return 0;
	}
	return 1;
}
