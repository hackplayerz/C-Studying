#include <stdio.h>											//헤더추가
#include <conio.h>
#define BOOL int											//매크로 정의
#define TRUE 1
#define FALSE 0

BOOL whitesp(char c);										//외부함수선언

void main() {												//main함수 시작
	int ch;													//정수형변수 선언
	int count = 0;											//정수형변수count를 초기화
	
	printf("문자열을 입력후 ctrl+z를 누르세요.\n");			//사용자 메세지 출력
	while ((ch = getchar()) != EOF)							//while반복문 실행
		if (whitesp(ch))count++;							//if문 실행
	printf("There are %d whitespace charater.\n",count);	//사용자 메세지 출력

	getch();
	return 0;
}
BOOL whitesp(char c)										//함수 정의
{
	if (c == ' ' || c == '\n' || c == '\t')					//c='',c=='\n',c=='\t'일때 실행
		return (TRUE);										//TREU값으로 돌려준다
	else
		return (FALSE);										//FALSE값으로 돌려준다
}