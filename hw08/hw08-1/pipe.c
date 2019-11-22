#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define	MAX_BUF	128

int main()
{
	int		n, fd[2];	//File descriptor
	pid_t	pid;		//process Id
	char	buf[MAX_BUF];	//Buffer to store string

	//create pipe
	if (pipe(fd)<0)  {
		perror("pipe");
		exit(1);
	}
	//fork child process
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}

	//case when process is child process
	else if (pid == 0)  {
		//child's write file descriptor
		close(fd[1]);
		printf("Child : Wait for parent to send data\n");
		//read from pipe(parent's write file descriptor)
		if ((n=read(fd[0],buf,MAX_BUF))<0)  {
			perror("read");
			exit(1);
		}
		printf("Child : Received data from parent: \n");
		//make stdout empty 
		fflush(stdout);
		//write to stdout from buf
		write(STDOUT_FILENO, buf, n);
	}
	else  {
		//close parent's read file desciptor
		close(fd[0]);
		//string copy to buf
		strcpy(buf, "Hello, World!\n");
		printf("Parent: Send data to child\n");
		//write to buf 
		write(fd[1], buf, strlen(buf)+1);
	}

	exit(0);
}
