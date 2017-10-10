#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

typedef struct _element // �������� ����� �� ���� ����ü
{
	int row;
	int col;
	int val;
} element;

int printUI(void);
int endUI(void);
void runMatrixProgram(void);

void main()
{
	do
	{
		if (printUI() == 2)
			exit(1);
		else
			runMatrixProgram();
	} while (endUI() != -1);
	putchar('\n');
	exit(1);
}

int printUI(void)
{
	char ch;
	do
	{
		putchar('\n');
		printf("Select one of following items:\n");
		printf("\t1. Matrix program\n");
		printf("\t2. Exit\n");
		printf("Which do you want to select a number? (1-2) : ");
		if ((ch = getche()) == '1')
			return 1;
		else if ((ch = getche()) == '2')
			return 2;
	} while (ch != '1' || ch != '2');
}

int endUI(void)
{
	char ch = 0;
	do
	{
		if (ch != 0)
			putchar('\n');
		putchar('\n');
		printf("Do you want to try other program? (Y/N) : ");
		ch = getche();
	} while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');
	if (ch == 'N' || ch == 'n')
		return -1;
	else
		return 1;

}

void runMatrixProgram(void)
{
	char ch;
	int rows, cols;
	int i, j;
	int terms = 0; // �������� �����Ҵ����� ���� ��, �ʿ��� 0�� �ƴ� ���� ����
	int temp; // �����Ŀ� ���Ҹ� ������ �� ���� ī���� ����
	int cnt = 0; // ������ 6�� �ּ� ����� ���� ī���� ����
	int cntStruct = 0; // ����ü �迭�� ������ �� ���� �迭�� �ѹ� ����
	int **ppArr;
	element *pElement;

	putchar('\n');
	printf("Type the number of rows : ");
	scanf("%d", &rows);
	printf("Type the number of columns : ");
	scanf("%d", &cols);
	ppArr = (int **)malloc(sizeof(int *) * rows); // �����ü�� �����ϴ� ����� ��Ÿ�� �� ���� int **ppArr �����Ҵ�

	for (i = 0; i < rows; i++)
	{
		*(ppArr + i) = (int *)malloc(sizeof(int) * cols);
		printf("Type the %d elements of %d-th row : ", cols, i);
		for (j = 0; j < cols; j++)
		{
			scanf("%d", *(ppArr + i) + j);
			if (ppArr[i][j] != 0)
				terms++; // �������� ������ �� ���� ����, 0�� �ƴ� ������ ������ ī�����Ѵ�.
		}
	}
	temp = terms;
	pElement = (element *)malloc(sizeof(element) * terms); // �����ķ� ������ ���� �����Ҵ����� pElement ���� (terms*element ũ��� �Ҵ�)
	printf("sizeof (pElement): %d\n", sizeof(element));

	for (i = 0; i < rows; i++) // ������ �Ҵ�� �������� �������� 
	{
		for (j = 0; j < cols; j++)
		{
			if (ppArr[i][j] != 0)
			{
				pElement[cntStruct].row = i;
				pElement[cntStruct].col = j;
				pElement[cntStruct].val = ppArr[i][j];
				temp--;
				cntStruct++;
				if (temp == 0)
					break;
			}
			if (temp == 0)
				break;
		}
		if (temp == 0)
			break;
	}
	putchar('\n');

	printf("Matrix\n");
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			printf("%d ", ppArr[i][j]);
		putchar('\n');
	}
	putchar('\n');

	printf("Memory comparison\n");
	printf("1) Matrix itself representation : %d bytes\n", sizeof(int) * cols * rows);
	printf("2) Non-zero term representation : %d bytes\n", sizeof(element) * terms + sizeof(pElement) + sizeof(rows) + sizeof(cols) + sizeof(terms));


	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("mat[%d][%d]: %d (%x)\n",
				i, j, ppArr[i][j], &ppArr[i][j]);
			cnt++;
			if (cnt == 6)
				break;
		}
		if (cnt == 6)
			break;
	}
	for (i = 0; i < rows; i++)
		free(*(ppArr + i));
	free(ppArr);
	free(pElement);
}
