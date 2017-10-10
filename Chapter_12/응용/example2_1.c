/* 2017-09-27 Scanf()를 이용한 활용예제 -와부함수를 선언한 Case */
#include <stdio.h>					// Standard Input Output Header

float triangle(int a, int b);		// 삼각형의 넓이를 구하는 함수
float rectangle(int a, int b);		// 사각형의 넓이를 구하는 함수
float f_round(int a);				// 원의 넓이를 구하는 함수

int main(void) {
	/* 각 밑변, 높이, 원의 반지름을 저장할 정수형 변수 선언 */
	int t_under = 0;				
	int t_high = 0;
	int r_under = 0;
	int r_high = 0;
	int round = 0;

	printf("삼각형의 밑변과 높이를 입력하세요 :");
	scanf("%d %d", &t_under, &t_high);
	/* 사용자로부터 값을 받아와 변의 크기를 변수에 저장 */ 
	printf("\n사각형의 밑변과 높이를 입력하세요 :");
	scanf("%d %d", &r_under, &r_high);

	printf("\n원의 반지름을 입력하세요 :");
	scanf("%d", &round);
	
	printf("삼각형의 넓이는 %.3f입니다.\n", triangle(t_under, t_high));
	printf("사각형의 넓이는 %.3f입니다.\n", rectangle(r_under, r_high));
	printf("원의 넓이는 %.3f입니다.\n",f_round(round));
	/* 사용자로부터 받아온 값을 계산하여 삼각형, 사각형, 원의 넓이를 출력 */
}
	/* 함수에서 넓이를 계산해 실수형으로 Return */
float triangle(int a, int b) {
	float x;
	x = (a*b) / 2;					
	return x;
}
float rectangle(int a, int b) {
	float x;
	x = a*b;
	return x;
}
float f_round(int a) {
	float x;
	x = a*a*3.14;
	return x;
}