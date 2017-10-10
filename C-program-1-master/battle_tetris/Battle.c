#include "Battle.h"

// Player1 ���� �Լ�
BOOL Player1();
void DrawScreen1(); // ȭ�� ��ü�� �׸���. �����ǰ� ���� �̸�, ������ �Ѳ����� �׸���.
void DrawBoard1(); // �����Ǹ� �׸���. �� �ܺκ��� ���ڿ����� ���� �׿� �ִ� ������ �׸���.
void DrawNext1(); // ������ ���� ���� �׸���.
void PrintBrick1(BOOL Show); // ������ ����ϰų� �����ϴµ� �̵����� ������ ������� �ϹǷ�
							 // �������� brick1, rot1, nx1, ny1 ���� �����Ѵ�.
int GetAround1(int x, int y, int b, int r); // ���� �ֺ��� ������ �ִ��� �˻��Ͽ� ������ �̵� �� ȸ�� ���ɼ��� �����Ѵ�.
											// �̵����� ������ �ֺ��� �����ϴ� ���� �ƴϹǷ� �μ��� ���޵� ��ġ�� ���� ����� �����Ѵ�.
BOOL MoveDown1(); // ������ �� ĭ �Ʒ��� �̵���Ų��. ���� �ٴڿ� ��Ҵٸ� TestFull �Լ��� ȣ���� �� TRUE�� �����Ѵ�.
void TestFull1(); // �������� �� ä���� ���� ã�� �����Ѵ�.
void PrintInfo1(); // ������ ���� ������ ����Ѵ�.
void FinishGame1(); // �� �̻� ������ ������ �� ���� ��, ȣ��Ǵ� �Լ���. �� ���ٺ��� ���� ������ ��ϵ� ���� ���ʴ�� ȸ������ �����δ�.

// Player2 ���� �Լ�
BOOL Player2();
void DrawScreen2();
void DrawBoard2();
void DrawNext2();
void PrintBrick2(BOOL Show);
int GetAround2(int x, int y, int b, int r);
BOOL MoveDown2();
void TestFull2();
void PrintInfo2();
void FinishGame2();

// ���� �Լ�
void StartUI(); // ��Ʈ���� ����� ����Ű�� �����ϴ� ����ȭ���� ����Ѵ�.
void Init(); // �������� �� �����迭�� �ʱ�ȭ�ϴ� �Լ�
void InputKey(unsigned char); // ������� Ű �Է��� ó���ϴµ�, 1P�� 2P�� ���ÿ� ó���Ǳ� ���ؼ��� �ϳ��� �Լ��� �����ߴ�.

// ��ǥ�� �����ϴ� Point ����ü Ÿ���� ����
typedef struct Point {
	int x, y;
} Point;

// 4���� ��ǥ�� �� �ϳ��� ����� �����ϰ�, 4���� ��� (ȸ���� �ִ� 4��) �� �𿩾� �ϳ��� ������ ���ǵǸ�
// �̷� ������ 7���� �ִ�. �׷��� ������ ���� 3���� ����ü �迭�� ��ü ������ ����� �����Ѵ�.
// Shape[������ȣ][ȸ����ȣ][�Ϸù�ȣ] ������ �Ϸù�ȣ�� ��� �������� ��ǥ��
// ù ��° ��ǥ (0,0)�� �� ����� �������̸�, ȸ���� ���� �߽����� �ȴ�. ������ �� ��ǥ�� ���������κ��� ����� �Ÿ� ��ǥ�̴�.
Point Shape[][4][4] = {
	{ { { 0,0 },{ 1,0 },{ 2,0 },{ -1,0 } },{ { 0,0 },{ 0,1 },{ 0,-1 },{ 0,-2 } },{ { 0,0 },{ 1,0 },{ 2,0 },{ -1,0 } },{ { 0,0 },{ 0,1 },{ 0,-1 },{ 0,-2 } } }, // ���� �� ���� (������ ������ ��ǥ 2�� �ߺ� -> ��, ��, ��, �� ������ �ߺ�)
	{ { { 0,0 },{ 1,0 },{ 0,1 },{ 1,1 } },{ { 0,0 },{ 1,0 },{ 0,1 },{ 1,1 } },{ { 0,0 },{ 1,0 },{ 0,1 },{ 1,1 } },{ { 0,0 },{ 1,0 },{ 0,1 },{ 1,1 } } }, // ���� �� ���� (������ ������ ��ǥ 4�� ��ε���)
	{ { { 0,0 },{ -1,0 },{ 0,-1 },{ 1,-1 } },{ { 0,0 },{ 0,1 },{ -1,0 },{ -1,-1 } },{ { 0,0 },{ -1,0 },{ 0,-1 },{ 1,-1 } },{ { 0,0 },{ 0,1 },{ -1,0 },{ -1,-1 } } }, // ��(����)�� �� ���� (������ ������ ��ǥ 2�� �ߺ� -> ��(����), �ݽð���� ȸ�� ������ �ߺ�) 
	{ { { 0,0 },{ -1,-1 },{ 0,-1 },{ 1,0 } },{ { 0,0 },{ -1,0 },{ -1,1 },{ 0,-1 } },{ { 0,0 },{ -1,-1 },{ 0,-1 },{ 1,0 } },{ { 0,0 },{ -1,0 },{ -1,1 },{ 0,-1 } } }, // ��(����)�� �� ���� (������ ������ ��ǥ 2�� �ߺ� -> ��(����), �ð���� ȸ�� ������ �ߺ�)
	{ { { 0,0 },{ -1,0 },{ 1,0 },{ -1,-1 } },{ { 0,0 },{ 0,-1 },{ 0,1 },{ -1,1 } },{ { 0,0 },{ -1,0 },{ 1,0 },{ 1,1 } },{ 0,0,0,-1,0,1,1,-1 } }, // ��(����)�� �� ���� (�ݽð���� ȸ�� ������ 4�� ��� ����)
	{ { { 0,0 },{ 1,0 },{ -1,0 },{ 1,-1 } },{ { 0,0 },{ 0,1 } ,{ 0,-1 },{ -1,-1 } },{ 0,0,1,0,-1,0,-1,1 },{ 0,0,0,-1,0,1,1,1 } }, // ��(����)�� �� ���� (�ݽð���� ȸ�� ������ 4�� ��� ����)
	{ { { 0,0 },{ -1,0 },{ 1,0 },{ 0,1 } },{ { 0,0 },{ 0,-1 },{ 0,1 },{ 1,0 } },{ { 0,0 },{ -1,0 },{ 1,0 },{ 0,-1 } },{ { 0,0 },{ -1,0 },{ 0,-1 },{ 0,1 } } }, // ���� �� ���� (�ݽð���� ȸ�� ������ 4�� ��� ����)
};

// puts(arTile[ttype][enum])�� ���� Ȱ��� ���̴�. �� �� �ϳ��� �׷�����.
enum { EMPTY, BRICK, WALL }; // �������� ���¸� ǥ���Ѵ�. �������� �� �� �� �ϳ��� ���¸� ������.
							 // define���� ��ũ�� ����� ���� ���� �� ���� ������, �ߺ����� �ʴ� �Ϸ��� ���̹Ƿ� ���� ����� �����ϴ� ���� �� �ٶ���

							 // Ÿ���� ����� ������ �� �ֵ��� ���� ������ �迭�� �������.
							 // �׸��� ���� ������� Ÿ�� ����� �����ϱ� ���� ttype ���������� �߰��Ѵ�.
