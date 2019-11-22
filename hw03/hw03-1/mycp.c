#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define	MAX_BUF	1024

int main(int argc, char *argv[])
{
	//declare two file descriptor and count to read/write
	int 	fd1, fd2, count;
	//declare buf to store which is read at argv[1]
	char	buf[MAX_BUF];

	//argument count error check
	if (argc != 3)  {
		printf("Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	//file open to read and error check
	if ((fd1 = open(argv[1], O_RDONLY)) < 0)  {
		perror("open");
		exit(1);
	}

	//file open to write(copy) and error check
	if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)  {
		perror("open");
		exit(1);
	}

	//read function return positive value when function operate nomally.
	while ((count = read(fd1, buf, MAX_BUF)) > 0)  {
		//The content which is stored in buf is writen to file pointing f2.
		write(fd2, buf, count);
	}

	close(fd1);
	close(fd2);

	return 0;
}
