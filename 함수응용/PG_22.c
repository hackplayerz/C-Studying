/* 
2017-11-22 
���� ���α׷���  3���� ȣ���Լ�
(f-for(), f-while(), f-dowhile())�� ������
 ���α׷����� �ۼ��Ͻÿ�
 */
#include <stdio.h>
extern int f_for(int a);		// f_for.c
extern int f_while(int b);		// f_while.c
extern int f_do_while(int c);	// f_do_while.c
main() {
	f_for(10);
	f_while(10);
	printf("\n do_while �� : hap = %2d\n\n", f_do_while(10));
}