int ttype = 0;
char *arTile[][3] = {
	{ "  ","��","��" }, // ���� �����Ǿ��� ���� �� ���
	{ "  ","��","��" }, // �ٴڿ� ����� ���� �� ���
}; // ũ�� 3�� ���ڿ� �迭, �� Ÿ���� 2���� char�� �����ȴ�.
   // "  " ������ ��� 2byte�� �����Ǿ� �ְ� ������ ��µ� ���� ���� �� �ַ� ���ȴ�.
   // ���� ����Ǿ� �ִ� ������ ��������� �� Ÿ�Ͽ� �״�� ���ν��� Ÿ�Ϲ迭�� �ε����� ����� ���̴�.

   /* Player1 ���� ���� ���� �� �迭 */
int board1[BW + 2][BH + 2]; // ��ü �������� ���´�. ������ �󸶸�ŭ �׿� �ִ����� ����Ѵ�.
int color1[BW + 2][BH + 2]; // �÷� ������̴�. board1 �迭�� ��ϵ� ������ ������ ���� �÷��� ������ ��ϵȴ�.
// �̹� �ٴڿ� ������ ������ ������ ����Ѵ�. �̵����� �������� ���� �ڸ��� �������� �ʾ����Ƿ� ��ϵ��� �ʴ´�.
// ���� ȭ�鿡 ǥ�õǴ� ��ǥ�ʹ� ���̰� �ִ�. ó���� �̷��� �������� ���� ��ǥ�� ������ �Ŀ� ����� �ʿ��� ��, ������ ��������� ���ľ� �Ѵ�.

int nx1, ny1; // Player1�� �̵����� ������ ���� ��ǥ�̴�. �迭���� ��ǥ ���̴�.
// �迭���� ��ǥ�� ȭ����� ��ǥ�� �ٲ� ���� BX + nx*2, BY + ny ���� ����ϸ� �ȴ�.
// ���� ���� ���� ����ϸ�, ������ 10x20 ũ���� �������� ���� ���� �����ǥ�� ������ �� �ִ�.
// ����� ���ؼ� ������ ��ǥ�� ������ �ʿ䰡 ���ٴ� ���� ������ �־� �ְ� �����̴�.

// �� ��������
int brick1, rot1; // �̵����� ������ ��ȣ�� ȸ�� ����� ����Ѵ�. brick, rot, nx, ny ���������� �����ϸ�
				  // � ������ � ������� ��� ��ġ�� �ִ����� �˰� �ȴ�.
int nbrick1; // ������ ���� ������ ����� �����ϱ� ���� ��������
int score1; // ������ ����ϴ� ��������, �������������� ���ϴ� arScoreInt �迭�� �����ϴ� �� ���� ���� ���� �ٸ� ������ �����ߴ�.
int bricknum1; // �� ������ ������ �����ϴ� ��������
int flag1; // ���ο� ������ ������� ������ �����ϴ� flag, Player1 �Լ��� ���� �ִ�.
int nFrame1, nStay1; // ������ �ӵ��� �����ϴ� ��������, nFrame1���� �������� nStay1���� ��ī���� (0.05�� ����)�� ���� �ӵ��� �����Ѵ�.

 /* Player2 ���� ���� ���� �� �迭 */
int board2[BW + 2][BH + 2];
int color2[BW + 2][BH + 2];
int nx2, ny2;
int brick2, rot2;
int nbrick2;
int score2;
int bricknum2;
int flag2;
int nFrame2, nStay2;

// ���� �������� (game, finish, virtualNum, offset �� ��� ���� ���������� �ƴ�����, ���� ��ġ�ϴ� ���� ��ü���� ���� �帧���ؿ� ������ �ȴ�.)
int game1, game2; // ������ ��������, �� �������� ������ �Ǻ��ϴ� ��������
int finish1, finish2; // �����÷��̰� ������ �� 0.05�� �������� �������� ����, 0.05�ʴ� �����ڰ� ���������� ������ �ּҴ����� �ð� ���̴�. �� ���� �������� �Ѵ�.
int brickColor[7] = { MAGENTA2, RED2, YELLOW2, GREEN2, BLUE2, CYAN2, GRAY2 }; // �� ������ ������ ������ �����Ѵ�.
int arScoreInc[] = { 0, 1, 3, 8, 10 }; // ���ھ���, ������� �� ���� ���� ������ �ٸ��� �ݿ��ȴ�.
int virtualNum1, virtualNum2; // ������ ���̵� ���� �˰��򿡴� ġ���� ������ �����ߴ�. 0.05�� ���� player �Լ��� 1p, 2p ���� ���� �Ǹ鼭 nStay ����
// nFrame ���� ���� ��ī���� ���ִ� �۾��� �����ϸ鼭 �ӵ������� ����Ǵµ�, ������ bricknum % n (�� ������ �� ���� n���� ����� ��) ���ǹ��� ���߾� nFrame ����
// ���ҽ����ִ� �۾��� �������� ���, 0.05�� ������ �۾��� ����Ǳ⿡ bricknum ���� 0.05�� ������ ������ �ٲ��� �ʴ� �̻� ������ �������� �� ���ϱ޼�������
// nFrame ���� �����ϴ� �������� �߻��߰�, �׷� ���� �ӵ��� ���ڱ� �������� ������ �߻��ߴ�. �� ������ virtualNum ������ offset ������ ������ ���������ν�
// ������ �������� ������ �� �� ���� nFrame�� ���ҽ����ְԲ� �˰����� �����ߴ�.
int offset1, offset2;

