#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OVER 21

int main(void)
{
	int ucard = 2, ccard = 2;//���� ī�� ���
	int umon = 5000, cmon = 50000, betmon = 0;//���Ϳ� ����� �� �� �ǵ�
	int tal = 0, tal1 = 0;//����ī���� ��
	int sel = 0, sel1 = 0;//����ġ�� ���ÿ�
	int race = 0;//���� ����
	int win = 0, lose = 0, drew = 0;//�¹���
	int rand1 = 0, rand2 = 0, crand1 = 0, crand2 = 0;//ī�尪

	srand(time(NULL));
	srand(rand());


	while (1) {//��ü �ݺ���
		printf("----Black Jack GAME---\n");//�޴�����
		printf("�޴�->  1.GAME START\n");
		printf("        2.SCORE\n");
		printf("        3.QUIT\n");
		printf("----------------------\n");
		printf(">");
		scanf("%d", &sel);
		printf("\n");
		switch (sel) { //�޴� ���ù�
		case 3://����κ�
		{
			system("cls");
			printf("Bye Bye~!!!!\n");
			return 0;
		}break;

		case 2://���ھ� �κ�
		{
			system("cls");
			printf("----------------------\n");
			printf("victory    -> <%d>\n", win);
			printf("lose    -> <%d>\n", lose);
			printf("drew    -> <%d>\n", drew);
			printf("your money    -> <%d>\n", umon);
			printf("----------------------\n");
			getch();
			system("cls");
		}break;

		case 1:
		{
			system("cls");
			rand1 = rand() % 10 + 1;//�����ī�� ���� �޴� �κ� 
			rand2 = rand() % 10 + 1;

			tal = rand1 + rand2;

			crand1 = rand() % 10 + 1;//���� ī�� ���� �޴� �κ�
			crand2 = rand() % 10 + 1;

			tal1 = crand1 + crand2;


			while (1) {
				printf("����� ī�尪�� ���� %d�Դϴ�.\n", tal);
				printf("1.HIT? or 2.STAND >");
				scanf("%d", &sel1);
				if (sel1 == 1) {//ī�� ���޴� �κ�
					rand1 = rand() % 10 + 1;
					tal = tal + rand1;
					ucard++;
					if (tal > OVER)//21�� �Ѱ����� ���� ���� �κ�
					{
						printf("21�� �Ѱ���ϴ�\n");
						printf("you lose!!!\n");						
						lose++;
						umon = umon - 10;
						getch();
						system("cls");
						if (umon <= 0) {
							printf("���� ������ �����Ŷ�~!!\n");
							break;
						}
						break;
					}
				}
				else if (sel1 == 2)//ī�� �� �ȹް� �񱳺κ� 
				{
					printf("How much bet money<1~%d>?", umon);
					scanf("%d", &betmon);//���� �ݾ�
					printf("\n");
					break;
				}
			}
			while (1) {
				if (tal1<17) {//���� �ΰ����� �κ� 17�̸��� ���ޱ�
					crand1 = rand() % 10 + 1;
					tal1 = crand1 + tal1;
					ccard++;
				}
				else if (tal1 >= 17 && tal1 < 22) {//17���� 21�� ���̽� �ȹޱ�

					break;
				}
				else if (tal1 > OVER) {//21������ ���� ��
					printf(" ��ǻ�Ͱ� 21�� �Ѿ �̰���ϴ�.\n");
					umon = umon + 10;
					win++;
					getch();
					system("cls");	
					break;
				}
			}
			if (tal <= OVER && tal1 <= OVER && tal > tal1) {//ī�� �񱳺κ�
				printf("������ ���� %d�Դϴ�.\n", tal1);
				printf("������ ī����� %d�Դϴ�.\n", ccard);
				printf(" you  win!!\n");		
				umon = umon + 10 + betmon;
				win++;
				getch();
				system("cls");
			}
			else if (tal == tal1 && ucard < ccard) {//���� ���� ������ ī�� ���� ��������� �¸� 
				printf("������ ���� %d�Դϴ�.\n", tal1);
				printf("������ ī����� %d�Դϴ�.\n", ccard);
				printf("   you win!!\n");				
				umon = umon + 10 + betmon;
				win++;
				getch();
				system("cls");
			}
			else if (tal1 <= OVER&& tal < tal1) {
				printf("������ ���� %d�Դϴ�.\n", tal1);
				printf("������ ī����� %d�Դϴ�.\n", ccard);
				printf(" you lose..\n");							
				umon = umon - 10 - betmon;
				lose++;
				getch();
				system("cls");
				if (umon <= 0) {
					printf("���� ������ �����Ŷ�~!!\n");
					return 0;
				}
			}
			else if (tal == tal1 && ucard > ccard) {//���� ���� ������ ī�� ���� ��������� �¸�
				printf("������ ���� %d�Դϴ�.\n", tal1);
				printf("������ ī����� %d�Դϴ�.\n", ccard);
				printf(" you lose..\n");				
				umon = umon - 10 - betmon;
				lose++;
				getch();
				system("cls");
				if (umon <= 0) {
					printf("���� ������ �����Ŷ�~!!\n");
					return 0;
				}

			}
			else if (tal == tal1 && ucard == ccard) {
				printf("������ ���� %d�Դϴ�.\n", tal1);
				printf("������ ī����� %d�Դϴ�.\n", ccard);
				printf("  Drew!!!\n");
				umon = umon + 10;
				drew++;
				getch();
				system("cls");
			}

		}break;


		}
	}

	return 0;
}