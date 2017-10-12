#include <stdio.h>			// Standard Input Output Header
#include <time.h>			// Standard Time Library Header
#include <stdlib.h>			// Visual C Standard Library Header
#include <string.h>			// String Header
#define WORDS 6				// 단어수는 6개로 정의

void main()
{				// Main Func 
	char *words[WORDS] = { "한글이든","영문이든","상관은","없어요","인터넷에","나온것들은" };
										// 한글타자에 사용될 문자들의 배열을 포인터로 선언
	char input[32];						// 값을 받아올 문자들의 배열을 선언
	int n, i, used[WORDS] = { 0 };		// 사용된 문자들을 저장하기위한 변수used 선언후 초기화
	int t, cntError = 0, cntChar = 0;	// Error의 횟수와 문자의 갯수를 Count할  변수 선언



	/* seed값을 time(NULL)값으로 set 
	무작위 값을 받아오기 위해 srand()함수안에 time()함수를 사용 매번 다른 값을 받아옴 */

	srand(time(NULL));

	t = clock();						 // 시작된 시간을 clock함수를 사용하여 변수t안에 대입
	for (n = 0; n < WORDS; n++) {		// 6번 Loop

		do {
			i = rand() % WORDS;			 // 0~5 번호선택 난수(무작위)값을 가져올 rand()에 word(6)을 나눈 값을 i에 대입(0 ~ 5)
		} while (used[i]);				 // 이미 사용됐으면 다시
		used[i] = 1;                     // 사용됐음 기호

		while (1) {						 // 무한루프
			printf("%s : ", words[i]);	 
			scanf("%s", input);
			cntChar += strlen(input) / 2;				// 입력글자수, 한글이라 /2
			if (strcmp(input, words[i]) == 0)			// strcmp()함수를 사용해 입력된 문자를 즉시 스캔하여 받아온 문자가 맞았으면 실행
				break;                                  // 루프탈출, 다음단어 처리
			else {										// 잘못된 문자가 입력됬으면
				printf("틀렸습니다. 다시입력하세요\n");
				cntError++;								// Error의 카운트를 1개 증가
			}
		}
	}
	t = clock() - t;									// 위 실행결과의 소요된 시간을 변수t에 대입



	printf("\n");
	printf("틀린 횟수 : %d\n", cntError);
	printf("소요 시간 : %.1f sec\n", t / 1000.0);
	printf("글자수 : %d 자\n", cntChar);
	printf("속도 : %.1f 자/sec\n", cntChar / (t / 1000.0));
}														// End oF Main Func