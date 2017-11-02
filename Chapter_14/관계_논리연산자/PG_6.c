/* 2017-11-02 실습 2 */
#include <stdio.h>
void main()
{

	char c = 'w';            // c는 참
	int i = 3, j = 3, k = 3;         // i, j, k는 참
	double x = 0.0, y = 2.3;   // x는 거짓, y는 참 


	printf("( i && j ) && k                                     = %d\n", i && j && k);
	printf("( x || ( i && ( j - 3 ) )                          = %d\n", x || i && j - 3);
	printf("( i < j ) && ( x < y )                             = %d\n", i < j && x < y);
	printf("( i < j ) || ( x < y )                              = %d\n", i < j || x < y);
	printf("( i == j ) && ( x <= y )                         = %d\n", i == j && x <= y);
	printf("( x + y ) && (( j + 1 ) == ( ( !k ) + 4 ))   = %d\n", x + y && j + 1 == !k + 4);
	printf("( 'A' <= c ) && ( c <= 'Z' )                   = %d\n", 'A' <= c && c <= 'Z');
	printf("( ( c – 1 ) == 'v' ) || ( ( c + 1 ) == 'v' ) = %d\n", c - 1 == 'v' || c + 1 == 'v');
	printf("(( i ==2 ) || ( j == 4 )) || ( k == 6 )      = %d\n", i == 2 || j == 4 || k == 6);
	printf("(( i ==2 ) || ( j == 4 )) || ( k = 6 )        = %d\n\n", i == 2 || j == 4 || (k = 6));
}