void main()
{
	unsigned char ch; // Ư��Ű �Է±��� ó���ؾ��� char ����
	randomize(); // ���� �ʱ�ȭ (srand(time(NULL))�� ����
	StartUI();

	while (1) { // �ٽý����ϰڽ��ϱ�? ���� �޽����� ���� �����԰� ���ÿ� ���Ӻ��带 �ʱ�ȭ �ؾ��ϴ� ���� �۾��� �ʿ��ϱ⿡
				// ������ ���⼭���� �ٽ� �����Ѵ�.
		clrscr();
		Init();
		PlaySound(TEXT("Tetris.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		while (2) { // ���� ��ü�� ���δ� �����̴�.
			if (finish1 == 1 || finish2 == 1) { // finish ���������� �� �� �ϳ����̶� 1�̸� ���� ����
				// ��, ������ ������ �������� �ǹ��ϴ� finish��� ��Ʈ�� ���� �־�� �Ѵ�.
				if (kbhit() == 1) {
					// ������ ������ game�� ���� üũ���ش�. üũ���ִ� ������ Ȥ���� �� �� �ϳ��� �÷��̰� �����ٸ�, ���� ���� ����Ǵ� ���� ������
					// ���α׷��� ȿ������ ���� ��� üũ���ش�.
					ch = getch();
					if (game1 == 1) { // ������ ������ �ʾ��� ��
						Player1();
					}
					else
						FinishGame1(); // ������ ������ ���� ���������� 0.05�� �������� �� ĭ�� GRAY2 �÷�ȭ ��Ű�� �۾��� �����Ѵ�.

					if (game2 == 1) {
						Player2();
					}
					else
						FinishGame2();
					InputKey(ch);
				}
				else { // Ű�� �Է¹��� �ʾ��� ��
					if (game1 == 1)
						Player1();
					else
						FinishGame1();

					if (game2 == 1)
						Player2();
					else
						FinishGame2();
				}
			}
			else {
				break; // finish1�� finish2�� ���� 0�� �� ������ ���� ���´�. ��, �ϳ��� ������ �÷��̰� ����ƴٴ� ���̴�.
				// finish ������������ 0�� �Ǵ� ��, GRAY2 �÷�ȭ�� ������ �����ٴ� ���� �ǹ��Ѵ�.
			}

			delay(1000 / 20); // 1ms = 1/1000 ��, 0.05��
		}
		delay(2000); // 2��
		clrscr();
		gotoxy(35, 10); puts("G A M E  O V E R");
		gotoxy(38, 13);
		if (score1 > score2)
			printf("Player1 WIN\n");
		else if (score1 == score2)
			printf("Draw Game\n");
		else
			printf("Playejr2 WIN\n");
		gotoxy(29, 16); puts("�ٽ� �����Ϸ��� Y�� ��������");
		if (tolower(getch()) != 'y') break;
	}
	PlaySound(NULL, 0, 0);
	setcursortype(NORMALCURSOR);
}

void StartUI()
{
	char buf[128]; // Key Instruction�� �׸� �� ���������� ���� ĳ���� �迭
	char startKey;
	setcursortype(NOCURSOR); // Ŀ���� ������ �ʰ� �����Ѵ�.

							 // BATTLE ���
							 // B ���
	textcolor(MAGENTA2, BLACK);
	gotoxy(5, 2);	printf("���");
	gotoxy(5, 3);	printf("��  ��");
	gotoxy(5, 4);	printf("���");
	gotoxy(5, 5);	printf("��  ��");
	gotoxy(5, 6);	printf("���");
	// A ���
	gotoxy(5 + UIJUMP, 2);	printf("  ��  ");
	gotoxy(5 + UIJUMP, 3);	printf("��  ��");
	gotoxy(5 + UIJUMP, 4);	printf("����");
	gotoxy(5 + UIJUMP, 5);	printf("��  ��");
	gotoxy(5 + UIJUMP, 6);	printf("��  ��");
	// T ���
	gotoxy(5 + UIJUMP * 2, 2);	printf("����");
	gotoxy(5 + UIJUMP * 2, 3);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 2, 4);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 2, 5);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 2, 6);	printf("  ��  ");
	// T ��� 
	gotoxy(5 + UIJUMP * 3, 2);	printf("����");
	gotoxy(5 + UIJUMP * 3, 3);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 3, 4);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 3, 5);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 3, 6);	printf("  ��  ");
	// L ���
	gotoxy(5 + UIJUMP * 4, 2);	printf("��");
	gotoxy(5 + UIJUMP * 4, 3);	printf("��");
	gotoxy(5 + UIJUMP * 4, 4);	printf("��");
	gotoxy(5 + UIJUMP * 4, 5);	printf("��");
	gotoxy(5 + UIJUMP * 4, 6);	printf("����");
	// E ���
	gotoxy(5 + UIJUMP * 5, 2);	printf("����");
	gotoxy(5 + UIJUMP * 5, 3);	printf("��");
	gotoxy(5 + UIJUMP * 5, 4);	printf("����");
	gotoxy(5 + UIJUMP * 5, 5);	printf("��");
	gotoxy(5 + UIJUMP * 5, 6);	printf("����");
	// version ���
	textcolor(WHITE, BLACK);
	gotoxy(5 + UIJUMP * 7, 6);	printf("ver. 1.0");

	// TETRIS ���
	textcolor(GREEN2, BLACK);
	// T ���
	gotoxy(5 + UIJUMP * 2, 8);	printf("�ââ�");
	gotoxy(5 + UIJUMP * 2, 9);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 2, 10);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 2, 11);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 2, 12);	printf("  ��  ");
	// E ���
	gotoxy(5 + UIJUMP * 3, 8);	printf("�ââ�");
	gotoxy(5 + UIJUMP * 3, 9);	printf("��");
	gotoxy(5 + UIJUMP * 3, 10);	printf("�ââ�");
	gotoxy(5 + UIJUMP * 3, 11);	printf("��");
	gotoxy(5 + UIJUMP * 3, 12);	printf("�ââ�");
	// T ���
	gotoxy(5 + UIJUMP * 4, 8);	printf("�ââ�");
	gotoxy(5 + UIJUMP * 4, 9);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 4, 10);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 4, 11);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 4, 12);	printf("  ��  ");
	// R ���
	gotoxy(5 + UIJUMP * 5, 8);	printf("�â�  ");
	gotoxy(5 + UIJUMP * 5, 9);	printf("��  ��");
	gotoxy(5 + UIJUMP * 5, 10);	printf("�â�");
	gotoxy(5 + UIJUMP * 5, 11);	printf("��  ��");
	gotoxy(5 + UIJUMP * 5, 12);	printf("��  ��");
	// I ���
	gotoxy(5 + UIJUMP * 6, 8);	printf("��");
	gotoxy(5 + UIJUMP * 6, 8);	printf("��");
	gotoxy(5 + UIJUMP * 6, 9);	printf("��");
	gotoxy(5 + UIJUMP * 6, 10);	printf("��");
	gotoxy(5 + UIJUMP * 6, 11);	printf("��");
	gotoxy(5 + UIJUMP * 6, 12);	printf("��");
	// S ���
	gotoxy(5 + UIJUMP * 6 + 4, 8);	printf("�ââ�");
	gotoxy(5 + UIJUMP * 6 + 4, 9);	printf("��");
	gotoxy(5 + UIJUMP * 6 + 4, 10);	printf("�ââ�");
	gotoxy(5 + UIJUMP * 6 + 4, 11);	printf("    ��");
	gotoxy(5 + UIJUMP * 6 + 4, 12);	printf("�ââ�");

	// Key Instructions ���
	textcolor(GRAY1, BLACK);
	gotoxy(4, 17);
	strcpy(buf, "������<   Key Instructions   >������");
	printf("%s", buf);
	gotoxy(4, 18);	printf("��");
	gotoxy(6, 18);	printf("PLAYER 1");
	gotoxy(30, 18);	printf("PLAYER 2");
	gotoxy(38, 18);	printf("��");

	gotoxy(4, 19);	printf("��");
	gotoxy(9, 19);	printf("��");
	gotoxy(21, 19); printf("UP");
	gotoxy(33, 19); printf("W");
	gotoxy(38, 19);	printf("��");

	gotoxy(4, 20);	printf("��");
	gotoxy(9, 20);	printf("��");
	gotoxy(20, 20); printf("LEFT");
	gotoxy(33, 20); printf("A");
	gotoxy(38, 20);	printf("��");

	gotoxy(4, 21);	printf("��");
	gotoxy(9, 21);	printf("��");
	gotoxy(19, 21); printf("RIGHT");
	gotoxy(33, 21); printf("D");
	gotoxy(38, 21);	printf("��");

	gotoxy(4, 22);	printf("��");
	gotoxy(9, 22);	printf("��");
	gotoxy(20, 22); printf("DOWN");
	gotoxy(33, 22); printf("S");
	gotoxy(38, 22);	printf("��");

	gotoxy(4, 23);	printf("��");
	gotoxy(8, 23);	printf("sBar");
	gotoxy(18, 23); printf("STRAIGHT");
	gotoxy(33, 23); printf("J");
	gotoxy(38, 23);	printf("��");

	gotoxy(4, 24);
	printf("������������������������������������");

	gotoxy(5 + UIJUMP * 3 + 5, 15);
	textcolor(WHITE, BLACK);

	printf("< Press Enter Key to Start >");
	while (1) {
		startKey = getch();
		if (startKey == ENTER)
			return;
		else
			continue;
	}
}

