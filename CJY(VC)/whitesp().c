#include <stdio.h>											//����߰�
#include <conio.h>
#define BOOL int											//��ũ�� ����
#define TRUE 1
#define FALSE 0

BOOL whitesp(char c);										//�ܺ��Լ�����

void main() {												//main�Լ� ����
	int ch;													//���������� ����
	int count = 0;											//����������count�� �ʱ�ȭ
	
	printf("���ڿ��� �Է��� ctrl+z�� ��������.\n");			//����� �޼��� ���
	while ((ch = getchar()) != EOF)							//while�ݺ��� ����
		if (whitesp(ch))count++;							//if�� ����
	printf("There are %d whitespace charater.\n",count);	//����� �޼��� ���

	getch();
	return 0;
}
BOOL whitesp(char c)										//�Լ� ����
{
	if (c == ' ' || c == '\n' || c == '\t')					//c='',c=='\n',c=='\t'�϶� ����
		return (TRUE);										//TREU������ �����ش�
	else
		return (FALSE);										//FALSE������ �����ش�
}