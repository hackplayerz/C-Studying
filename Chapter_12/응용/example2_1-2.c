 #include<stdio.h>			// Standard Input Output Header

void main()					// Start Main Func
{
	int t_high = 0, t_under = 0, r_right = 0, r_left = 0, round = 0;	

		/* ����ڷκ��� �غ�, ����, ����, ����, �������� �޾ƿ� */
	printf("�ﰢ���� �غ��� ���̸� �Է��ϼ���:");
	scanf("%d %d", &t_under, &t_high);
	printf("�ﰢ���� ���ο� ���θ� �Է��ϼ���:");
	scanf("%d %d", &r_right, &r_left);
	printf("���� �������� �Է��ϼ���:");
	scanf("%d", &round);

		/* ���� ���� ��� */
	printf("�ﰢ���� ���̴�:%.3f\n", (float)((t_high*t_under) / 2));
	printf("�簢���� ���̴�:%.3f\n", (float)(r_right*r_left));
	printf("���� ���̴�:%.3f\n", (float)(round*round*3.141592));
}