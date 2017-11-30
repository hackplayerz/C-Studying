/* 2017-11-30 2차원 문자 배열을 통한 문자열 저장 */
#include <stdio.h>

void main() {
	int i, j;
	char game_list[4][15] = { "StarCraft","WarCraft","Call of Duty","FIFA" };

	for (i = 0; i < 4; i++) {
		printf("Game List[%d] : %s\n", i, game_list[i]);
	}
	printf("================================\n");
	for (i = 0; i < 4; i++) {
		printf("game_list[%d][0] : %c\n", i, game_list[i][0]);
	}
	printf("================================\n");
	i = 0;
	do {
		printf("game_list[%d] : ", i);

		for (j = 0; j < 15; j++)
			printf("%3d ", game_list[i][j]);

		printf("\n");
		i++;
	} while (i < 4);

	printf("\n");
}