void Init()
{
	int x, y;
	for (x = 0; x < BW + 2; x++) {
		for (y = 0; y < BH + 2; y++) { // x�� y�� ���� 0�� ��, �������� Ʋ(BW, BH)�� ����� �� WALL�� ����
									   // ��, ���Ӻ��带 ����� ���� ��Ȳ�� WALL ���� �������ش�.
			board1[x][y] = (y == 0 || y == BH + 1 || x == 0 || x == BW + 1) ? WALL : EMPTY;
			board2[x][y] = (y == 0 || y == BH + 1 || x == 0 || x == BW + 1) ? WALL : EMPTY;
			color1[x][y] = WHITE;
			color2[x][y] = WHITE;
		}
	}
	// DrawScreen() �ȿ� ���� ��� ���� �����Ƿ� �ʱ�ȭ �۾��� �������ش�.
	score1 = score2 = 0; // ���� �ʱ�ȭ
	bricknum1 = bricknum2 = 0; // �ʱ� ���� ������ ����̴�. �⺻ ��������� 0���� �������ش�.
	DrawScreen1();		DrawScreen2(); // ���� ȭ�� ��ü�� ����Ѵ�. ������ �����Ǿ� �ִ� �κ��� ������, ���� �κ��� �������� ��µȴ�.
	nStay1 = nFrame1 = 20; // ������ ���� �������ش�. 20���� ��ī���� �ؾ� MoveDown()�� ȣ��ȴ�. �� ī���ô� ����ð��� ������ �������ش�.
	nStay2 = nFrame2 = 20;
	nbrick1 = random(sizeof(Shape) / sizeof(Shape[0])); // �ʱ� �� ����� �����ϰ� ����
	nbrick2 = random(sizeof(Shape) / sizeof(Shape[0]));
	flag1 = flag2 = 0;
	game1 = game2 = 1; // ������ ���۵��� �ǹ��Ѵ�. �� �� ���� 0�� �Ǹ� ������ ������ �ǹ��Ѵ�.
	finish1 = finish2 = 1;
	offset1 = offset2 = 1; // �ӵ� ������ ���� offset���� 1�� �ʱ�ȭ
}

void InputKey(unsigned char ch)
{
	int trot;
	if (ch == SPECIAL1 || ch == SPECIAL2) {
		ch = getch();
		switch (ch) {
		case LEFT:
			if (game1 == 1) {
				if (GetAround1(nx1 - 1, ny1, brick1, rot1) == EMPTY) { // �������� �� ĭ �� ��츦 �̸� ������ �ش� ��ǥ�� ������ �ִ����� �����Ѵ�.
					PrintBrick1(FALSE); // ����� ���� ��� ���� ��ǥ�� �ش��ϴ� ��ǥ ���� ���� �����.
					nx1--; // ���� x��ǥ�� ���� �������� �� ĭ �̵���Ų��.
					PrintBrick1(TRUE); // ���ο� ��ǥ�� ���� ����Ѵ�.
				}
			}
			break;
		case RIGHT:
			if (game1 == 1) {
				if (GetAround1(nx1 + 1, ny1, brick1, rot1) == EMPTY) {
					PrintBrick1(FALSE);
					nx1++;
					PrintBrick1(TRUE);
				}
			}
			break;
		case UP:
			if (game1 == 1) {
				trot = (rot1 == 3 ? 0 : rot1 + 1); // ��ȯ�ϴ� ���� �������ϹǷ� (0~3) 3�� �Ǿ��� ���� �ٽ� 0����, �� �ܿ��� �ϳ��� ���� ������Ų��.
				if (GetAround1(nx1, ny1, brick1, trot) == EMPTY) { // ����� ȸ������ �̸� ������� ����� �������� Ȯ���Ѵ�.
					PrintBrick1(FALSE); // ����� �����ϴٸ�, ���� ��ǥ�� ��µǾ� �ִ� ���� ���鹮�ڷ� ä�� �����ϴ� �۾��� �����Ѵ�.
					rot1 = trot; // ����� �����ϱ� ������, ȸ�� ���¸� ��Ÿ���� �������� rot�� ���� ����� ȸ�����¸� ��Ÿ���� trot�� �����κ��� �����Ѵ�.
					PrintBrick1(TRUE); // ����� rot�� ���� �����Ͽ� �� ��ġ�� ����Ѵ�.
				}
			}
			break;
		case DOWN:
			if (game1 == 1) {
				if (MoveDown1()) { // �� ĭ �Ʒ��� ������ �Լ��� ȣ���� �� �ٷ� TRUE�� �����Ѵ�. (Ű ���� ���ȱ� ������)
					return TRUE;
				}
				break;
			}
		}
	}
	else {
		switch (tolower(ch)) { // ������ �ҹ��ڰ� ��� �־��ٸ� �״�� �ҹ����̰� �빮�ڸ� �ҹ��ڷ� �����ϱ⿡ �ξ� ���õ� ���ǹ��̶� �� �� �ִ�.
		case ' ':
			if (game1 == 1) {
				while (MoveDown1() == FALSE) { ; } // �ٴڿ� ������ MoveDown() �� TRUE�� �����Ѵ�. ����, �ٴڿ� ���� ���� ��� ���ѷ����� MoveDown()�� ȣ���Ѵ�.
				return TRUE; // �ٴڿ� ������� TRUE�� �����Ѵ�. (Ű ���� ���ȴٴ� ���� �ǹ��ϴ� TRUE)
			}
			break;
		case ESC:
			clrscr();
			exit(0);
		case 'p': // ��� ������ �� ���� ȭ���� �����ϰ� ����� getch�� ����Ѵ�.
			clrscr();
			gotoxy(15, 10);
			puts("Tetris ��� ����. �ٽ� �����Ϸ��� �ƹ�Ű�� ��������.");
			getch();
			clrscr(); // Ű�� ���� �ٽ� ���ƿ� ���� �ؽ�Ʈ�� �����
			ttype = 1; // �ٴڿ� ����� ���� �� ����� ���Ѵ�.
			DrawScreen1(); // ��üȭ���� �ٽ� �׸���.
			DrawBoard1();
			DrawNext1();
			PrintBrick1(TRUE); // �̵����� ������ ���� �׷��� �Ѵ�. (������ǥ ����)
			PrintInfo1();
			DrawScreen2();
			DrawBoard2();
			DrawNext2();
			PrintBrick2(TRUE);
			PrintInfo2();
			ttype = 0;
			break;
		case LEFT2:
			if (game2 == 1) {
				if (GetAround2(nx2 - 1, ny2, brick2, rot2) == EMPTY) { // �������� �� ĭ �� ��츦 �̸� ������ �ش� ��ǥ�� ������ �ִ����� �����Ѵ�.
					PrintBrick2(FALSE); // ����� ���� ��� ���� ��ǥ�� �ش��ϴ� ��ǥ ���� ���� �����.
					nx2--; // ���� x��ǥ�� ���� �������� �� ĭ �̵���Ų��.
					PrintBrick2(TRUE); // ���ο� ��ǥ�� ���� ����Ѵ�.
				}
			}
			break;
		case RIGHT2:
			if (game2 == 1) {
				if (GetAround2(nx2 + 1, ny2, brick2, rot2) == EMPTY) {
					PrintBrick2(FALSE);
					nx2++;
					PrintBrick2(TRUE);
				}
			}
			break;
		case UP2:
			if (game2 == 1) {
				trot = (rot2 == 3 ? 0 : rot2 + 1); // ��ȯ�ϴ� ���� �������ϹǷ� (0~3) 3�� �Ǿ��� ���� �ٽ� 0����, �� �ܿ��� �ϳ��� ���� ������Ų��.
				if (GetAround2(nx2, ny2, brick2, trot) == EMPTY) { // ����� ȸ������ �̸� ������� ����� �������� Ȯ���Ѵ�.
					PrintBrick2(FALSE); // ����� �����ϴٸ�, ���� ��ǥ�� ��µǾ� �ִ� ���� ���鹮�ڷ� ä�� �����ϴ� �۾��� �����Ѵ�.
					rot2 = trot; // ����� �����ϱ� ������, ȸ�� ���¸� ��Ÿ���� �������� rot�� ���� ����� ȸ�����¸� ��Ÿ���� trot�� �����κ��� �����Ѵ�.
					PrintBrick2(TRUE); // ����� rot�� ���� �����Ͽ� �� ��ġ�� ����Ѵ�.
				}
			}
			break;
		case DOWN2:
			if (game2 == 1) {
				if (MoveDown2()) { // �� ĭ �Ʒ��� ������ �Լ��� ȣ���� �� �ٷ� TRUE�� �����Ѵ�. (Ű ���� ���ȱ� ������)
					return TRUE;
				}
			}
			break;
		case 'j':
			if (game2 == 1) {
				while (MoveDown2() == FALSE) { ; } // �ٴڿ� ������ MoveDown() �� TRUE�� �����Ѵ�. ����, �ٴڿ� ���� ���� ��� ���ѷ����� MoveDown()�� ȣ���Ѵ�.
				return TRUE; // �ٴڿ� ������� TRUE�� �����Ѵ�. (Ű ���� ���ȴٴ� ���� �ǹ��ϴ� TRUE)
			}
		}
	}
}

