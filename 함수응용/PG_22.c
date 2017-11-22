/* 
2017-11-22 
다음 프로그램을  3개의 호출함수
(f-for(), f-while(), f-dowhile())로 구성된
 프로그램으로 작성하시오
 */
#include <stdio.h>
extern int f_for(int a);		// f_for.c
extern int f_while(int b);		// f_while.c
extern int f_do_while(int c);	// f_do_while.c
main() {
	f_for(10);
	f_while(10);
	printf("\n do_while 문 : hap = %2d\n\n", f_do_while(10));
}