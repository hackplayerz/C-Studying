/* 2017-11-02 Report 실습 3 방정식판별 프로그램 */
#include <stdio.h>

int ValidityCheck(char *str);		// 연산자 판별함수 선언

void main() {
	char equation[50];

	while (1) {
		printf("방정식 입력 : ");
		gets_s(equation, sizeof(equation));				// 사용자로부터 식을 받아옴

		if (!ValidityCheck(equation))
			printf("잘못된 방정식 입니다.\n\n");
		else
			printf("정상적인 방정식 입니다.\n\n");
	}
}
int ValidityCheck(char *str)
{
	int i, token, numberFlag = 0, operFlag = 0;

	for (i = 0; str[i] != '\0'; i++) {
		//토큰 분류 (자연수는 0, 연산자는 1
		if (str[i] >= '0' && str[i] <= '9')  token = 0;
		else if (str[i] == '+' || str[i] == '-') token = 1;
		else {  //잘못된 문자는 에러
			printf("잘못된 문자 포함. ");
			return 0;
		}
		if (token) { //토큰이 연산자일 때
			if (operFlag) { //연산자 다음에 연산자가 오면 에러
				printf("연속 연산자로 에러. ");
				return 0;
			}
			else {
				operFlag = 1;  //연산자 감지 on 셋팅
				numberFlag = 0;  //항종료이므로자연수감지 off셋팅
			}
		}
		else {
			//자연수가 감지된 상태일 때(자연수 연속일 때)
			if (numberFlag) continue;
			else {
				numberFlag = 1;
				operFlag = 0;
			}
		}
	}
	return 1;
}