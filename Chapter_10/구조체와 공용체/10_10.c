/*2017-09-07 ����ü ��� ����*/
#include "myheader.h"
union int_or_float {
	int inum;
	float fnum;
};
int main(void) {
	static union int_or_float  abc;  // ���Ͽº�����abc ����
	union int_or_float * pabc;        // ���Ͽ������ͺ�����pabc ����
	pabc = &abc;

	abc.inum = 25;  //���Ͽº�����.���
	printf("���Ͽº���abc�������abc.inum�ǰ�=  %d \n\n", abc.inum);
	pabc->fnum = 13.4;   // ���Ͽ������͸�.���.  (*pabc).fnum = 13.4; ����� ����
	printf("pabc->fnum = %f; ������,���Ͽº���abc �������abc.inum �ǰ�= %d \n\n", abc.fnum,abc.inum);
	// abc.inum ����25����Ȯ���غ�����?  Yes, No?
	printf("���Ͽ������ͺ���pabc ������� pabc->fnum = %3.1f, (*pabc).fnum = %3.1f \n\n", pabc->fnum, (*pabc).fnum);

	getch();
	return 0;
}