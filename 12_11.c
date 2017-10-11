#include <stdio.h>
#define size 8

void Reverse(int *arr);
void main() {
	int decimal = 254, i = 0;
	int binary[size];
		//10진수 13이 1보다 클 동안
	while (decimal > 1)
	{
		//배열에 2로 나눈 나머지를 차례로 저장
		binary[i++] = decimal % 2;
		//10진수 13은 2로 나누고 다음 루프로
		decimal /= 2;
	}
		//마지막에 남은  1을 배열의 끝에 저장
	binary[i] = 1;

	Reverse(binary);
	for (i = 0; i < size; i++)
		printf("%d", binary[i]);

	printf("\n\n");
}

		//배열을 역순으로 뒤집는 사용자 정의 함수
void Reverse(int *arr)
{
	int temp[size];
	int i;

		//임시 배열 temp에 데이터를 거꾸로 저장
	for (i = 0; i < size; i++)
		temp[i] = arr[size - i - 1];

		//원본 배열에 임시 배열값을 복사
	for (i = 0; i < size; i++)
		arr[i] = temp[i];
}