/*2017-09-07 ����ü�� �Լ�*/
#include "myheader.h"
float avg(struct book *money);
// �Լ�������ü���������޹��(Call By Address) 

struct book {
	char title[20];    char first[15];     char last[10];
	float r_price;      float h_price;
};
int main(void) {
	struct book guide = { "Distributed  Systems", "George", "Coulouris",28000.0, 32000.0 };
	printf("Call by Address : R_price and H_price �� ��հ� = $%.2f\n\n", avg(&guide));

	getch();
	return 0;
}
float avg(struct  book  * money)
// money = &guide
{
	return((money->r_price + money->h_price) / 2);
	// �Ǵ�return(((*money).r_price +(*money).h_price)/2);
}