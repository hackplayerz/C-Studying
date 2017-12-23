/* 2017-11-16 마방진을 보여주는 프로그램 */
#include <stdio.h>

void SquareSolve(int size);			// 마방진의 SIZE를 받아오는 함수
void printSquare(int size);			// 마방진을 출력하는 함수							
void MagicSquareOdd(int size);		// 홀수 마방진
void MagicSquare4x(int size);		// 4배수 마방진
void MagicSquareElseEven(int size);	// 4배수가 아닌 짝수 마방진

int magicSquare[9][9];				// 마방진 배열

main()								// main
{
	int size;

	while (1) {
		printf("마방진 사이즈를 입력하세요\n(최소 사이즈 3 - 최대 사이즈 20 / 종료는 0)\n입력 >> ");
		scanf("%d", &size);

		if (size == 0) {
			printf("종료합니다.\n");
			return;
		}
		else if (size<3 || size>20) {
			printf("입력 오류! 다시 입력하세요.\n\n");
			continue;
		}
		SquareSolve(size);
	}
}
/* 입력한 값에 따라 마방진 함수로 이동 */

void SquareSolve(int size) {
	printf("마방진 풀이를 시작합니다.\n");
	printf("입력하신 마방진 사이즈는 %d로, ", size);
	switch (size % 4) {
	case 0:
		printf("4배수 마방진으로 풀이합니다.\n\n");
		MagicSquare4x(size);
		break;
	case 1: case 3:
		printf("홀수 마방진으로 풀이합니다.\n\n");
		MagicSquareOdd(size);
		break;
	case 2:
		printf("4배수가 아닌 짝수 마방진으로 풀이합니다.\n\n");
		MagicSquareElseEven(size);
		break;
	}
}
/* 출력을 위한 함수 */
void printSquare(int size)
{
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			printf("%4d", magicSquare[i][j]);
		printf("\n");
	}
	printf("\n\n");
}
/* 홀수 마방진 프로그램 */
void MagicSquareOdd(int size) {
	int i = size / 2;
	int j = size - 1;;
	int oldi, oldj;
	int k, l;


	printf("1이 들어갈 초기점 좌표 : <%2d,%2d > \n", i, j);
	printf("마방진 풀이\n");
	for (l = 0; l<size; l++) {
		for (k = 0; k<size; k++)
			magicSquare[l][k] = 0;
	}

	for (l = 0, k = 0; k<size*size; l++) {
		oldi = i;
		oldj = j;
		magicSquare[i--][j++] = ++k;
		if (i<0) i = size - 1;
		if (j>size-1)j=0;                   
		if (magicSquare[i][j]!=0) {
			i = oldi;
			j = oldj - 1;
		}
	}
	printSquare(size);
}
/* 4배수 마방진 프로그램 */
void MagicSquare4x(int size) {
	int i, j, k, temp = 0;
	printf("1단계 : 순서대로 숫자 배열\n");
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			magicSquare[i][j] = i*size + j + 1;
			printf("%4d", magicSquare[i][j]);
		}
		printf("\n");
	}
	printf("\n2단계 : 마방진 풀이\n");
	for (j = 0; j<size / 4; j++) {
		for (i = size / 4; i <3 * size / 4; i++) {
			//세로부분 대칭
			temp = magicSquare[i][j];
			magicSquare[i][j] = magicSquare[size - i - 1][size - j - 1];
			magicSquare[size - i - 1][size - j - 1] = temp;
			//가로부분 대칭
			temp = magicSquare[j][i];
			magicSquare[j][i] = magicSquare[size - j - 1][size - i - 1];
			magicSquare[size - j - 1][size - i - 1] = temp;

		}
	}
	printSquare(size);
	printf("\n\n");
}
/* 4의 배수가 아닌 짝수 마방진 프로그램 */
void MagicSquareElseEven(int size) {
	int i, j;
	int temp[20][20] = { 0, }; // 구역을 정의할 배열
	printf("1단계 : size/2 크기의 홀수 마방진 생성\n");
	MagicSquareOdd(size / 2); // 홀수 마방진 생성
	printSquare(size / 2);
	printf("\n");

	printf("1구역 값 출력 \n");
		//1 구역
		for (i = 0; i<size / 2; i++) {         //전체 구역의 행을 size/2으로 나눈다.
			for (int j = 0; j<size / 4; j++) {  //전체 구역의 열을 size/4로 나눈다.
				if (i == size / 4)     //가운데 행은 처음 자리에 0을 먼저 채우고,
					temp[i][j + 1] = 3; //그 뒤에 (size/4)개의 3을 채운다.
				else
					temp[i][j] = 3; //floor(size/4)개의 3을 왼쪽에서부터 
			}                                  // 채운다.
		}
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			printf("%4d", temp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("2구역 값 출력\n");
		//2 구역
		for (i = 0; i<size / 2; i++) {
			for (int j = 0; j<size / 2; j++) {
				if (j<((int)(size / 2 - 1)))
					temp[i][size / 2 + j] = 2;  //ceil(size/2-1) 개의 
												//2를 왼쪽에서부터 채운다.
				else
					temp[i][size / 2 + j] = 1;  //나머지 자리는 모두 1로 
			}                                               // 채운다.
		}
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			printf("%4d", temp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("3, 4구역 값 출력\n");
	//3,4 구역
	for (i = 0; i<size / 2; i++) {
		for (j = 0; j<size / 2; j++) {
			if (temp[i][j] == 0)       //1구역 값과 반대로 채운다.
				temp[size / 2 + i][j] = 3; // (3 대신 0으로, 0 대신 3으로)
			else
				temp[size / 2 + i][j] = 0;
		}
		for (j = 0; j<size / 2; j++) {
			if (temp[i][size / 2 + j] == 2)//2구역 값과 반대로 채운다.
				temp[size / 2 + i][size / 2 + j] = 1;
			else                                    //(2 대신 1로, 1 대신 2로)
				temp[size / 2 + i][size / 2 + j] = 2;
		}
	}
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			printf("%4d", temp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//행렬에 스칼라(size*size/4) 곱
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			temp[i][j] *= size*size / 4;
		}
	}
	printf("2단계 1-4구역 값에 size*size/4 를 곱한 값 출력\n");
	//1-4구역에 size*size/4 를 곱한 값  출력
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			printf("%4d", temp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//각 구역값에 생성한 홀수 마방진 더함
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			temp[i][j] += magicSquare[i % (size / 2)][j % (size / 2)];
		}
	}
	//원래 배열에 결과 옮김
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			magicSquare[i][j] = temp[i][j];
		}
	}
	//마방진 출력
	printf("마방진 출력\n");
	printSquare(size);
}
