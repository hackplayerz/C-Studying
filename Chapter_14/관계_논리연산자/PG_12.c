/* 2017-11-02 방정식 감지 프로그램 */
#include <stdio.h>				// Standard Input Output Header
#include <string.h>				// Standard String Header

int ValidityCheck(char *str);

main() {
	char equation[50];

	while (1) {
		printf("방정식 입력(exit 입력 시 종료) : ");
		gets_s(equation, sizeof(equation));

		if (!strcmp(equation, "exit")) {	// 사용자가 "exit"을 치면 프로그램 종료
			printf("종료합니다.\n");
			break;
		}
		else if (!ValidityCheck(equation))
			printf("잘못된 방정식입니다.\n\n");
		else
			printf("정상적인 방정식입니다.\n\n");
	}
}

int ValidityCheck(char *str) {

	int i, token, numberFlag = 0, operFlag = 0, unknownQuantityFlag = 0;
	char unknownQuantity = 'x';

	/* 토큰 분류 (자연수는 0, 연산자는 1, 미지수는 2) */
	for (i = 0; str[i] != '\0'; i++) {

		if (str[i] >= '0'&&str[i] <= '9')
			token = 0;		// 자연수일떄 token = 0
		else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
			token = 1;		// 증감연산자일때 token = 1
		else if (str[i] == 'x' || str[i] == 'y') {
			token = 2;		// 미지수 토큰 설정
		}
		else {
			printf("잘못된 문자 입력 잘못된 문자 인덱스: %d\n", i);
			return 0;
		}

		if (token == 0) {	// 자연수 토큰			
			if (numberFlag) // 자연수가 감지된 상태일 때(자연수 연속일 때)
				continue;

			else if (unknownQuantityFlag) {	// 미지수 뒤에 자연수가 왔을 때
				printf("항이 시작되는데 연산자가 없습니다. 잘못된 문자 인덱스: %d\n", i);
				return 0;		// 앞의 항이 끝난 뒤 연산자가 없는 경우로 에러
			}

			else {
				numberFlag = 1; //자연수 감지 on 셋팅
				operFlag = 0;	//항 시작으로 연산자 감지 off 셋팅
			}
		}
		else if (token == 1) {	// 연산자 토큰			
			if (operFlag) {		// 연산자 다음에 연산자가 오면 에러
				printf("연속 연산자로 에러. 잘못된 문자 인덱스: %d\n", i);
				return 0;
			}
			else {
				operFlag = 1;	// 연산자 감지 on 셋팅
				numberFlag = 0;
				unknownQuantityFlag = 0;
				// 항 시작이므로 자연수 감지, 미지수 감지 off 셋팅
			}
		}

		else {							// 토큰이 미지수일때				
			if (unknownQuantityFlag) {
				continue;
			}

			else {						// 항 종료이므로 자연수감지, 연산자 감지 off 셋팅
				unknownQuantityFlag = 1;
				operFlag = 0;
				numberFlag = 0;
			}
		}
	}
	if (token == 1) {					// 마지막항이 연산자일시 항에 에러가 발생 
		printf("마지막항이 연산자입니다.");
		return 0;
	}
	return 1;
}