BOOL Player1()
{
	int i;
	if (flag1 == 0) {
		bricknum1++; // ���� ������ ������ �� ���� ���� 1�� �÷��ش�.
		PrintInfo1();
		brick1 = nbrick1; // �ʱ⿡ ������ ����� ����, ������ ������ ����� �״�� ���� (�� ��° �������)
		nbrick1 = random(sizeof(Shape) / sizeof(Shape[0])); // ������ ������ ����� �����ϰ� ����

		DrawNext1(); // ������ ������ ����� ȭ�鿡 ���
					 // ���ο� ������ ���� �߾� ��ǥ�� (BW/2, 3) ��ġ�� �����Ѵ�.

		nx1 = BW / 2; // Player1 �ʵ��� �߾Ӻ��� �����ȴ�.
		ny1 = 3; // ���� y��ǥ�� 3���� ����
		rot1 = 0; // ù ���� ���� ȸ���� ���� ���� �����̹Ƿ� rot�� ���� 0�̴�.
		PrintBrick1(TRUE); // TRUE ���� ������ ���� ��µȴ�.
		flag1 = 1; // ���� ���� �������Ƿ� flag1 ���� �ٽ� 1�� �������ش�.
	}
	if (GetAround1(BW / 2, 3, brick1, rot1) != EMPTY) {
		for (i = 0; i < 4; i++) {
			board1[nx1 + Shape[brick1][rot1][i].x][ny1 + Shape[brick1][rot1][i].y] = BRICK;
		}
		game1 = 0;
		return FALSE;
	}
	if (--nStay1 == 0) { // ������ �����ӿ� ���� nStay1 ���� 0.05�� �������� ī���õǰ�, 20�� ������� �� (��, 1�ʰ� ���� ��) MoveDown1() �Լ��� ȣ���Ѵ�.
		nStay1 = nFrame1;// ���� ���� ������ ��Ȯ�� 1�ʿ� �� ĭ�� �������Բ� ������ �Ǿ� �ִ�.
		if (MoveDown1()) {
			return TRUE; // �ð��� ���� ������ �ٴڿ� ������ MoveDown �Լ��� TRUE�� �����Ѵ�.
		}
	}
	// ���� nStay�� ��ī��Ʈ ���ָ鼭 1�ʸ��� ���� ��Ű�� ������, ���� �ð� ���� ��ü�� 1�ʷ� ������ ������,
	// �߰��� �޴� Ű �Է� ���� 1�ʸ��� �Է¹��� ���� �ֱ� ������ ������ �������� �������� �ɰ��� ������ ��ġ�� �ȴ�.
	// ���� Ű �Է��� �� �����Ӹ��� ������ �ֵ��� �ϱ� ���� �Ϻη� �ð��� �����ߴ�.
	if (offset1) {
		if (bricknum1 < 100 && bricknum1 % 10 == 0 && nFrame1 > 5) {
			// ������ 100�� ������ ���� 10���� ������ ������ ������ ���� 1�� ���ҽ��� ������ �������� �ӵ��� ������Ų��.
			// nFrame�� ������ �� �� ������ ������ ���̹Ƿ� �� ���� �����ϸ� �ӵ��� �����Ѵ�. (0.05�� x nFrame ���� �� ĭ �Ʒ��� ������ ���� �ӵ���.)
			// 100�� ������ ���� �ִ� �ӵ��� 0.25�ʿ� �� �� �������� ������ �����Ͽ���.
			// �� �Ŀ� ���� ���(bricknum1) 10�� nFrame1 5�� ���̵��� �����ϴ� �����̴�.
			virtualNum1 = bricknum1 + 1;
			nFrame1--;
			nStay1 = nFrame1; // ��ī���ÿ� �ʿ��� nStay1 ������ �������ش�. �� �������� �Ϻ��� �ð������ ���� �ʴ� �Ѱ谡 �����Ѵ�.
			// ������ nStayī���� ����� ���� ���� �� ���ŵ� ���, ������ ī���� ������ ���󰡱� �����̴�.
			offset1 = 0;
		}
		else if (bricknum1 >= 100 && bricknum1 % 10 == 0 && nFrame1 > 1) { // ������ 100�� �̻��� ���� nFrame�� �ּ� 2���� �� �� �ְԲ� ���̵��� �����ߴ�. (2*0.05 = 0.1��)
			virtualNum1 = bricknum1 + 1; // ������ѹ� virtualNum1�� �����ϴ� ������ ������ �������� �� �ӵ��� �����ϴ� ������ 0.05�� ������ ����Ǵ� �� ���� �����̴�.
			nFrame1--; // �� ������ ���������� �� ���� ������ �Ǿ�� �ϴ� ������ �������ϱ� ������, virtualNum1�� brickNum ���� 1���� ��Ų ������ �ְ�
			nStay1 = nFrame1; // offset1�� 0���� �����ش�. offset��ư�� ������ ���� ������ �� ���� ���� else������ ���� �ȴ�.
			offset1 = 0;
		}
	}
	else { // ������ �ӵ������ϴ� ������ �� �� ����� �� ���� ���ǹ��̴�.
		if (bricknum1 == virtualNum1) { // virtualNum1�� ������ bricknum1 ���� 1 ���� ������ �Ǿ� �ֱ� ������, ���ο� ���� �����ϸ�
			offset1 = 1; // �� �� �ٽ� offset��ư�� ���� ���� ���ǹ��� �ٽñ� �������� �� �ְ� �Ǵ� ������.
		}
	}
	return TRUE;
}

