/*	2017-8-31 ����ü	Report	*/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <conio.h>

struct book {
	char title[20];
	char author[25];
	float value;
};

struct book book1 = { "Operating system", "Stallings", 15000.0 };
struct book book2 = { "Database system", " Korth", };	//	����ü book2�� value�� ���� �ʱ�ȭ

int main(void)
{
	printf("����ü���� : book1 \n");					// ����ü���� book1�� member�� ���
	printf("å������   : %s \n", book1.title);
	printf("å������   : %s \n", book1.author);
	printf("å�ǰ���   : %7.1f \n\n", book1.value);

	printf("����ü���� : book2 \n");					// ����ü���� book2�� member�� ��� 
	printf("å������   : %s \n", book2.title);
	printf("å������   : %s \n", book2.author);
	printf("å�ǰ���   : %7.1f \n\n", book2.value);		// �ʱⰪ ����  
	getch();
	return 0;
}
