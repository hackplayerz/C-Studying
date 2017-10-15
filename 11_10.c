/*2017-10-11 �ǽ����� 2 
�ؽ�Ʈ ������ �о�鿩 �� ���� ù�Ӹ��� ���ȣ�� ���ٿ��� ȭ������ ���*/
#include <stdio.h>					//Standard Input Output Header
#include <stdlib.h>					//Standard Library Header 

int main(int argc, char *argv[])	//����μ� ����
{
	char buffer[74 + 1];
	int line = 1;
	FILE *stream;

	if (argc <= 1)					//����μ��� ������
		puts("Usage: list filename"), exit(1);

	stream = fopen(argv[1], "r+");
									//����μ����� ����
	if (stream == NULL)
		puts("File not found !"), exit(1);
									//������ ������
	while (!feof(stream)) {
		if (fgets(buffer, 74 + 1, stream) == NULL)
			break;
		printf("%3d: %s", line++, buffer);
	}								//���ϳ��� ���

	return 0;
}