BOOL Player2()
{
	int i;
	if (flag2 == 0) {
		bricknum2++;
		PrintInfo2();
		brick2 = nbrick2;
		nbrick2 = random(sizeof(Shape) / sizeof(Shape[0]));
		DrawNext2();
		nx2 = BW / 2;
		ny2 = 3;
		rot2 = 0;
		PrintBrick2(TRUE);
		flag2 = 1;
	}
	if (GetAround2(BW / 2, 3, brick2, rot2) != EMPTY) {
		for (i = 0; i < 4; i++) {
			board2[nx2 + Shape[brick2][rot2][i].x][ny2 + Shape[brick2][rot2][i].y] = BRICK;
		}
		game2 = 0;
		return FALSE;
	}
	if (--nStay2 == 0) {
		nStay2 = nFrame2;
		if (MoveDown2()) {
			return TRUE;
		}
	}
	if (offset2) {
		if (bricknum2 < 100 && bricknum2 % 10 == 0 && nFrame2 > 5) {
			
			virtualNum2 = bricknum2 + 1;
			nFrame2--;
			nStay2 = nFrame2;
			offset2 = 0;
		}
		else if (bricknum2 >= 100 && bricknum2 % 10 == 0 && nFrame2 > 1) {
			virtualNum2 = bricknum2 + 1;
			nFrame2--;
			nStay2 = nFrame2;
			offset2 = 0;
		}
	}
	else { 
		if (bricknum2 == virtualNum2) { 
			offset2 = 1;
		}
	}
	return TRUE;
}

void DrawScreen1()
{
	int x, y;

	for (x = 0; x < BW + 2; x++) {
		for (y = 0; y < BH + 2; y++) { // �»�� x, y��ǥ�� �ش��ϴ� BX, BY�κ���
									   // x��ǥ�� ��� 2��, y��ǥ�� ��� 1�� ������Ű�鼭 ���带 ����Ѵ�.
			gotoxy(BX1 + x * 2, BY + y);
			// Init()���� ���� �ش��ϴ� �κп��� ���� WALL ���� ���������Ƿ� WALL�� ��µ� ���̴�.
			// ���� ����: x == 0 || y == 0 || x == BW + 1 || y == BH + 1
			puts(arTile[ttype][board1[x][y]]);
		}
	}
}

void DrawScreen2()
{
	int x, y;
	for (x = 0; x < BW + 2; x++) {
		for (y = 0; y < BH + 2; y++) {
			gotoxy(BX2 + x * 2, BY + y);
			puts(arTile[ttype][board2[x][y]]);
		}
	}
}

void DrawBoard1()
{
	int x, y;

	for (x = 1; x < BW + 1; x++) {
		for (y = 1; y < BH + 1; y++) { // �»�ܺ��� �����ϴܱ��� �޿� ��ȸ�ϸ鼭
			gotoxy(BX1 + x * 2, BY + y); // ������ǥ�� ������ǥ�� ��ȯ�� ������ Ŀ���� �̵���Ű��
			textcolor(brickColor[color1[x][y]], BLACK);
			puts(arTile[ttype][board1[x][y]]); // ����迭�� ��ϵ� ������ ���� ����Ѵ�.
		}
	}
	textcolor(WHITE, BLACK);
}

void DrawBoard2()
{
	int x, y;
	for (x = 1; x < BW + 1; x++) {
		for (y = 1; y < BH + 1; y++) {
			gotoxy(BX2 + x * 2, BY + y);
			textcolor(brickColor[color2[x][y]], BLACK);
			puts(arTile[ttype][board2[x][y]]);
		}
	}
	textcolor(WHITE, BLACK);
}

void DrawNext1()
{
	int x, y, i;
	gotoxy(32, 1);
	printf("<PLAYER1>");
	gotoxy(32, 2);
	printf("Next:");
	textcolor(brickColor[nbrick1], BLACK); // ������ ���� ���� �´� �ε��� nbrick1���� �ε����� brickColor�� ����Ǿ� �ִ� ���� �ҷ��´�.
	for (x = 30; x <= 38; x += 2) { // ������ ���� ���� ������ �ٲ�� ������, �ش� �κ� ȭ�鸸 �����ִ� �۾��� �ʿ��ϴ�.
		for (y = 3; y <= 6; y++) {
			gotoxy(x, y);
			puts(arTile[ttype][EMPTY]);
		}
	}
	for (i = 0; i < 4; i++) { // ���� ���� for������ ���������Ƿ� ������ ���� ���� ���Ӱ� ����Ѵ�.
		gotoxy(34 + (Shape[nbrick1][0][i].x) * 2, 5 + Shape[nbrick1][0][i].y);
		puts(arTile[ttype][BRICK]);
	}
	textcolor(WHITE, BLACK); // ���ϴ� ���� ��������� �ٽ� ������ �ʱ�ȭ���ش�.
}

void DrawNext2()
{
	int x, y, i;
	gotoxy(50, 1);
	printf("<PLAYER2>");
	gotoxy(50, 2);
	printf("Next:");
	textcolor(brickColor[nbrick2], BLACK);
	for (x = 50; x <= 58; x += 2) {
		for (y = 3; y <= 6; y++) {
			gotoxy(x, y);
			puts(arTile[ttype][EMPTY]);
		}
	}
	for (i = 0; i < 4; i++) {
		gotoxy(52 + (Shape[nbrick2][0][i].x) * 2, 5 + Shape[nbrick2][0][i].y);
		puts(arTile[ttype][BRICK]);
	}
	textcolor(WHITE, BLACK);
}

// �������� brick, rot�� �����ϴ� ���� ����� ���� ��ġ nx, ny�� ����ϰų� �����.
void PrintBrick1(BOOL Show) // TRUE ���� ������ BRICK�� ����ϰ�, FALSE ���� ������ EMPTY�� ����Ѵ�. (��, ������ ����Ѵ�.)
{
	int i;
	textcolor(brickColor[brick1], BLACK);
	for (i = 0; i < 4; i++) { // ���� ���� ��ǥ������ ����Ͽ� �ϳ��� ����Ͽ� �ϳ��� ������ ���� ����Ѵ�.
		gotoxy(BX1 + (Shape[brick1][rot1][i].x + nx1) * 2, BY + Shape[brick1][rot1][i].y + ny1);
		// ���� ��ǥ�� ���� ������ ������ ������, �� �������� ���� ��ǥ�� �����Ѵ�.
		// ���� ���� ��ǥ�� (0,0), ���� ���� (BW, BH) �� ��ġ C++�� �߻�Ŭ������ ����� ��������
		// ���� ���������� ���� ���� ������ ���־� ȭ�鿡 ����ؾ� �Ѵ�.
		puts(arTile[ttype][Show ? BRICK : EMPTY]); // �� Ȥ�� ������ ����Ѵ�. (2����Ʈ)
	}
	textcolor(WHITE, BLACK);
}

void PrintBrick2(BOOL Show)
{
	int i;
	textcolor(brickColor[brick2], BLACK);
	for (i = 0; i < 4; i++) {
		gotoxy(BX2 + (Shape[brick2][rot2][i].x + nx2) * 2, BY + Shape[brick2][rot2][i].y + ny2);
		puts(arTile[ttype][Show ? BRICK : EMPTY]);
	}
	textcolor(WHITE, BLACK);
}

// �̵����� ������ �ֺ� ������ �����ؾ��ϹǷ�, ���������� �������� �ʰ�, ������ ������ ������ �μ��� ���޹޴´�.
int GetAround1(int x, int y, int b, int r)
{
	int i, k = EMPTY;

	for (i = 0; i < 4; i++) { // ���� EMPTY(0)�� �ʱ�ȭ�� k�� ������ �ִ� ��ǥ�� ��ȸ�ϸ鼭 �ִ밪�� �����ϰ� �ȴ�.
		// EMPTY < BRICK < WALL ������ ���ϰ�, ���� �� ��ġ�� �ƹ��͵� ���ٸ� �״�� EMPTY�� ���ϵ� ���̰�, ������ �浹������ BRICK
		// ���� �浹 �Ǿ��ٸ� WALL �� ���ϵ� ���̴�. �� �Լ��� �����ϴ� �ֺ� ���� ������ �̵����� ����, ������ ��ӿ��� ���� �Ǵ��ϴ� �߿��� ������ �ȴ�.
		k = max(k, board1[x + Shape[b][r][i].x][y + Shape[b][r][i].y]); // max�� stdlib�� ��ũ�η� �����Ǿ� �ִ�.
	}
	return k;
}

