/* 2017-11-16 �������� �����ִ� ���α׷� */
#include <stdio.h>

void SquareSolve(int size);			// �������� SIZE�� �޾ƿ��� �Լ�
void printSquare(int size);			// �������� ����ϴ� �Լ�							
void MagicSquareOdd(int size);		// Ȧ�� ������
void MagicSquare4x(int size);		// 4��� ������
void MagicSquareElseEven(int size);	// 4����� �ƴ� ¦�� ������

int magicSquare[9][9];				// ������ �迭

main()								// main
{
	int size;

	while (1) {
		printf("������ ����� �Է��ϼ���\n(�ּ� ������ 3 - �ִ� ������ 20 / ����� 0)\n�Է� >> ");
		scanf("%d", &size);

		if (size == 0) {
			printf("�����մϴ�.\n");
			return;
		}
		else if (size<3 || size>20) {
			printf("�Է� ����! �ٽ� �Է��ϼ���.\n\n");
			continue;
		}
		SquareSolve(size);
	}
}
/* �Է��� ���� ���� ������ �Լ��� �̵� */

void SquareSolve(int size) {
	printf("������ Ǯ�̸� �����մϴ�.\n");
	printf("�Է��Ͻ� ������ ������� %d��, ", size);
	switch (size % 4) {
	case 0:
		printf("4��� ���������� Ǯ���մϴ�.\n\n");
		MagicSquare4x(size);
		break;
	case 1: case 3:
		printf("Ȧ�� ���������� Ǯ���մϴ�.\n\n");
		MagicSquareOdd(size);
		break;
	case 2:
		printf("4����� �ƴ� ¦�� ���������� Ǯ���մϴ�.\n\n");
		MagicSquareElseEven(size);
		break;
	}
}
/* ����� ���� �Լ� */
void printSquare(int size)
{
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			printf("%4d", magicSquare[i][j]);
		printf("\n");
	}
	printf("\n\n");
}
/* Ȧ�� ������ ���α׷� */
void MagicSquareOdd(int size) {
	int i = size / 2;
	int j = size - 1;;
	int oldi, oldj;
	int k, l;


	printf("1�� �� �ʱ��� ��ǥ : <%2d,%2d > \n", i, j);
	printf("������ Ǯ��\n");
	for (l = 0; l<size; l++) {
		for (k = 0; k<size; k++)
			magicSquare[l][k] = 0;
	}

	for (l = 0, k = 0; k<size*size; l++) {
		oldi = i;
		oldj = j;
		magicSquare[i--][j++] = ++k;
		if (i<0) i = size - 1;
		if (j>size-1)j=0;                   
		if (magicSquare[i][j]!=0) {
			i = oldi;
			j = oldj - 1;
		}
	}
	printSquare(size);
}
/* 4��� ������ ���α׷� */
void MagicSquare4x(int size) {
	int i, j, k, temp = 0;
	printf("1�ܰ� : ������� ���� �迭\n");
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			magicSquare[i][j] = i*size + j + 1;
			printf("%4d", magicSquare[i][j]);
		}
		printf("\n");
	}
	printf("\n2�ܰ� : ������ Ǯ��\n");
	for (j = 0; j<size / 4; j++) {
		for (i = size / 4; i <3 * size / 4; i++) {
			//���κκ� ��Ī
			temp = magicSquare[i][j];
			magicSquare[i][j] = magicSquare[size - i - 1][size - j - 1];
			magicSquare[size - i - 1][size - j - 1] = temp;
			//���κκ� ��Ī
			temp = magicSquare[j][i];
			magicSquare[j][i] = magicSquare[size - j - 1][size - i - 1];
			magicSquare[size - j - 1][size - i - 1] = temp;

		}
	}
	printSquare(size);
	printf("\n\n");
}
/* 4�� ����� �ƴ� ¦�� ������ ���α׷� */
void MagicSquareElseEven(int size) {
	int i, j;
	int temp[20][20] = { 0, }; // ������ ������ �迭
	printf("1�ܰ� : size/2 ũ���� Ȧ�� ������ ����\n");
	MagicSquareOdd(size / 2); // Ȧ�� ������ ����
	printSquare(size / 2);
	printf("\n");

	printf("1���� �� ��� \n");
		//1 ����
		for (i = 0; i<size / 2; i++) {         //��ü ������ ���� size/2���� ������.
			for (int j = 0; j<size / 4; j++) {  //��ü ������ ���� size/4�� ������.
				if (i == size / 4)     //��� ���� ó�� �ڸ��� 0�� ���� ä���,
					temp[i][j + 1] = 3; //�� �ڿ� (size/4)���� 3�� ä���.
				else
					temp[i][j] = 3; //floor(size/4)���� 3�� ���ʿ������� 
			}                                  // ä���.
		}
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			printf("%4d", temp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("2���� �� ���\n");
		//2 ����
		for (i = 0; i<size / 2; i++) {
			for (int j = 0; j<size / 2; j++) {
				if (j<((int)(size / 2 - 1)))
					temp[i][size / 2 + j] = 2;  //ceil(size/2-1) ���� 
												//2�� ���ʿ������� ä���.
				else
					temp[i][size / 2 + j] = 1;  //������ �ڸ��� ��� 1�� 
			}                                               // ä���.
		}
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			printf("%4d", temp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("3, 4���� �� ���\n");
	//3,4 ����
	for (i = 0; i<size / 2; i++) {
		for (j = 0; j<size / 2; j++) {
			if (temp[i][j] == 0)       //1���� ���� �ݴ�� ä���.
				temp[size / 2 + i][j] = 3; // (3 ��� 0����, 0 ��� 3����)
			else
				temp[size / 2 + i][j] = 0;
		}
		for (j = 0; j<size / 2; j++) {
			if (temp[i][size / 2 + j] == 2)//2���� ���� �ݴ�� ä���.
				temp[size / 2 + i][size / 2 + j] = 1;
			else                                    //(2 ��� 1��, 1 ��� 2��)
				temp[size / 2 + i][size / 2 + j] = 2;
		}
	}
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			printf("%4d", temp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//��Ŀ� ��Į��(size*size/4) ��
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			temp[i][j] *= size*size / 4;
		}
	}
	printf("2�ܰ� 1-4���� ���� size*size/4 �� ���� �� ���\n");
	//1-4������ size*size/4 �� ���� ��  ���
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			printf("%4d", temp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//�� �������� ������ Ȧ�� ������ ����
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			temp[i][j] += magicSquare[i % (size / 2)][j % (size / 2)];
		}
	}
	//���� �迭�� ��� �ű�
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			magicSquare[i][j] = temp[i][j];
		}
	}
	//������ ���
	printf("������ ���\n");
	printSquare(size);
}
