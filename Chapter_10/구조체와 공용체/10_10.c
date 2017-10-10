/*2017-09-07 공용체 멤버 참조*/
#include "myheader.h"
union int_or_float {
	int inum;
	float fnum;
};
int main(void) {
	static union int_or_float  abc;  // 유니온변수명abc 선언
	union int_or_float * pabc;        // 유니온포인터변수명pabc 선언
	pabc = &abc;

	abc.inum = 25;  //유니온변수명.멤버
	printf("유니온변수abc를사용한abc.inum의값=  %d \n\n", abc.inum);
	pabc->fnum = 13.4;   // 유니온포인터명.멤버.  (*pabc).fnum = 13.4; 선언과 같음
	printf("pabc->fnum = %f; 수행후,유니온변수abc 를사용한abc.inum 의값= %d \n\n", abc.fnum,abc.inum);
	// abc.inum 값이25인지확인해보세요?  Yes, No?
	printf("유니온포인터변수pabc 를사용한 pabc->fnum = %3.1f, (*pabc).fnum = %3.1f \n\n", pabc->fnum, (*pabc).fnum);

	getch();
	return 0;
}