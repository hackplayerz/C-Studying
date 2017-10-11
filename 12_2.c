/* 2017-09-21 printf() */
#include "myheader.h"

int main(void)
{
	int i;
	char *pi;
	char *string = "books";				// char string[ ] = “book”; 

										// charater and inteager
	printf("[%c]   \n", 'A');			// [A]  c : print Charater
	printf("[%d]   \n", 7);				// [7]	d : print signed inteager
	printf("[%i]   \n", 7);				// [7]	i : print inteager
	printf("[%5d]  \n", 7);				// *  [    7]
	printf("[%05d] \n", 7);				//  * [00007]
	printf("[%+d]  \n", -12345);		// [-12345]
	printf("[%+d]  \n", 12345);			// [+12345]
	printf("[% d]  \n", -12345);		// [-12345]
	printf("[%u]   \n", 12345);			// [12345] u : unsigned inteager
	printf("[%u]   \n", -12345);		// [4294954951]

										// octal and hexadecimal
	printf("[%x]   \n", 0xFF);			// [ff]
	printf("[%X]   \n", 0xFF);			// [FF]
	printf("[%#x]  \n", 0xFF);			// [0xff]
	printf("[%#x]  \n", 12345);			// [0x3039]
	printf("[%o]   \n", 0123);			// [123]
	printf("[%#o]  \n", 0123);			// [0123]

										// 고정소수점
	printf("[%f]      \n", 3.141592);	// [3.141592]
	printf("[%5f]     \n", 3.141592);	// [3.141592]
	printf("[%.f]     \n", 3.141592);	// [3]
	printf("[%.2f]    \n", 3.141592);	// [3.14]
	printf("[%2.2f]   \n", 3.141592);	// [3.14]
	
	printf("[%5.5f]   \n", 3.141592);	// [3.14159]
	printf("[%20.5f]  \n", 3.141592);	//  *[             3.14159]
	printf("[%-20.5f] \n", 3.141592);	// [3.14159             ]

										// 부동소수점
	printf("[%e]      \n", 3.141592);	// [3.141592e+000]
	printf("[%E]      \n", 3.141592);	// [3.141592E+000]
	printf("[%5e]     \n", 3.141592);   // [3.141592e+000]
	printf("[%E]      \n", 3.141592);	// [3.141592E+000]
	printf("[%5e]     \n", 3.141592);   // [3.141592e+000]
	printf("[%.e]     \n", 3.141592);   // [3e+000]
	printf("[%.2e]    \n", 3.141592);   // [3.14e+000]
	printf("[%2.2e]   \n", 3.141592);   // [3.14e+000]
	printf("[%5.5e]   \n", 3.141592);   // [3.14159e+000]
	printf("[%20.5e]  \n", 3.141592);   // [        3.14159e+000]
	printf("[%20.2E]  \n", 1.2e+10);	// [           1.20E+010]
	printf("[%-20.2E] \n", 1.2e+10);	// [1.20E+010           ]

										// 스마트형
	printf("[%g] \n", 3.141592);		// [3.14159]

										// 문자열형
	printf("[%s]    \n", string);		// [books]
	printf("[%10s]  \n", string);		// [     books]
	printf("[%-10s] \n", string);		// [books     ]
	printf("[%2s]   \n", string);		// [books]
	printf("[%2.2s] \n", string);		// [bo]
	printf("[%3.2s] \n", string);		// [ bo]
	printf("[%010s] \n", string);		//  * [00000books]

										// 포인트형
	printf("[%p] \n", &i);				// [0012FF7C]
	printf("[%p] \n", &pi);				// [0012FF78]

	getch();
	return 0;
}