/* 2017-11-22 정적변수와 지역변수의 차이 */
#include <stdio.h>

void aut() {
	int x = 0;
	x += 2;
	printf("x = %d\n", x);
}
void stat() {
	static int x = 0;
	x = x + 2;
	printf("x = %d\n", x);
}
void main()
{
	printf("===== auto variable =====\n");
	aut();	aut();	aut();			// 지역변수가 저장된 함수를 호출 : 값이 초기화되어 새롭게 출력
	printf("===== static variable =====\n");
	stat();	stat();	stat();			// 정적변수가 저장된 함수를 호출 : 값이 누적되어 출력
}