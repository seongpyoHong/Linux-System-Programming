#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

//two file descriptor vector
static int	Pfd1[2], Pfd2[2];

//create two pipe 
void TELL_WAIT(void){
	if (pipe(Pfd1) < 0 || pipe(Pfd2) < 0)  {
		perror("pipe");
		exit(1);
	}
}

//write from parent write fd to 
void TELL_PARENT(void){
	//write to parent write file descriptor
	if (write(Pfd2[1], "c", 1) != 1)  {
		perror("write");
		exit(1);
	}
}

//read from child
void WAIT_PARENT(void){
	char	c;
	//read from write file descriptor
	if (read(Pfd1[0], &c, 1) != 1)  {
		perror("read");
		exit(1);
	}
	if (c != 'p')  {
		fprintf(stderr, "WAIT_PARENT: incorrect data");
		exit(1);
	}
}

//write from parent write file descriptor
void TELL_CHILD(void) {
	if (write(Pfd1[1], "p", 1) != 1)  {
		perror("write");
		exit(1);
	}
}
//read from pipe 
void WAIT_CHILD(void) {
	char	c;
	//read from pipe to child read file descriptor
	if (read(Pfd2[0], &c, 1) != 1)  {
		perror("read");
		exit(1);
	}
	if (c != 'c')  {
		fprintf(stderr, "WAIT_CHILD: incorrect data");
		exit(1);
	}
}
