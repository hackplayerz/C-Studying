/* 2017-11-09 Report �ݺ��� Ȱ�� ���α׷� */
#include <stdio.h>
void main()
{
	// for��
	int i;
	int hap = 0;
	for (i = 0; i <= 10; i++) {
		if (i == 5) continue;
		printf("%d", i);//��� 1, 2, 3, 4, 6, 7
		hap = hap + i;
		if (i == 7) break;
	}
	printf("for�� : hap = %d\n", hap);//hap = 23
									 //while��
	i = 1;
	hap = 0;
	while (i <= 10) {
		i++;							// continue�� �Ʒ� ������ ���ѷ��� �߻�
		if (i == 5) 
			continue;
		printf("%d", i);//��� 1, 2, 3, 4, 6, 7
		hap = hap + i;
		if (i == 7)
			break;
	}
	printf("while�� : hap = %d\n", hap);//hap = 23
									   //do - while��
	i = 1;
	hap = 0;
	do {
		i++;							// continue�� �Ʒ� ������ ���ѷ��� �߻�
		if (i == 5) continue;
		printf("%d", i);//��� 1, 2, 3, 4, 6, 7
		hap = hap + i;
		if (i == 7) break;		
	} while (i <= 10);
	printf("while�� : hap = %d\n", hap);//hap = 23
}