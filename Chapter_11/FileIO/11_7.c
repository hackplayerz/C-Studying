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

	printf("testin 파일로부터 20문자만 fread()하여 fwrite()수행 후 \n");
	printf("새로 생성된 testout파일을 확인하세요\n\n");
	length = 20;
	fread(string, sizeof(char), length, infile);
											// Read File 20 charaters
	fwrite(string, sizeof(char), length, outfile);
											// Write File 20 Charaters
		

	printf("testin파일의 맨 앞의 13번째 위치로부터 20문자만 fread()하여 fwrite() 수행후\n");
	printf("새로 생성된 testfseek 파일을 확인하세요\n\n");
	 
	fseek(infile, 13L, SEEK_SET);
											// Set First to 13th location File couser 
	fread(string, sizeof(char), length, infile);
	fwrite(string, sizeof(char), length, fseekfile);
											// Read and Write File 
	f_location = ftell(infile);
											// Input couser's location
	printf("infile의 현재 커서(파일 포인터 위치)는 %d번째 위치이다\n\n", f_location);
											// print File Couser location
	if (feof(infile) == 1) {				// If FIle is End
		printf("End of testin file \n");
	}
	else {
		rewind(infile);
											// Flash File's Couser

		f_location = ftell(infile);
		printf("rewind이후 infile파일의 커서(파일포인터 위치)는 %d번쨰 위치이다\n\n", f_location);
	}
	fclose(infile);
											// Close File

	getch();
	return 0;
}