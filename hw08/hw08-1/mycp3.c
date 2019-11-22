#include <stdio.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	//file descriptor
	int			fdin, fdout;
	char		*src, *dst;
	struct stat	statbuf;

	//check arguments
	if (argc != 3)  {
		fprintf(stderr, "Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	//open file and return the file descriptor to fdin
	if ((fdin = open(argv[1], O_RDONLY)) < 0)  {
		perror("open");
		exit(1);
	}
	//open file and return file descriptor to fdout
	if ((fdout = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0)  {
		perror("open");
		exit(1);
	}

	//load file's stat
	if (fstat(fdin, &statbuf) < 0)  {
		perror("fstat");
		exit(1);
	}
	//set fdout's offset to fdin's size-1
	if (lseek(fdout, statbuf.st_size-1, SEEK_SET) < 0)  {
		perror("lseek");
		exit(1);
	}
	//write to out
	write(fdout, "", 1);

	//mapping to src & dst file
	if ((src = mmap(0, statbuf.st_size, PROT_READ, MAP_SHARED, fdin, 0)) 
			== (caddr_t) -1)  {
		perror("mmap");
		exit(1);
	}
	if ((dst = mmap(0, statbuf.st_size, PROT_WRITE, MAP_SHARED, fdout, 0)) 
			== (caddr_t) -1)  {
		perror("mmap");
		exit(1);
	}

	//copty to dst from src 
	memcpy(dst, src, statbuf.st_size);

	close(fdin);
	close(fdout);
}
