/*2017-09-07 ����ü�� ����ü�� ũ���*/
#include "myheader.h"
union wk {
	int i;
	float f;
} wka;   // ���Ͽ� ����  wka(4����Ʈ) ����

struct wka {
	int i;
	float f;
} wkb;  // �������� wkb(8����Ʈ) ���� 

int main(void)
{
	printf("���Ͽ� ������ ����ü������ ũ�⸦ Ȯ���Ͻÿ�? \n");
	printf("���Ͽ� ���� wka �� ũ���    =  %d Bytes\n", sizeof(wka));
	printf("����ü����  wkb ��ũ���     =  %d Bytes\n\n", sizeof(wkb));

	getch();
	return 0;
}