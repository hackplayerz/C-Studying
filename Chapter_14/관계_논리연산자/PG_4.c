/* 2017-11-02 Report ½Ç½À1 */
#include <stdio.h>
void main()
{

	char c = 'w';
	int i = 1, j = 2, k = -7, x = 7e+33, y = 0.001;

	printf("('a' + 1) < c						= %d\n", 'a' + 1 < c);
	printf("( ( -i ) - ( 5 * j ) ) >= ( k + 1 ) = %d\n", -i - 5 * j >= k + 1);
	printf("( 3 < j ) < 5						= %d\n", 3 < j < 5);
	printf("( x - 3.333 ) <= ( x + y )			= %d\n", x - 3.333 <= x + y);
	printf("x < (x + y)							= %d\n", x < x + y);
	printf(" \'v\'== (c -1)						= %d\n", 'v' == c - 1);
	printf("( ( i + j ) + k ) == ( ( -2 ) * j ) = %d\n", i + j + k == -2 * j);
	printf("(k == j- 9) == i					= %d\n", k == j - 9 == i);
	printf("(x + x) != (x * y)					= %d\n", x + x != x * y);
	printf("x  != (x + y)						= %d\n\n", x != (x + y));
}