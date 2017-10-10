/* 2017-09-20 File Read, Write fseek ftell rewind feof*/
#include "myheader.h"

int main(void) {
	FILE *infile, *outfile, *fseekfile;		// include File poiner

	char string[500];
	long length;
	long f_location;

	infile = fopen("D://CJY(VC)/testin.txt", "r");
	outfile = fopen("D://CJY(VC)/testout.txt", "w");
	fseekfile = fopen("D://CJY(VC)/testfseek.txt", "w");
											// Opne File

	printf("testin ���Ϸκ��� 20���ڸ� fread()�Ͽ� fwrite()���� �� \n");
	printf("���� ������ testout������ Ȯ���ϼ���\n\n");
	length = 20;
	fread(string, sizeof(char), length, infile);
											// Read File 20 charaters
	fwrite(string, sizeof(char), length, outfile);
											// Write File 20 Charaters
		

	printf("testin������ �� ���� 13��° ��ġ�κ��� 20���ڸ� fread()�Ͽ� fwrite() ������\n");
	printf("���� ������ testfseek ������ Ȯ���ϼ���\n\n");
	 
	fseek(infile, 13L, SEEK_SET);
											// Set First to 13th location File couser 
	fread(string, sizeof(char), length, infile);
	fwrite(string, sizeof(char), length, fseekfile);
											// Read and Write File 
	f_location = ftell(infile);
											// Input couser's location
	printf("infile�� ���� Ŀ��(���� ������ ��ġ)�� %d��° ��ġ�̴�\n\n", f_location);
											// print File Couser location
	if (feof(infile) == 1) {				// If FIle is End
		printf("End of testin file \n");
	}
	else {
		rewind(infile);
											// Flash File's Couser

		f_location = ftell(infile);
		printf("rewind���� infile������ Ŀ��(���������� ��ġ)�� %d���� ��ġ�̴�\n\n", f_location);
	}
	fclose(infile);
											// Close File

	getch();
	return 0;
}