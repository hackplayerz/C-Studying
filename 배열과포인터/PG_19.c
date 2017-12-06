/* 2017-12-06 포인터변수의 선언 */
#include <stdio.h> 
void main()
{
	int x = 10, y = 20;
	int *ptrx, *ptry;  // 2개의 포인터변수ptrx, ptry 선언
	ptrx = &x;          // ptrx에는 x의변수의 위치번지를 저장
	ptry = &y;          // ptry에는 y의변수의 위치번지를 저장

	printf("x의번지(&x) = %d   y의번지(&y) = %d \n", &x, &y);
	printf("ptrx        = %d   ptry        = %d \n\n", ptrx, ptry);

	printf("x의값       = %d    y의값           = %d \n", x, y);     // 변수 x와 y의  값을  직접접근해서 얻음
	printf("*ptrx       = %d   *ptry            = %d \n\n", *ptrx, *ptry);  // 변수 x와 y의  값을 포인터변수 ptrx, ptry를 이용하여  간접(우회)접근해서 얻음 
}