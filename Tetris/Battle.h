#ifndef BATTLE_HEADER
#define BATTLE_HEADER
#pragma comment(lib, "winmm.lib")

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <Mmsystem.h>
#include <Digitalv.h>

typedef enum CURSOR_TYPE { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
typedef enum { false, true } bool;

#define BLACK	0
#define BLUE1	1
#define GREEN1	2
#define CYAN1	3
#define RED1	4
#define MAGENTA1 5
#define YELLOW1	6
#define GRAY1	7
#define GRAY2	8
#define BLUE2	9
#define GREEN2	10
#define CYAN2	11
#define RED2	12
#define MAGENTA2 13
#define YELLOW2	14
#define WHITE	15
#define UIJUMP 8
#define WHITESPACE "  "

#define Z 122
#define Q 113
#define ENTER 13
#define SPECIAL1 0xe0 // Ư��Ű�� 0xe0 + key ������ �����ȴ�.
#define SPECIAL2 0x00 // keypad ��� 0x00 + key �� �����ȴ�.
#define P1DOWN ' ' // Player1�� ��� �����̽��ٸ� ������ �ٷ� ������ ����
#define P2DOWN 'j' // Player2�� ��� jŰ�� ������ �ٷ� ������ ����
#define LEFT 75 // Player1�� ����Ű�� ����
#define RIGHT 77
#define UP 72
#define DOWN 80
#define UP2		'w'//player2 �� AWSD �� ����Ű ���
#define DOWN2	's'
#define LEFT2	'a'
#define RIGHT2	'd'
#define ESC 27
#define BX1 5 // �ܺ� ���� �»�� ��ǥ BX, BY
#define BY 1
#define BX2 65 // Plyaer2�� �ܺ� ���� �»�� ��ǥ BX2, BY���� ����

#define BW 10 // �������� ���� ���� BW, BH
#define BH 20 // ������ �� ���� ���̴� ����� ���ǵ� ��ġ����, ���� ����Ʈ�ʹ� �ٸ���.
// BW�� ���, ��µǴ� ������ 2����Ʈ�� ��µǹǷ� ���� BW�� ���� 2*10 �� �� ���̴�.
// BH�� ���, ��µǴ� ���鿡 ��� ���� ���� 1����Ʈ�� ���� BH�� ���� �״�� 20�� �� ���̴�.
/* BW + 2 = �������� ���� ���� ���� ���� ���� �� */

void clrscr();
void gotoxy(int x, int y);
int wherex();
int wherey();
void setcursortype(CURSOR_TYPE c);
void textcolor(int fg_color, int bg_color);

#define delay(n) Sleep(n)                              // n/1000�ʸ�ŭ �ð� ����
#define randomize() srand((unsigned)time(NULL))         // ���� �߻��� �ʱ�ȭ
#define random(n) (rand() % (n))                        //0~n-1������ ���� �߻�

// ȭ���� ��� �����.
void clrscr()
{
	system("cls");
}

// Ŀ���� x,y��ǥ�� �̵���Ų��.
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// Ŀ���� x ��ǥ�� �����Ѵ�.
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.X;
}

// Ŀ���� y��ǥ�� �����Ѵ�.
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.Y;
}

// Ŀ���� ����ų� �ٽ� ǥ���Ѵ�.
void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void textcolor(int fg_color, int bg_color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

#endif