/* Wonkwang Univ. 2017-09-06 ����ü�� ���� ������ �Լ��� �����ϴ� ��� */
#pragma warning(disable:4996)
#include <stdio.h>
#define SIZE 100
#define LIST struct list

LIST{
	char initial;
char sex;
char age;
};

void inpt(LIST *pman)
{
	char in[6], sx[6];
	int ag;

	printf("\n Initial  Sex  Age => ");
	scanf("%ls %ls %d", in, sx, &ag);
	pman->initial = *in;/* ���տ�����(a *= 1)�� �ƴ�,*in�� in�� ����� ������ �ִ� ��  */
	pman->sex = *sx;
	pman->age = ag;
}
void prnt(LIST *array, int bz)
{
	int j;
	printf("\n Num	Initial	Sex	Age\n");
	printf("---------------------------\n");
	for (j = 0; j <= bz; j++)
		printf("%d %c %c %d\n", j, (array + j)->initial, (array + j)->sex, (array + j)->age);
}

void main()
{
	int i, key;
	LIST man[SIZE];
	LIST *pm = man;

	for (i = 0; i<SIZE; i++) {
		inpt(pm++);
		printf("\n go - 0, stop - 9 => ");
		scanf("%d", &key);
		if (key == 9) {
			break;
		}
	}
	printf(" input == end!\n");
	prnt(man, i);
}