/* 2017-11-22 매크로확장 */
#include <stdio.h>
#define AREA(x) (3.1415926536 * x * x)
void main()
{
	printf("매크로확장-원의면적=  %f \n", AREA(2.5));
	printf("공식이용   -원의면적=  %f \n", 3.1415926536 * 2.5 * 2.5);
}