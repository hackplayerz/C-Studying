#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OVER 21

int main(void)
{
	int ucard = 2, ccard = 2;//받은 카드 장수
	int umon = 5000, cmon = 50000, betmon = 0;//컴터와 사용자 돈 앤 판돈
	int tal = 0, tal1 = 0;//받은카드의 합
	int sel = 0, sel1 = 0;//스위치문 선택용
	int race = 0;//가나 마나
	int win = 0, lose = 0, drew = 0;//승무패
	int rand1 = 0, rand2 = 0, crand1 = 0, crand2 = 0;//카드값

	srand(time(NULL));
	srand(rand());


	while (1) {//전체 반복문
		printf("----Black Jack GAME---\n");//메뉴선택
		printf("메뉴->  1.GAME START\n");
		printf("        2.SCORE\n");
		printf("        3.QUIT\n");
		printf("----------------------\n");
		printf(">");
		scanf("%d", &sel);
		printf("\n");
		switch (sel) { //메뉴 선택문
		case 3://종료부분
		{
			system("cls");
			printf("Bye Bye~!!!!\n");
			return 0;
		}break;

		case 2://스코어 부분
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
			rand1 = rand() % 10 + 1;//사용자카드 두장 받는 부분 
			rand2 = rand() % 10 + 1;

			tal = rand1 + rand2;

			crand1 = rand() % 10 + 1;//딜러 카드 두장 받는 부분
			crand2 = rand() % 10 + 1;

			tal1 = crand1 + crand2;


			while (1) {
				printf("당신의 카드값의 합은 %d입니다.\n", tal);
				printf("1.HIT? or 2.STAND >");
				scanf("%d", &sel1);
				if (sel1 == 1) {//카드 더받는 부분
					rand1 = rand() % 10 + 1;
					tal = tal + rand1;
					ucard++;
					if (tal > OVER)//21을 넘겼을시 게임 지는 부분
					{
						printf("21을 넘겼습니다\n");
						printf("you lose!!!\n");						
						lose++;
						umon = umon - 10;
						getch();
						system("cls");
						if (umon <= 0) {
							printf("돈이 없구나 나가거라~!!\n");
							break;
						}
						break;
					}
				}
				else if (sel1 == 2)//카드 더 안받고 비교부분 
				{
					printf("How much bet money<1~%d>?", umon);
					scanf("%d", &betmon);//배팅 금액
					printf("\n");
					break;
				}
			}
			while (1) {
				if (tal1<17) {//딜러 인공지능 부분 17미만시 더받기
					crand1 = rand() % 10 + 1;
					tal1 = crand1 + tal1;
					ccard++;
				}
				else if (tal1 >= 17 && tal1 < 22) {//17에서 21일 사이시 안받기

					break;
				}
				else if (tal1 > OVER) {//21오버시 딜러 패
					printf(" 컴퓨터가 21이 넘어서 이겼습니다.\n");
					umon = umon + 10;
					win++;
					getch();
					system("cls");	
					break;
				}
			}
			if (tal <= OVER && tal1 <= OVER && tal > tal1) {//카드 비교부분
				printf("딜러의 합은 %d입니다.\n", tal1);
				printf("딜러의 카드수는 %d입니다.\n", ccard);
				printf(" you  win!!\n");		
				umon = umon + 10 + betmon;
				win++;
				getch();
				system("cls");
			}
			else if (tal == tal1 && ucard < ccard) {//서로 값이 같을시 카드 적게 받은사람이 승리 
				printf("딜러의 합은 %d입니다.\n", tal1);
				printf("딜러의 카드수는 %d입니다.\n", ccard);
				printf("   you win!!\n");				
				umon = umon + 10 + betmon;
				win++;
				getch();
				system("cls");
			}
			else if (tal1 <= OVER&& tal < tal1) {
				printf("딜러의 합은 %d입니다.\n", tal1);
				printf("딜러의 카드수는 %d입니다.\n", ccard);
				printf(" you lose..\n");							
				umon = umon - 10 - betmon;
				lose++;
				getch();
				system("cls");
				if (umon <= 0) {
					printf("돈이 없구나 나가거라~!!\n");
					return 0;
				}
			}
			else if (tal == tal1 && ucard > ccard) {//서로 값이 같을시 카드 적게 받은사람이 승리
				printf("딜러의 합은 %d입니다.\n", tal1);
				printf("딜러의 카드수는 %d입니다.\n", ccard);
				printf(" you lose..\n");				
				umon = umon - 10 - betmon;
				lose++;
				getch();
				system("cls");
				if (umon <= 0) {
					printf("돈이 없구나 나가거라~!!\n");
					return 0;
				}

			}
			else if (tal == tal1 && ucard == ccard) {
				printf("딜러의 합은 %d입니다.\n", tal1);
				printf("딜러의 카드수는 %d입니다.\n", ccard);
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