/*	2017-09-06 ����ü�� ���� ������*/
#include "myheader.h"
#define LEN 25

struct author {
	char first[LEN];
	char last[LEN];
};						// ����ü author ����

int main(void) {
	static struct author names = { "Harby","Deitel" };
	struct author *ptr;	// ������ ������ *ptr����
	ptr = &names;		// ptr�� names�� �ּҸ� ����

	printf("����ü ���� names ���\n");
	printf("å�� ���ڸ� �̸� names.first : %s\n", names.first);
	printf("å�� ���ڸ� ��   names.last : %s\n\n", names.last);

	printf("����ü ������ptr ��� [name�� (*ptr)�� ����]\n");
	printf("å�� ���ڸ� �̸�(*ptr).first : %s\n", (*ptr).first);
	printf("å�� ���ڸ� ��  (*ptr).last : %s\n\n",(*ptr).last);

	printf("����ü ������ ptr ���[(*ptr)�� ptr->�� ����]\n");
	printf("å�� ���ڸ� �̸� ptr->first : %s\n", ptr->first);
	printf("å�� ���ڸ� ��   ptr->last : %s\n\n", ptr->last);

	getch();
	return 0;
}