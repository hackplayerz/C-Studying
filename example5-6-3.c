/* 2017-10-18 실습예제3 */
#include <stdio.h>							// Standard Input Output Header
#include <conio.h>							// Console Input Output Header
#pragma warning (disable:4996)

void main() {
	char input[100];						// 가저올 문자를 저장할 변수 선언
				/* 가저온 문자를 각각의 변수에 대입 */
	char inteager[40];						
	char upper[40];							
	char down[40];
	char ect[40];

	int i, in = 0, d = 0, u = 0, e = 0;

	printf("입력 :");
	gets_s(input,sizeof(input));			// 사용자로부터 문자를 받아옴

	for (i = 0; input[i] != NULL; i++) {	// 사용자로부터 받아온 값들을 분류
		if ('0' <= input[i] && input[i] <= '9') {
			inteager[in++] = input[i];
		}
		else if ('a' <= input[i] && input[i] <= 'z') {
			down[d++] = input[i];
		}
		else if ('A' <= input[i] && input[i] <= 'Z') {
			upper[u++] = input[i];
		}
		else
			ect[e++] = input[i];

		inteager[in] = NULL;
		down[d] = NULL;
		upper[u] = NULL;
		ect[e] = NULL;						// 분류한뒤 마지막 값에 ESCAPE문자를 대입하여 문자열의 끝을 알려줌
	}
	printf("숫자 : %s", inteager);
	printf("소문자 : %s\n", down);
	printf("대문자 : %s\n", upper);
	printf("기타 : %s\n", ect);				// 분류한 문자를 출력
}