/*2017-10-11 실습예제 2 
텍스트 파일을 읽어들여 각 행의 첫머리에 행번호를 덧붙여서 화면으로 출력*/
#include <stdio.h>					//Standard Input Output Header
#include <stdlib.h>					//Standard Library Header 

int main(int argc, char *argv[])	//명령인수 선언
{
	char buffer[74 + 1];
	int line = 1;
	FILE *stream;

	if (argc <= 1)					//명령인수가 없을때
		puts("Usage: list filename"), exit(1);

	stream = fopen(argv[1], "r+");
									//명령인수파일 대입
	if (stream == NULL)
		puts("File not found !"), exit(1);
									//파일이 없을때
	while (!feof(stream)) {
		if (fgets(buffer, 74 + 1, stream) == NULL)
			break;
		printf("%3d: %s", line++, buffer);
	}								//파일내용 출력

	return 0;
}