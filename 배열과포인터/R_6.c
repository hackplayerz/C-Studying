/* �ǽ�����11.5 */
#include <stdio.h>

main() {
	char *str = "qweaqweweqwsqwedqweqwewebwecpwezpweqwertyqedqwe";
	int i, count = 0;

	puts(str);

	for (i = 0; *(str + i) != '\0'; i++) {
		if (*(str + i) == 'q' && *(str + i + 1) == 'w' && *(str + i + 2) == 'e') {
			printf("�ε��� %d���� �߰�\n", i);
			count++;
			i += 2;
		}
	}
	printf("�߰ߵ� ���ڿ� \"qwe\"�� ���� : %d\n", count);
}
