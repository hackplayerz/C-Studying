/*	2017-09-06 ��ø�� ����ü	*/
#include "myheader.h"

struct author {					// ����ü  author ����
	char first[15];
	char last[10];
};
struct book {
	char title[20];
	struct author names;		// ����ü book ���� ����ü author �� ��ø����
	float value;
};

int main(void)
{
	static struct book guide = { "Computer network",{ "Andrew", "Tanenbaum" }, 6000.0 };
	/* guide�� ����ü book�� ����ü����, names�� ����ü author��  ����ü����  */

	printf("å������guide.title : %s \n", guide.title);
								// ��ø�� ����ü ��� ���
	printf("å�����ڸ� �̸�guide.names.first : %s \n", guide.names.first); 
	printf("å�����ڸ�  ��guide.names.last  : %s \n", guide.names.last); 
	printf("å�ǰ���guide.value : %7.1f\n\n", guide.value);

	getch();
	return 0;
}