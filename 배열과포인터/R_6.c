/* 실습예제11.5 */
#include <stdio.h>

main() {
	char *str = "qweaqweweqwsqwedqweqwewebwecpwezpweqwertyqedqwe";
	int i, count = 0;

	puts(str);

	for (i = 0; *(str + i) != '\0'; i++) {
		if (*(str + i) == 'q' && *(str + i + 1) == 'w' && *(str + i + 2) == 'e') {
			printf("인덱스 %d에서 발견\n", i);
			count++;
			i += 2;
		}
	}
	printf("발견된 문자열 \"qwe\"의 개수 : %d\n", count);
}
