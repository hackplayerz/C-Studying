/*2017-09-07 ����ü�� �Լ�*/
#include "myheader.h"

float avg(float x, float y);

struct book {
	char title[20];
	char first[15];
	char last[10];
	float r_price;
	float h_price;
};

int main(void) {
	struct book guide = { "Distributed Systems","George","Coulouris",28000.0,32000.0 };

	printf("Call by Value : R_price and H_price�� ��հ� = %.2f\n\n",avg(guide.r_price, guide.h_price));
	//�Լ��� �μ��� ����ü�� ����� ȣ��
	getch();
	return 0;
}

float avg(float x, float y) {
	return ((x + y) / 2);
}