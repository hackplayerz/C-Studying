/*2017-09-07 구조체와 배열*/
#include "myheader.h"
float avg(struct book *money);
// 함수에배열구조체정보값전달방법(Call By Result) 
struct book {
	char title[20];
	char first[15];
	char last[10];
	float r_price;
	float h_price;
};
int main(void)
{
	static struct book guide[2] = {
		{ "Distributed Systems","George","Coulouris",28000.0, 32000.0 } ,
		{ "Architecture", "Moris", "Mano", 26000.0, 30000.0 } };

	printf("guide의주소= %d, &guide[0]의주소= %d \n", guide, &guide[0]);
	//배열구조체명이 포인터임
	printf("Call By Result: R-price and H-price의평균값= $%.2f\n\n", avg(guide));

	getch();
	return 0;
}
float avg(struct book *  money)   // money = guide 
{
	float total = 0;
	int i;
	for (i = 0; i<2; i++) {
		total += (money->r_price + money->h_price) / 2;
		printf(" Total_ [%d] == %8.2f\n", i, total);
		money++;
	}
	return(total / i);	// i가 순차적으로 2까지 증가해 2를 나누게됨
}
