/*2017-09-13������ ����I/O*/
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
#pragma disable(warning:4996)

void main()
{
	int fd;
	char buf[SIZE + 1];  /*�ѱ��� �ι���Ʈ�� �����*/


	fd = open("c:/CJY(VC)/�л�1.txt", O_RDONLY);
	printf("Open - fd�ǰ��� == = %d\n\n", fd);
		if (fd<0) {
			printf("(�л�.txt) ����: open error !");
			exit(1);
		}
	while (1) {
		if (read(fd, buf, SIZE) == 0) { break; }
		buf[SIZE] = '\0';
		printf("%s\n", buf);
	}
	close(fd);
	printf("\nClose-fd�� �� ===  %d\n\n", fd);
}
