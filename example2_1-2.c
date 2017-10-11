 #include<stdio.h>			// Standard Input Output Header

void main()					// Start Main Func
{
	int t_high = 0, t_under = 0, r_right = 0, r_left = 0, round = 0;	

		/* 사용자로부터 밑변, 높이, 가로, 세로, 반지름을 받아옴 */
	printf("삼각형의 밑변과 높이를 입력하세요:");
	scanf("%d %d", &t_under, &t_high);
	printf("삼각형의 가로와 세로를 입력하세요:");
	scanf("%d %d", &r_right, &r_left);
	printf("원의 반지름을 입력하세요:");
	scanf("%d", &round);

		/* 계산된 값을 출력 */
	printf("삼각형의 넓이는:%.3f\n", (float)((t_high*t_under) / 2));
	printf("사각형의 넓이는:%.3f\n", (float)(r_right*r_left));
	printf("원의 넓이는:%.3f\n", (float)(round*round*3.141592));
}