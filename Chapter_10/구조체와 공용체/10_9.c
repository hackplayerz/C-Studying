/*2017-09-07 ����ü(Union)*/
#include "myheader.h"
void main()
{
	union book {
		char title[25];
		char author[25];
		float value;
	}book1;    // ���Ͽº��� book1 �μ���
	printf("Union size is %d Bytes\n\n", sizeof(book1));
	/*	union ���𿡼� Turbo C������ 25 bytes�� ��Ÿ��
		Visual Studio(C++)������ ����� �Ǽ��� 4 bytes �� ����
		���� ũ���� 28 bytets�� ������.	*/
	getch();
	return 0;
}