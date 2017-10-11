#include <stdio.h>
#define size 8

void Reverse(int *arr);
void main() {
	int decimal = 254, i = 0;
	int binary[size];
		//10���� 13�� 1���� Ŭ ����
	while (decimal > 1)
	{
		//�迭�� 2�� ���� �������� ���ʷ� ����
		binary[i++] = decimal % 2;
		//10���� 13�� 2�� ������ ���� ������
		decimal /= 2;
	}
		//�������� ����  1�� �迭�� ���� ����
	binary[i] = 1;

	Reverse(binary);
	for (i = 0; i < size; i++)
		printf("%d", binary[i]);

	printf("\n\n");
}

		//�迭�� �������� ������ ����� ���� �Լ�
void Reverse(int *arr)
{
	int temp[size];
	int i;

		//�ӽ� �迭 temp�� �����͸� �Ųٷ� ����
	for (i = 0; i < size; i++)
		temp[i] = arr[size - i - 1];

		//���� �迭�� �ӽ� �迭���� ����
	for (i = 0; i < size; i++)
		arr[i] = temp[i];
}