int GetAround2(int x, int y, int b, int r)
{
	int i, k = EMPTY;

	for (i = 0; i < 4; i++) {
		k = max(k, board2[x + Shape[b][r][i].x][y + Shape[b][r][i].y]);
	}
	return k;
}

BOOL MoveDown1()
{
	if (GetAround1(nx1, ny1 + 1, brick1, rot1) != EMPTY) { // ȸ������ x���� �״�� ������ ä, y���� �ϳ� �������� �ֺ��� ���̳� ���� �ִ��� Ȯ���Ѵ�.
		ttype = 1; // �ٴڿ� ����� ���� �� ����� ���Ѵ�.
		TestFull1(); // ���� ���̳� ���� �ִٸ�, TestFull() �� ȣ���Ͽ� ä���� �� ���Ÿ� �Ѵ�. (���� ���)
					 // �� ���� �ٷ� ���� Ȥ�� ������ �̵��� �ٸ���.
		flag1 = 0; // ���� ���� �����ϱ� ���� flag���� ����, �̷ν� Player1 �Լ����� ���ο� �� ������ ����������.
		DrawBoard1(); // board �迭�� ���ŵ� ���� �������� �ٽ� �׸���.
		// PlaySound(TEXT("BlockBreak.wav"), NULL, SND_FILENAME | SND_ASYNC);
		ttype = 0; // �� ��� ���󺹱�
		return TRUE; // �ٴڿ� ���� ���, TRUE�� �����Ѵ�. �ֳ��ϸ�, ���� ���� ����ؾ��ϱ� �����̴�.
	}
	PrintBrick1(FALSE); // �Ʒ��� �̵��� ������ ���̳� ���� �����Ƿ�, ������ ��ġ�� ������ �����ش�.
	ny1++; // y���� �ϳ� ������Ų ��, �� ��ǥ�� ���� ����Ͽ� �� ĭ �Ʒ� �̵��� �����Ѵ�.
	PrintBrick1(TRUE);
	return FALSE; // �ٴڿ� ���� ���� �ƴϹǷ� FALSE�� �����Ѵ�.
}

BOOL MoveDown2()
{
	if (GetAround2(nx2, ny2 + 1, brick2, rot2) != EMPTY) {
		ttype = 1; // �ٴڿ� ����� ���� �� ����� ���Ѵ�.
		TestFull2();
		flag2 = 0;
		DrawBoard2(); // board �迭�� ���ŵ� ���� �������� �ٽ� �׸���. ����� �� ������� ����ϱ� ���� (������ ��� ��� ����)
		// PlaySound(TEXT("BlockBreak.wav"), NULL, SND_FILENAME | SND_ASYNC);
		ttype = 0; // �� ��� ���󺹱�
		return TRUE;
	}
	PrintBrick2(FALSE);
	ny2++;
	PrintBrick2(TRUE);
	return FALSE;
}

void TestFull1() // ä���� �� ���Ÿ� �ϴ� �Լ�
{	// �� �Լ��� MoveDown() �Լ����� ȣ��ǰ�, MoveDown()���� �� ĭ �Ʒ� ������ �ƴ϶�� ���� �����Ǹ� ȣ��ȴ�.
	// �� ĭ �Ʒ��� WALL or BRICK �̹Ƿ� ��� ���̵� �ϴ� ���� ��µǾ�� �ϰ� ���� �Ǵ� ������ �� �ڿ� �Ͼ��.
	int i, j, x, y, ty;
	int rNum[3];
	int count = 0;
	for (i = 0; i < 4; i++) { // ���� ��ǥ�� �ش��ϴ� �� ���� ������ �迭�� ����Ѵ�. (����������, �ϴ� �ش� ������ ��ϵǾ� �־�� �˻����ǿ� ������ �� �ֱ� �����̴�.) 
		board1[nx1 + Shape[brick1][rot1][i].x][ny1 + Shape[brick1][rot1][i].y] = BRICK;
		color1[nx1 + Shape[brick1][rot1][i].x][ny1 + Shape[brick1][rot1][i].y] = brick1;
	}
	// �������� ���� ���ٺ��� �˻��Ѵ�.
	for (y = 1; y < BH + 1; y++) { // y���� �����ǰ� x���� �����̹Ƿ�, ��ǥ���� �� ������ �˻��ϴ� for���̴�. ��輱 ������ ��� ������ �˻��Ѵ�.
		for (x = 1; x < BW + 1; x++) {
			if (board1[x][y] != BRICK) break; // �ϳ��� ��� �ִ� ĭ�� �ִٸ�, �� �������� �� �� �����Ƿ� for���� ������.
		}
		// �ϳ��� ������ ä���� �ִٴ� ���� �������� ��
		if (x == BW + 1) { // �ش� �ٿ� �ش��ϴ� y���� 1���� ���������� �����ϴ� ������ ���� ��������� �������� ���縦 ����� ������ ���� �� ���� ���̺��� ������ �� �ֱ� �����̴�.
			count++; // ���ִ� �� ������ count�� �ϳ��� ������Ų��.
			for (ty = y; ty > 1; ty--) { // ���� y������ 1���� ���������� �����ϸ鼭
				for (x = 1; x < BW + 1; x++) { // �ش� y���� ��� x�� ��ȸ�ϸ鼭
					board1[x][ty] = board1[x][ty - 1]; // ��ϵǾ� �ִ� ���� �� ĭ �Ʒ��� �ű��.
					color1[x][ty] = color1[x][ty - 1];
				}
			}
			DrawBoard1(); // board �迭�� ���ŵ� ���� �������� �ٽ� �׸���.
		}
		score1 += arScoreInc[count]; // ������̺��� ���� �� ���� ÷�ڷ� �Ͽ� ������ ���Ѵ�.
									 // PrintInfo(); // ��������� �����Ƿ� ���� �߿� ����ڰ� �� ������ �� �� �ֵ��� �ؾ� �Ѵ�.
	}
	if (count >= 3 && game2 == 1) { // ���� ���� 3�� �̻��� ��, ���濡�� ������ ���Ѵ�.
		for (i = 0; i < count; i++) { // �� ĭ ���� �ű�� �۾��� count ����ŭ ���ش�.
			for (y = 1; y < BH + 1; y++) { // �ش� �ٿ� �ش��ϴ� y���� 1���� ���������� �����ϴ� ������ �Ʒ��� ��������� �������� ���縦 ������ϱ� �����̴�.
				for (x = 1; x < BW + 1; x++) { // �ش� y���� ��� x�� ��ȸ�ϸ鼭
					board2[x][y - 1] = board2[x][y]; // ��ϵǾ� �ִ� ���� �� ĭ ���� �ű��.
					color2[x][y - 1] = color2[x][y];
					board2[x][y] = EMPTY;
				}
			}
		}
		for (i = 0; i < 3; i++) { // �������� ��ĭ�� �ո� x��ǥ�� 3���� �迭�� �������ش�.
			rNum[i] = random(BW) + 1;
			for (j = 0; j < i; j++) {
				if (rNum[j] == rNum[i]) {
					i--;
					break;
				}
			}
		}
		for (y = BH; y >= BH - count + 1; y--) {
			for (x = 1; x < BW + 1; x++) {
				for (i = 0; i < 3; i++) {
					if (rNum[i] == x) {  // ��ĭ�� �մµ� ���� �迭 ���뿡 flag�� ǥ�����ش�. ǥ�ø� ������ ������ �Ȱ��� ���� ������ �ո��Եȴ�.
						rNum[i] = 0;
						board2[x][y] = EMPTY;
						break;
					}
					else {
						board2[x][y] = BRICK;
						color2[x][y] = brickColor[6]; // ������ ��� �߸��� ���� �𸣰�����, BLUE2�� ��µȴ�.
						break;
					}
				}
			}
			for (i = 0; i < 3; i++) { // ��ĭ�� �������� 3���� �ո� �ٸ� ��������� ������. (����)
				rNum[i] = random(BW) + 1;
				for (j = 0; j < i; j++) { // flag�� ǥ���ߴ� �迭�� ���� �����Ͽ� ��ü�� �������ش�.
					if (rNum[j] == rNum[i]) { 
						i--;
						break;
					}
				}
			}
		}
		DrawBoard2();
	}
}

