
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// findMax, findMin�� ���� ��ũ�� ����
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))

// ���� ū(����) ��, �׸��� �� ��°�� ū(����) ���� �����ϱ� ���� �����迭 arrMm ����
int arrMm[2] = { 0 };

// �����ȭ���� ����ϴ� �Լ�
int PrintUI(void);

// �����ȭ���� �������ִ� �Լ�
void clearScreen(int arr[], int n);

// findMax, findMin : ���� ū, ���� ���� �������ִ� �Լ�
int findMax(int arr[], int n);
int findMin(int arr[], int n);

// secMax, secMin : �ι�°�� ū, ���� ���� �����迭 arrMm[1]�� �����ϴ� �Լ�
int secMax(int arr[], int n);
int secMin(int arr[], int n);

void main()
{
	// main �Լ����� ���ʰ� �� �迭�� ������ �Է¹޴´�.
	int arr[100] = { 0 };
	int n;
	int i;
	int nMenu;
	int nMax;
	int nMin;

	clock_t start, finish;
	double duration;
	printf("�迭�� �� ���� �����͸� �Է��Ͻðڽ��ϱ�? ");
	scanf_s("%d", &n);

	printf("%d���� �����͸� �Է����ּ���\n", n);
	for (i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	putchar('\n');

	// ������� �޴� ���ÿ� ���� �� �޴��� ����ð��� �����Ѵ�.
	while ((nMenu = PrintUI()) != 0)
	{
		switch (nMenu)
		{
		case 1:
		{
			start = clock();
			clearScreen(arr, n);
			nMax = findMax(arr, n - 1);
			printf("�Էµ� �� �� ���� ū ���� %d �Դϴ�.\n", nMax);
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			printf("���α׷� ����ð�: %f ��\n\n", duration);
			break;
		}
		case 2:
		{
			start = clock();
			clearScreen(arr, n);
			nMin = findMin(arr, n - 1);
			printf("�Էµ� �� �� ���� ���� ���� %d �Դϴ�.\n", nMin);
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			printf("���α׷� ����ð�: %f ��\n\n", duration);
			break;
		}
		case 3:
		{
			start = clock();
			clearScreen(arr, n);
			secMax(arr, n - 1);
			printf("�Էµ� �� �� 2��°�� ū ���� %d �Դϴ�.\n", arrMm[1]);
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			printf("���α׷� ����ð�: %f ��\n\n", duration);
			break;
		}
		case 4:
		{
			start = clock();
			clearScreen(arr, n);
			secMin(arr, n - 1);
			printf("�Էµ� �� �� 2��°�� ���� ���� %d �Դϴ�.\n", arrMm[1]);
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			printf("���α׷� ����ð�: %f ��\n\n", duration);
			break;
		}
		}
	}
	exit(1);
}

int PrintUI(void)
{
	int n = 0;
	printf("���ϴ� ��ɿ� �ش��ϴ� ��ȣ�� �Է� ���ּ���.\n");
	printf("1��: �ִ밪�� ���Ѵ�.\n");
	printf("2��: �ּڰ��� ���Ѵ�.\n");
	printf("3��: �� ��°�� ū ���� ���Ѵ�.\n");
	printf("4��: �� ��°�� ���� ���� ���Ѵ�.\n");
	printf("0��: ���α׷��� �����մϴ�.\n");
	scanf_s("%d", &n);
	return n;
}

void clearScreen(int arr[], int n)
{
	int i;
	system("cls");
	printf("\n�� ��ҿ� �Էµ� �����͸� ����մϴ�.\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');
}

int findMax(int arr[], int n)
{
	if (n == 1)
		return MAX(arr[n], arr[n - 1]);
	return MAX(arr[n], findMax(arr, n - 1));
}

int findMin(int arr[], int n)
{
	if (n == 1)
		return MIN(arr[n], arr[n - 1]);
	return MIN(arr[n], findMin(arr, n - 1));
}

// �Ʒ��� ���̴� �� �Լ� secMax �� secMin �� ���� ū Ư¡��, �����迭�� �̿��Ѵٴ� ���̴�.
// ��ȯ�� ������ (��, �迭�� �ε����� 0�� 1�� ��) ���� �ش� ��ҵ��� �����迭 arrMm[0], arrMm[1]�� ���� �����Ѵ�.
// arrMm[0]���� ���� ū(����) ���� ����� ���̰�, arrMm[1]���� �ι�°�� ū(����) ���� ����� ���̴�.
int secMax(int arr[], int n)
{
	int nIndex;
	if (n == 1)
	{
		if (arr[n] > arr[n - 1])
		{
			arrMm[0] = arr[n];
			arrMm[1] = arr[n - 1];
			return n;
		}
		else
		{
			arrMm[0] = arr[n - 1];
			arrMm[1] = arr[n];
			return n - 1;
		}
	}
	nIndex = secMax(arr, n - 1);
	if (arr[n] > arr[nIndex])
	{
		arrMm[1] = arrMm[0];
		arrMm[0] = arr[n];
		return n;
	}
	else
	{
		if (arrMm[1] < arr[n] && arr[n] != arrMm[0])
			arrMm[1] = arr[n];
		return nIndex;
	}
}

int secMin(int arr[], int n)
{
	int nIndex;
	if (n == 1)
	{
		if (arr[n] < arr[n - 1])
		{
			arrMm[0] = arr[n];
			arrMm[1] = arr[n - 1];
			return n;
		}
		else
		{
			arrMm[0] = arr[n - 1];
			arrMm[1] = arr[n];
			return n - 1;
		}
	}
	nIndex = secMin(arr, n - 1);
	if (arr[n] < arr[nIndex])
	{
		arrMm[1] = arrMm[0];
		arrMm[0] = arr[n];
		return n;
	}
	else
	{
		if (arrMm[1] > arr[n] && arr[n] != arrMm[0])
			arrMm[1] = arr[n];
		return nIndex;
	}
}