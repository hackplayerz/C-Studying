#include <stdio.h>			// Standard Input Output Header
#include <time.h>			// Standard Time Library Header
#include <stdlib.h>			// Visual C Standard Library Header
#include <string.h>			// String Header
#define WORDS 6				// �ܾ���� 6���� ����

void main()
{				// Main Func 
	char *words[WORDS] = { "�ѱ��̵�","�����̵�","�����","�����","���ͳݿ�","���°͵���" };
										// �ѱ�Ÿ�ڿ� ���� ���ڵ��� �迭�� �����ͷ� ����
	char input[32];						// ���� �޾ƿ� ���ڵ��� �迭�� ����
	int n, i, used[WORDS] = { 0 };		// ���� ���ڵ��� �����ϱ����� ����used ������ �ʱ�ȭ
	int t, cntError = 0, cntChar = 0;	// Error�� Ƚ���� ������ ������ Count��  ���� ����



	/* seed���� time(NULL)������ set 
	������ ���� �޾ƿ��� ���� srand()�Լ��ȿ� time()�Լ��� ��� �Ź� �ٸ� ���� �޾ƿ� */

	srand(time(NULL));

	t = clock();						 // ���۵� �ð��� clock�Լ��� ����Ͽ� ����t�ȿ� ����
	for (n = 0; n < WORDS; n++) {		// 6�� Loop

		do {
			i = rand() % WORDS;			 // 0~5 ��ȣ���� ����(������)���� ������ rand()�� word(6)�� ���� ���� i�� ����(0 ~ 5)
		} while (used[i]);				 // �̹� �������� �ٽ�
		used[i] = 1;                     // ������ ��ȣ

		while (1) {						 // ���ѷ���
			printf("%s : ", words[i]);	 
			scanf("%s", input);
			cntChar += strlen(input) / 2;				// �Է±��ڼ�, �ѱ��̶� /2
			if (strcmp(input, words[i]) == 0)			// strcmp()�Լ��� ����� �Էµ� ���ڸ� ��� ��ĵ�Ͽ� �޾ƿ� ���ڰ� �¾����� ����
				break;                                  // ����Ż��, �����ܾ� ó��
			else {										// �߸��� ���ڰ� �Է�����
				printf("Ʋ�Ƚ��ϴ�. �ٽ��Է��ϼ���\n");
				cntError++;								// Error�� ī��Ʈ�� 1�� ����
			}
		}
	}
	t = clock() - t;									// �� �������� �ҿ�� �ð��� ����t�� ����



	printf("\n");
	printf("Ʋ�� Ƚ�� : %d\n", cntError);
	printf("�ҿ� �ð� : %.1f sec\n", t / 1000.0);
	printf("���ڼ� : %d ��\n", cntChar);
	printf("�ӵ� : %.1f ��/sec\n", cntChar / (t / 1000.0));
}														// End oF Main Func