#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#define MAP_X 30 // 맵의 가로

#define MAP_Y 22 // 맵의 세로

#define HEART MAP_X-1 // 최대 하트의 갯수

#define LEFT 75 // 왼쪽

#define RIGHT 77 // 오른쪽

#define DEAD 0 // 죽었을 경우

#define CLEAR 1 // 클리어 했을 경우
#pragma warning (disable:4996)



void endGame(int); // 게임이 끝났을 경우

void init_field(void); // 기본 맵의 테두리 출력

void init_game(void); // 게임을 초기화한다

void start_game(void); // 게임을 시작한다

void print_heart(void); // 화면에 하트을 뿌려준다

void check_hit(void); // 하트과 캐릭터 충돌 체크




typedef struct xy{
	int x;
	int y;
};
struct xy heart[HEART];
struct xy charic;

int max_heart = 0; // 떨어져야 하는 하트의 수
int count_heart = 0; // 떨어진 하트의 수
int game_speed = 0; // 게임 속도
int stage = 0; // 스테이지

			   // 입력받은 좌표로 커서를 움직여주는 함수

void gotoxy(int x, int y)
{	
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);	
}




// 게임이 끝났을 경우

void endGame(int flag)
{
	// 사용자가 죽었을 경우
	if (flag == DEAD)
	{
		getch();
		system("cls");
		gotoxy(MAP_X / 2, MAP_Y / 2);
		printf("## 하트에 맞아서 게임이 끝났습니다. ##\n");
		getch();
		exit(1);
	}
	else // 사용자가 스테이지를 클리어했을 경우
	{
		getch();
		getch();
		system("cls");
		gotoxy(MAP_X / 2, MAP_Y / 2);
		printf("## 스테이지 클리어 ##\n");
		gotoxy(MAP_X / 2, MAP_Y / 2 + 1);
		printf("## 하트이 내리는 속도와 갯수가 증가합니다 ##\n");
		gotoxy(MAP_X / 2, MAP_Y / 2 + 2);
		printf("## 아무키나 누르면 시작 ##\n");
		getch();
		getch();
		system("cls");
		// 맵 출력

		init_field();
		// 스테이지 증가

		stage++;


		// 게임 초기화

		init_game();
		// 내리는 하트의 갯수 증가

		max_heart += stage * 30;
		// 게임 속도 증가
		game_speed -= stage * 10;

	}
}




// 게임 맵의 테두리를 출력해주는 함수

void init_field(void)
{
	int col = 0; // 행
	int row = 0; // 열
				 // 미리 선언한 맵의 가로 크기만큼 반복
	for (col = 0; col <= MAP_Y; col++)
	{
		// 맨 처음 행과 가장 마지막 행 일때 수행
		if (col == 0 || col == MAP_Y)
		{
			for (row = 0; row <= MAP_X; row++)
			{
				gotoxy(row * 2, col);
				printf("□");
			}
		}
		else// 나머지 열 일때 수행
		{
			gotoxy(0, col);
			printf("□");
			gotoxy(MAP_X * 2, col);
			printf("□");
		}
	}
}
// 게임의 초기화 작업을 해주는 함수
void init_game(void)
{	
	int count = 0;
	// 떨어지는 하트의 최소 갯수
	max_heart = 50;
	// 현재 떨어진 하트의 갯수
	count_heart = 0;
	// 게임 속도 조절
	game_speed = 100;
	// 하트 위치 초기화
	for (count = 0; count < HEART; count++)
	{
		heart[count].x = count + 1;
		heart[count].y = rand() % 50;
		heart[count].x *= 2;
		heart[count].y *= -1;
	}

	// 사용자 위치 초기화
	charic.x = MAP_X;
	charic.y = MAP_Y - 1;

	// 캐릭터 기본 위치 출력
	gotoxy(charic.x, charic.y - 2);
	printf("○");
	gotoxy(charic.x, charic.y - 1);
	printf("□");
	gotoxy(charic.x, charic.y);
	printf("II");
	// 게임 화면에 메시지 출력
	gotoxy(0, MAP_Y + 1);
	printf("STAGE [ %d ]\n", stage + 1);
	printf(">> 피한 하트의 갯수 : %d", count_heart);
}
void print_heart(void)
{
	int count = 0;

	// 하트을 내리게 하는 함수

	for (count = 0; count < HEART; count++)
	{
		// 땅에 떨어졌을 경우
		if (heart[count].y == MAP_Y - 1) {
			// 기존 위치의 하트을 삭제한다.
			gotoxy(heart[count].x, heart[count].y);
			printf(" ");
			
			// 떨어진 하트의 갯수 증가
			count_heart++;
			gotoxy(0, MAP_Y + 1);

			printf("STAGE [ %d ]\n", stage + 1);

			printf(">> 피한 하트의 갯수 : %d", count_heart);




			// 떨어진 하트의 갯수와 최대 하트의 갯수가 같을 경우

			if (max_heart == count_heart)

			{

				gotoxy(MAP_X, MAP_Y + 1);

				printf("[ 하트를 다 피했습니다. 아무키나 누르세요 ]");

				// 게임 클리어

				endGame(CLEAR);

				return;

			}

			// 떨어진 하트의 갯수가 최대 갯수가 아닐 경우

			else if (max_heart > count_heart)

			{

				// 하트을 위에서 다시 내리게 한다

				heart[count].y = rand() % 50;

				heart[count].y *= -1;

			}

			continue;

		}

		// 하트을 밑으로 한칸 내린다

		heart[count].y = heart[count].y + 1;

		if (heart[count].y > 1)

		{

			// 기존 위치의 하트을 삭제한다.

			gotoxy(heart[count].x, heart[count].y - 1);

			printf(" ");




			// 새로운 위치에 하트을 출력한다.

			gotoxy(heart[count].x, heart[count].y);

			printf("♥");

		}

	}

}




