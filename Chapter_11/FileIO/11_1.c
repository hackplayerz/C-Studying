/*2017-09-13저수준 파일I/O*/
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
#pragma disable(warning:4996)

void main()
{
	int fd;
	char buf[SIZE + 1];  /*한글은 두바이트로 취급함*/


	fd = open("c:/CJY(VC)/학생1.txt", O_RDONLY);
	printf("Open - fd의값은 == = %d\n\n", fd);
		if (fd<0) {
			printf("(학생.txt) 없음: open error !");
			exit(1);
		}
	while (1) {
		if (read(fd, buf, SIZE) == 0) { break; }
		buf[SIZE] = '\0';
		printf("%s\n", buf);
	}
	close(fd);
	printf("\nClose-fd의 값 ===  %d\n\n", fd);
}