void TestFull2()
{
	int i, j, x, y, ty;
	int rNum[3];
	int count = 0;
	for (i = 0; i < 4; i++) {
		board2[nx2 + Shape[brick2][rot2][i].x][ny2 + Shape[brick2][rot2][i].y] = BRICK;
		color2[nx2 + Shape[brick2][rot2][i].x][ny2 + Shape[brick2][rot2][i].y] = brick2;
	}
	// �������� ���� ���ٺ��� �˻��Ѵ�.
	for (y = 1; y < BH + 1; y++) { // y���� �����ǰ� x���� �����̹Ƿ�, ��ǥ���� �� ������ �˻��ϴ� for���̴�. ��輱 ������ ��� ������ �˻��Ѵ�.
		for (x = 1; x < BW + 1; x++) {
			if (board2[x][y] != BRICK) break; // �ϳ��� ��� �ִ� ĭ�� �ִٸ�, �� �������� �� �� �����Ƿ� for���� ������.
		}
		// �ϳ��� ������ ä���� �ִٴ� ���� �������� ��
		if (x == BW + 1) { // �ش� �ٿ� �ش��ϴ� y���� 1���� ���������� �����ϴ� ������ ���� ��������� �������� ���縦 ����� ������ ���� �� ���� ���̺��� ������ �� �ֱ� �����̴�.
			count++; // ���ִ� �� ������ count�� �ϳ��� ������Ų��.
			for (ty = y; ty > 1; ty--) { // ���� y������ 1���� ���������� �����ϸ鼭
				for (x = 1; x < BW + 1; x++) { // �ش� y���� ��� x�� ��ȸ�ϸ鼭
					board2[x][ty] = board2[x][ty - 1]; // ��ϵǾ� �ִ� ���� �� ĭ �Ʒ��� �ű��.
					color2[x][ty] = color2[x][ty - 1];
				}
			}
			DrawBoard2(); // board �迭�� ���ŵ� ���� �������� �ٽ� �׸���.
		}
		score2 += arScoreInc[count]; // ������̺��� ���� �� ���� ÷�ڷ� �Ͽ� ������ ���Ѵ�.
									 // PrintInfo(); // ��������� �����Ƿ� ���� �߿� ����ڰ� �� ������ �� �� �ֵ��� �ؾ� �Ѵ�.
	}

	if (count >= 3 && game1 == 1) {
		for (i = 0; i < count; i++) { // �� ĭ ���� �ű�� �۾��� count ����ŭ ���ش�.
			for (y = 1; y < BH + 1; y++) { // �ش� �ٿ� �ش��ϴ� y���� 1���� ���������� �����ϴ� ������ �Ʒ��� ��������� �������� ���縦 ������ϱ� �����̴�.
				for (x = 1; x < BW + 1; x++) { // �ش� y���� ��� x�� ��ȸ�ϸ鼭
					board1[x][y - 1] = board1[x][y]; // ��ϵǾ� �ִ� ���� �� ĭ ���� �ű��.
					color1[x][y - 1] = color1[x][y];
					board1[x][y] = EMPTY;
				}
			}
		}
		for (i = 0; i < 3; i++) { // �������� ��ĭ�� �ո� x��ǥ�� 3���� �迭�� �������ش�.
			rNum[i] = random(BW) + 1;
			for (j = 0; j < i; j++) {
				if (rNum[j] == rNum[i]) {
					i--;
					break;
				}
			}
		}
		for (y = BH; y >= BH - count + 1; y--) {
			for (x = 1; x < BW + 1; x++) {
				for (i = 0; i < 3; i++) {
					if (rNum[i] == x) {
						rNum[i] = 0; // ��ĭ�� �մµ� ���� �迭 ���뿡 flag�� ǥ�����ش�. ǥ�ø� ������ ������ �Ȱ��� ���� ������ �ո��Եȴ�.
						board1[x][y] = EMPTY;
						break;
					}
					else {
						board1[x][y] = BRICK;
						color1[x][y] = brickColor[6];
						break;
					}
				}
			}
			for (i = 0; i < 3; i++) { // flag�� ǥ���ߴ� �迭�� ���� �����Ͽ� ��ü�� �������ش�.
				rNum[i] = random(BW) + 1;
				for (j = 0; j < i; j++) {
					if (rNum[j] == rNum[i]) {
						i--;
						break;
					}
				}
			}
		}
		DrawBoard1();
	}
}

void FinishGame1() {
	int x, y;
	int set1 = 0;
	ttype = 1; // ������ ���� ���� �� ����� ���Ѵ�.
	for (y = 0; y < BH + 3; y++) {
		for (x = 0; x < BW + 3; x++) {
			if (board1[x][y] == BRICK) {
				gotoxy(BX1 + x * 2, BY + y); // ������ǥ�� ������ǥ�� ��ȯ�� ������ Ŀ���� �̵���Ű��
				textcolor(GRAY2, BLACK);
				puts(arTile[ttype][BRICK]);
				board1[x][y] = EMPTY;
				set1 = 1;
				break;
			}
			if (x == BW + 2 && y == BH + 2) {
				finish1 = 0;
			}
		}
		if (set1 == 1)
			break;
	}
	textcolor(WHITE, BLACK);
	ttype = 0; // ������ ���� ���� �� ����� ���Ѵ�.
}

void FinishGame2() {
	int x, y;
	int set2 = 0;
	ttype = 1; // ������ ���� ���� �� ����� ���Ѵ�.
	for (y = 0; y < BH + 3; y++) {
		for (x = 0; x < BW + 3; x++) {
			if (board2[x][y] == BRICK) {
				gotoxy(BX2 + x * 2, BY + y); // ������ǥ�� ������ǥ�� ��ȯ�� ������ Ŀ���� �̵���Ű��
				textcolor(GRAY2, BLACK);
				puts(arTile[ttype][BRICK]);
				board2[x][y] = EMPTY;
				set2 = 1;
				break;
			}
			if (x == BW + 2 && y == BH + 2) {
				finish2 = 0;
			}
		}
		if (set2 == 1)
			break;
	}
	textcolor(WHITE, BLACK);
	ttype = 0;
}

void PrintInfo1()
{
	gotoxy(34, 9); printf("���� : %d ", score1);
	gotoxy(34, 10); printf("���� : %d �� ", bricknum1);
}

void PrintInfo2()
{
	gotoxy(50, 9); printf("���� : %d ", score2);
	gotoxy(50, 10); printf("���� : %d �� ", bricknum2);
}