// 하트을 맞았는지 체크

void check_hit(void)

{

	int count = 0;




	// 현재 하트의 수 만큼 반복

	for (count = 0; count < HEART; count++)

	{

		// 사용자와 같은 열인지 확인

		if (heart[count].x == charic.x)

		{

			// 같은 행인지 확인

			if (heart[count].y == charic.y || heart[count].y == charic.y - 1

				|| heart[count].y == charic.y - 2)

			{

				gotoxy(MAP_X, MAP_Y + 1);

				printf("[ 하트에 맞았습니다. 아무키나 누르세요 ]");

				// 게임 오버

				endGame(DEAD);

			}

		}

	}

}




// 게임 시작에 대한 내용을 구현한 부분

void start_game(void)

{

	// 사용자로부터 값을 입력받는 변수

	char input = '\0';




	while (1)

	{

		// 사용자로 부터 입력을 받는다.

		if (kbhit())

		{

			// 입력받은 값을 저장한다.

			input = getch();




			// 왼쪽으로 이동하라고 했을 경우

			if (input == LEFT)

			{

				// 왼쪽으로 이동 할 수 있을 경우

				if (charic.x - 2 > 0)

				{

					// 기존 위치의 캐릭터를 지운다.

					gotoxy(charic.x, charic.y - 2);

					printf(" ");

					gotoxy(charic.x, charic.y - 1);

					printf(" ");

					gotoxy(charic.x, charic.y);

					printf("  ");




					// 위치를 갱신한다.

					charic.x = charic.x - 2;




					// 새로운 위치에 다시 출력한다.

					gotoxy(charic.x, charic.y - 2);

					printf("○");

					gotoxy(charic.x, charic.y - 1);

					printf("□");

					gotoxy(charic.x, charic.y);

					printf("II");

				}

			}

			// 오른쪽으로 이동하라고 했을 경우

			else if (input == RIGHT)

			{

				// 오른쪽으로 이동할 수 있을 경우

				if (charic.x + 2 < MAP_X * 2)

				{

					// 기존 위치의 캐릭터를 지운다.

					gotoxy(charic.x, charic.y - 2);

					printf(" ");

					gotoxy(charic.x, charic.y - 1);

					printf(" ");

					gotoxy(charic.x, charic.y);

					printf("  ");




					// 위치를 갱신한다.

					charic.x = charic.x + 2;




					// 새로운 위치에 다시 출력한다.

					gotoxy(charic.x, charic.y - 2);

					printf("○");

					gotoxy(charic.x, charic.y - 1);

					printf("□");

					gotoxy(charic.x, charic.y);

					printf("II");

				}

			}

		}

		else

		{

			// 게임 속도 조절

			Sleep(game_speed);




			// 화면에 하트 출력

			print_heart();

		}

		// 하트을 맞았는지 확인

		check_hit();

	}

}




int main(void)

{

	// 랜덤 값 초기화

	srand(time(0));




	printf("┌────────────────────┐\n");

	printf("│				      │\n");

	printf("│	하트 피하기 게임	       │\n");

	printf("│				      │\n");

	printf("│	아무키나 누르면 시작!	       │\n");

	printf("│    게임 조작키 : 방향키 ←, →       │\n");

	printf("│				      │\n");

	printf("└────────────────────┘\n");




	getch();




	system("cls");

	// 게임 맵의 테두리를 출력해준다.

	init_field();




	// 게임의 기본적인 초기화 작업

	init_game();




	// 게임을 시작한다

	start_game();




	return 0;

}