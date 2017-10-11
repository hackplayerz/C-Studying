#include "myheader.h"

void main() {
	char ch = 200;				// char's size is -128 ~127
	unsigned char j = 200;		// unsigned char's size is 0~255
	char k = 'a';

	int i = 2000000000;
	unsigned ui = 4000000000;
	int ik = 'b';

	float d = 3.141592;
	double d1 = 1234567890;
	double d2 = 'c';

	printf("문자형 변수 ch의 값은 %d \n", ch);
	printf("문자형 변수 j의 값은 %u \n", j);
	printf("문자형 변수 k의 값은 %d \n\n", k);

	printf("정수형 변수 i의 값은 %d \n", i);
	printf("정수형 변수 ui의 값은 %u \n", ui);
	printf("정수형 변수 ik의 값은 %d \n\n", ik);

	printf("실수형 변수 d의 값은 %E \n", d);
	printf("실수형 변수 d1의 값은 %E \n", d1);
	printf("실수형 변수 d2의 값은 %E \n\n", d2);
}