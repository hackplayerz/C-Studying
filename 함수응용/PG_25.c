/* 2017-11-23 Switch - case 문을 사용해 사칙연산을 계산하는 프로그램 */
#include <stdio.h>
int add(int a, int b);		// 합
int sub(int a, int b);		// 차
int mul(int a, int b);		// 곱
int div(int a, int b);		// 나누기

int main(void) {
	int num_1, num_2, sum;
	char oper;
	while (1) {
		printf("***프로그램을 종료하려면 'q'를 입력하세요.***\n\n");
		printf("식을 쓰시오 : ");
		scanf("%d %c %d", &num_1, &oper, &num_2);

		if (getchar() == 'q') {
			printf("프로그램을 종료합니다.\n");
			return 0;
		}

		switch (oper)
		{
		case '+':
			sum = add(num_1, num_2);
			break;
		case '-':
			sum = sub(num_1, num_2);
			break;
		case '*':
			sum = mul(num_1, num_2);
			break;
		case '/':
			sum = div(num_1, num_2);
			break;
		default:
			printf("잘못된 연산자를 입력하셨습니다.\n");
			continue;
		}
		printf("\nResult : %d %c %d = %d\n", num_1, oper, num_2, sum);
	}

	return 0;
}
int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a*b;
}
int div(int a, int b) {
	return a / b;
}